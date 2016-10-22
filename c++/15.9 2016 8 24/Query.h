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
        shared_ptr<std::vector<string>> file;
        map<string,shared_ptr<set<line_no>>> wm;
};
TextQuery::TextQuery(std::ifstream &is):file(new vector<string>)
{
        string words;

        while(getline(is,words,'.'))
        {
                std::replace(words.begin(),words.end(),'\n','\0');
                file->push_back(words);
                string eva;
                std::size_t op = file->size() - 1;
               std::istringstream infile(words);
               while(infile >> eva)
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
public:
        set<TextQuery::line_no>::iterator begin(){return lines->begin();}
        set<TextQuery::line_no>::iterator end() {return lines->end();}
        shared_ptr<vector<string>> get_file(){return file;}
        QueryResult(string s,shared_ptr<set<TextQuery::line_no>> l ,shared_ptr<vector<string>> o):sought(s),lines(l),file(o){}
private:
        string sought;
        shared_ptr<set<TextQuery::line_no>> lines;
        shared_ptr<vector<string>> file;
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



#endif // QUERY_H_INCLUDED
