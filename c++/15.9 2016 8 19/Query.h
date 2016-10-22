#ifndef QUERY_H_INCLUDED
#define QUERY_H_INCLUDED
#include <sstream>
#include <algorithm>

#include <string>
using std::string;
#include<iterator>
#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;

#include <iostream>
#include <fstream>
#include <map>
#include <set>
using std::set;
class QueryResult;
class TextQuery
{
public:
        using line_no = vector<std::string>::size_type;
        TextQuery(std::ifstream&);
        QueryResult query(const std::string&)const;

private:
        std::shared_ptr<vector<string>> file;
        std::map<string ,std::shared_ptr<std::set<line_no>>> wm;
};
TextQuery::TextQuery(std::ifstream &is):file(new vector<std::string>)
{
        string text;
        while(std::getline(is,text))
        {
                file->push_back(text);
                int n = file->size() - 1;
                std::istringstream line(text);
                std::string word;
                while(line >> word)
                {
                        auto &lines = wm[word];
                        if(!lines)
                                lines.reset(new std::set<line_no>);
                        lines->insert(n);
                }
        }
}
class QueryResult
{

        friend std::ostream &print(std::ostream& os,const QueryResult&);
public:
        shared_ptr<std::vector<std::string>> get_file()
        {
                return file;
        }
        std::set<TextQuery::line_no>::iterator begin()const
        {
                return lines->begin();
        }
        set<TextQuery::line_no>::iterator end()const
        {
                return lines->end();
        }
        QueryResult(std::string s,shared_ptr<std::set<TextQuery::line_no>>p,std::shared_ptr<vector<string>>f):sought(s),lines(p),file(f){}
private:
        std::string sought;
        std::shared_ptr<std::set<TextQuery::line_no>> lines;
        std::shared_ptr<vector<std::string>> file;
};
QueryResult TextQuery::query(const string &sought)const
{
        static  shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
        auto loc = wm.find(sought);
        if(loc == wm.end())
                return QueryResult(sought,nodata,file);
        else
                return QueryResult(sought,loc->second,file);
}
std::ostream &print(std::ostream &os,const QueryResult &qr)
{
        os <<qr.sought <<"occurs " <<qr.lines->size() << " "
        << std::endl;
        for(auto num : *qr.lines)
        {
                os << "\t(line" << num + 1 << ")"
                <<*(qr.file->begin() + num) <<std::endl;

        }
        return os;
}
class Query_base
{
        friend class Query;
protected:
        using line_no = TextQuery::line_no;
        virtual ~Query_base() = default;
private:
        virtual QueryResult eval(const TextQuery &)const = 0;
        virtual std::string rep() const  = 0;
};
class Query
{
        friend std::ostream& operator<<(std::ostream &os,const Query &query);
        friend Query operator~(const Query &);
        friend Query operator|(const Query &,const Query &);
        friend Query operator&(const Query& ,const Query &);
public:
        Query(const std::string &);
        QueryResult eval(const TextQuery &t)const
        {
                return q->eval(t);
        }
        std::string rep()const
        {
                return q->rep();
        }
private:
        Query(std::shared_ptr<Query_base>query):q(query){}
        std::shared_ptr<Query_base> q;
};
std::ostream& operator<<(std::ostream &os,const Query &query)
{
        return os << query.rep() ;
}
class WordQuery:public Query_base
{
        friend class Query;
        WordQuery(const std::string &s):query_word(s){}
        std::string query_word;
        QueryResult eval(const TextQuery &t)const
        {
                return t.query(query_word);
        }
        std::string rep() const {return query_word;}
};
inline Query::Query(const std::string &s):q(new WordQuery(s)){}
class NotQuery:public Query_base
{
        friend Query operator~(const Query &);
        NotQuery(const Query &q):query(q){}
        std::string rep()const {return "~(" + query.rep() + ")";}
        QueryResult eval(const TextQuery&)const;
        Query query;
};
inline Query operator~(const Query &operand)
{
        return std::shared_ptr<Query_base>(new NotQuery(operand));
}
class BinaryQuery:public Query_base
{protected:
        Query lhs,rhs;
        std::string opSym;
        std::string rep()const
        {
                return "(" + lhs.rep() + " " + opSym +" " +rhs.rep() + ")";
        }
        BinaryQuery(const Query&l, const Query &r,std::string s):lhs(l) , rhs(r) ,opSym(s){}
};
class AndQuery:public BinaryQuery
{
        friend Query operator&(const Query&,const Query &);
        AndQuery(const Query &left,const Query&right):BinaryQuery(left,right,"&"){}
        QueryResult eval(const TextQuery &)const;
};
inline Query operator&(const Query&lhs,const Query &rhs)
{
        return std::shared_ptr<Query_base>(new AndQuery(lhs,rhs));
}
class OrQuery:public BinaryQuery
{
        friend Query operator|(const Query&,const Query &);
        OrQuery(const Query&left,const Query &right):BinaryQuery(left,right,"|"){}
        QueryResult eval(const TextQuery &)const;
};
inline Query operator|(const Query &lhs,const Query &rhs)
{
        return std::shared_ptr<Query_base>(new OrQuery(lhs,rhs));
}
QueryResult OrQuery::eval(const TextQuery &text)const
{
        auto right = rhs.eval(text);
        auto left = lhs.eval(text);
        auto ret_lines = std::make_shared<std::set<line_no>>(right.begin(),right.end());
        ret_lines->insert(left.begin(),left.end());
        return QueryResult(rep(),ret_lines,left.get_file());
}
QueryResult AndQuery::eval(const TextQuery& text)const
{
        auto left = lhs.eval(text);
        auto right = lhs.eval(text);
        auto ret_lines = std::make_shared<std::set<line_no>>();
        std::set_intersection(left.begin(),left.end(),right.begin(),right.end(),inserter(*ret_lines,ret_lines->begin()));
        return QueryResult(rep(),ret_lines,left.get_file());
}
QueryResult NotQuery::eval(const TextQuery& text)const
{
        auto result = query.eval(text);
        auto ret_lines = std::make_shared<std::set<line_no>>();
        auto beg = result.begin();
        auto end = result.end();
        auto sz = result.get_file()->size();
        for(std::size_t n = 0;n != sz;++n)
        {
                if(beg == end|| *beg != n)
                        ret_lines->insert(n);
                else if(beg != end)
                        ++beg;
        }

        return QueryResult(rep(),ret_lines,result.get_file());
}
#endif // QUERY_H_INCLUDED
