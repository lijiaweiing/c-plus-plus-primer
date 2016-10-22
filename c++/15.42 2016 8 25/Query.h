#ifndef QUERY_H_INCLUDED
#define QUERY_H_INCLUDED
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<memory>
#include<algorithm>
#include<iterator>

using std::shared_ptr;
using std::shared_ptr;
using std::vector;
using std::map;
using std::string;
using std::set;
class QueryResult;
class TextQuery
{
        friend class QueryResult;
public:
        TextQuery(std::ifstream &);

        QueryResult query(const string &)const;
        using line_no = std::vector<string>::size_type;
private:
        shared_ptr<std::vector<string>> file; //输入文件
        map<string,shared_ptr<set<line_no>>> wm;//每个单词到他所在的行号的集合映射
};
TextQuery::TextQuery(std::ifstream &is):file(new vector<string>)
{
        string words;

        while(getline(is,words))//a) 改为std::getline(is,words,'.')
        {
                // a) 改为 std::replace(words.begin(),words.end(),'\n','\0');
                file->push_back(words);
                string eva;
                std::size_t op = file->size() - 1; //当前行号
               std::istringstream infile(words);//将文本分解为单词
               while(infile >> eva)//对行中每一个单词
               {

                       auto &i = wm[eva];
                       if(!i)
                        {
                                i.reset(new set<line_no>);
                        }
                        i->insert(op);
               }
        }
}

class QueryResult
{friend std::ostream &print(std::ostream &os,const QueryResult & cases);
friend std::ostream &print(std::ostream &os,const QueryResult &cases,std::size_t n,std::size_t m);
public:
        // c 规定行的范围
        void changes(std::size_t n,std::size_t m)const
        {
                --n;
                --m;
          for(auto i = lines->begin();i != lines->end();++i)
          {
                if(*i < n || *i >m)
                        lines->erase(i);
          }
        }
        set<TextQuery::line_no>::iterator begin(){return lines->begin();}
        set<TextQuery::line_no>::iterator end() {return lines->end();}
        shared_ptr<vector<string>> get_file(){return file;}
        QueryResult(string s,shared_ptr<set<TextQuery::line_no>> l ,shared_ptr<vector<string>> o):sought(s),lines(l),file(o){}
private:
        string sought;//查询单词
        shared_ptr<set<TextQuery::line_no>> lines;//出现的行号
        shared_ptr<vector<string>> file;//输出文件

};
QueryResult TextQuery::query(const string &sou)const
{
        static shared_ptr<set<line_no>> nolo(new set<line_no>);
        auto i = wm.find(sou);
        if(i == wm.end())
                return QueryResult(sou,nolo,file);
        else
                return QueryResult(sou,i->second,file);

}

class Query_Base
{
        friend class Query;
protected:
        using line_no = TextQuery::line_no;
        virtual ~Query_Base() = default;
private:
        virtual QueryResult eval(const TextQuery&)const = 0;
        virtual string rep()const = 0;
};
class Query
{
friend Query operator~(const Query&);
friend Query operator|(const Query&,const Query&);
friend Query operator&(const Query&,const Query&);
public:
        Query(const string&);
        QueryResult eval(const TextQuery &t)const{return q->eval(t);}
        string rep()const{return q->rep();}
private:
        Query(shared_ptr<Query_Base> query):q(query){}
        shared_ptr<Query_Base> q;
};
class WordQuery:public Query_Base
{
        friend class Query;
        WordQuery(const string &s):sought(s){}
        string sought;
        QueryResult eval(const TextQuery &t)const{return t.query(sought);}
        string rep()const {return sought;}
};
inline Query::Query(const string& s):q(new WordQuery(s)){}
class NotQuery:public Query_Base
{
        friend Query operator~(const Query &);
        Query query;
        NotQuery(const Query& se):query(se){}
        QueryResult eval(const TextQuery &t)const;
        string rep()const{return "~(" + query.rep() +")";}

};
inline Query operator~(const Query &we)
{
        return shared_ptr<Query_Base>(new NotQuery(we));
}
class BinaryQuery:public Query_Base
{protected:
        Query lhs;
        Query rhs;
        string words;
        BinaryQuery(const Query &s,const Query &y,string z):lhs(s),rhs(y),words(z){}
        string rep()const {return "(" + lhs.rep() + words + rhs.rep() +" )";}
};
class OrQuery:public BinaryQuery
{
        friend Query operator|(const Query&,const Query&);
        OrQuery(const Query&s,const Query&y):BinaryQuery(s,y,"|"){}
        QueryResult eval(const TextQuery&)const;
};
inline Query operator|(const Query&x,const Query &y)
{
        return shared_ptr<Query_Base>(new OrQuery(x,y));
}
class AndQuery:public BinaryQuery
{
        friend Query operator&(const Query&,const Query&);
        AndQuery(const Query&s,const Query&y):BinaryQuery(s,y,"&"){}
        QueryResult eval(const TextQuery&)const;
};
inline Query operator&(const Query &x,const Query &y)
{
        return shared_ptr<Query_Base>(new AndQuery(x,y));
}
QueryResult OrQuery::eval(const TextQuery& vim)const
{
        auto v1 = lhs.eval(vim);
        auto v2 = rhs.eval(vim);
        shared_ptr<set<line_no>>nolo(new set<line_no>());
        nolo->insert(v1.begin(),v1.end());
        nolo->insert(v2.begin(),v2.end());
        return QueryResult(rep(),nolo,v1.get_file());
}
QueryResult AndQuery::eval(const TextQuery& vim)const
{
        auto v1 = lhs.eval(vim);
        auto v2 = rhs.eval(vim);
        auto ret_ret = std::make_shared<set<line_no>>();
        set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(), std::inserter(*ret_ret,ret_ret->begin()));
        return QueryResult(rep(),ret_ret,v1.get_file());
}
QueryResult NotQuery::eval(const TextQuery &vim)const
{
        auto v1 = query.eval(vim);
        auto result = std::make_shared<set<line_no>>();
        auto beg = v1.begin();
        auto end = v1.end();
        auto sz = v1.get_file()->size();
        for(size_t n = 0;n != sz;++n)
        {
                if(beg == end || *beg != n)
                        result->insert(n);
                else if(beg != end)
                        ++beg;
        }
        return QueryResult(rep(),result,v1.get_file());
}
//b 建立一个历史系统
class Queryhistory
{public:
        Queryhistory() = default;
        void add_query(const Query &m)
        {
                vec.push_back(m);
        }
        Query& operator[](std::size_t i)
        {
                return vec.at(i);
        }
private:
        std::vector<Query> vec;
};

#endif // QUERY_H_INCLUDED
