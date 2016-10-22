#ifndef TEXT_H_INCLUDED
#define TEXT_H_INCLUDED
#include<fstream>
#include<sstream>
#include<vector>
#include<map>
#include<set>
#include<memory>
#include<algorithm>
#include<iterator>
#include"DebugDelete.h"
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
        ~TextQuery()
        {
                DequgDelete d;
                d(file);
                d(wm.second);
        }
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
        ~QueryResult()
        {
                DequgDelete d;
                d(lines);
                d(file);
        }
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



#endif // TEXT_H_INCLUDED
