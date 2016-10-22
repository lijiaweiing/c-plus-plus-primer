/*#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<memory>
class TextQuery
{
private:
        std::shared_ptr<std::vector<std::string>> files;
        std::map<std::string,shared_ptr<std::set<std::vector<std::string>::size_type>>> word_line;
public:
        TextQuery(std::ifstream &infile);
        void query(const std::string &value);


};
TextQuery::TextQuery(std::ifstream &infile):files(new std::vector<std::string>)
{
        std::string vol;

        while(std::getline(infile,vol))
        {

                files->push_back(vol);
                int line = files->size() - 1;
                std::istringstream record(vol);
                std::string has;
                while(record >>has)
                {
                      auto &li = word_line[has];

                        li.insert(line);
                }
        }
}
void TextQuery::query(const std::string &value)
{
        for(auto i : word_line)
        {
                if(i.first == value)
                {
                        std::cout <<i.first->second
                        <<*(files->begin() +i.first);
                }
        }
}
void runQueries(std::ifstream &infile)
{
        TextQuery tq(infile);
        while(true)
        {
                std::cout << "enter word to look for,or q to quit:";
                std::string s;
                if(!(std::cin >> s)|| s == 'q')break;
               to.query(s);
        }
}
int main()
{
        std::ifstream in("haha.txt");
        if(!in)
                std::cerr << "can not open file";
        else
                runQueries(in);
}
*/
/*#include<iostream>
#include<sstream>
#include<string>
#include<fstream>
#include<map>
#include<set>
#include<vector>
#include<memory>
class QueryResult;
class TextQuery
{
private:
        std::shared_ptr<std::vector<std::string>> file;
        std::map<std::string,std::shared_ptr<std::set<std::vector<std::string>::size_type>>> wm;
public:
        friend class QueryResult;
        TextQuery(std::ifstream&);
        QueryResult query(std::string& a)const;

};
TextQuery::TextQuery(std::ifstream& infile)
{
        std::string vol;
        while(std::getline(infile,vol))
        {
                file->push_back(vol);
                int n = file->size() - 1;
                std::istringstream record(vol);
                std::string vel;
                while(record >> vel)
                {
                        auto &x = wm[vel];
                        if(!x)
                                x.reset(new std::set<std::vector<std::string>::size_type>);
                        x->insert(n);
                }
        }
}
class QueryResult
{
        friend std::ostream& print(std::ostream&os,const QueryResult pop);
private:
        std::string sought;
        std::shared_ptr<std::set<std::vector<std::string>::size_type>>lines;
        std::shared_ptr<std::vector<std::string>> file;
public:
        QueryResult(std::string s,std::shared_ptr<std::set<std::vector<std::string>::size_type>>f,
        std::shared_ptr<std::vector<std::string>> w):sought(s),lines(f),file(w){}
};
QueryResult TextQuery::query(std::string &a)const
{
        std::shared_ptr<std::set<std::vector<std::string>::size_type>> nom(new std::set<std::vector<std::string>::size_type>);
        auto f = wm.find(a);
        if(f == wm.end())
                return QueryResult(a, nom,file);
        else
                return QueryResult(a,f->second,file);
}
std::ostream& print(std::ostream&os,const QueryResult pop)
{
        os << pop.sought << "occurs" << pop.lines->size() <<" "
        <<std::endl;
        for(auto i :*pop.lines)
        {
                os << "\t(line" <<i + 1 << ")"<< *(pop.file->begin() + i) <<std::endl;
        }
        return os;
}
void runQueries(std::ifstream &infile)
{
        TextQuery tq(infile);
        while(true)
        {
                std::cout << "enter word to look for,or q to quit:";
                std::string s;
                if(!(std::cin >> s)|| s == "q")break;
               print(std::cout,tq.query(s)) <<std::endl;
        }
}
int main()
{
        std::ifstream in("i.txt");
        runQueries(in);
}
*/
#include <sstream>
#include <algorithm>

#include <string>
using std::string;

#include <vector>
using std::vector;

#include <memory>
using std::shared_ptr;

#include <iostream>
#include <fstream>
#include <map>
#include <set>

class QueryResult;
class TextQuery {
public:
    using LineNo = vector<string>::size_type;
    TextQuery(std::ifstream &);
    QueryResult query(const string&) const;
private:
    shared_ptr<vector<string>> input;
    std::map<string, shared_ptr<std::set<LineNo>>> result;
};

class QueryResult {
public:
    friend std::ostream& print(std::ostream &, const QueryResult&);
public:
    QueryResult(const string &s, shared_ptr<std::set<TextQuery::LineNo>> set, shared_ptr<vector<string>> v) : word(s), nos(set), input(v) { }
private:
    string word;
    shared_ptr<std::set<TextQuery::LineNo>> nos;
    shared_ptr<vector<string>> input;
};

std::ostream& print(std::ostream &, const QueryResult&);
TextQuery::TextQuery(std::ifstream &ifs) : input(new vector<string>)
{
    LineNo lineNo{ 0 };
    for (string line; std::getline(ifs, line); ++lineNo) {
        input->push_back(line);
        std::istringstream line_stream(line);
        for (string text, word; line_stream >> text; word.clear()) {
            // avoid read a word followed by punctuation(such as: word, )
            std::remove_copy_if(text.begin(), text.end(), std::back_inserter(word), ispunct);
            // use reference avoid count of shared_ptr add.
            auto &nos = result[word];
            if (!nos) nos.reset(new std::set<LineNo>);
            nos->insert(lineNo);
        }
    }
}

QueryResult TextQuery::query(const string& str) const
{
    // use static just allocate once.
    static shared_ptr<std::set<LineNo>> nodate(new std::set<LineNo>);
    auto found = result.find(str);
    if (found == result.end()) return QueryResult(str, nodate, input);
    else return QueryResult(str, found->second, input);
}

std::ostream& print(std::ostream &out, const QueryResult& qr)
{
    out << qr.word << " occurs " << qr.nos->size() << (qr.nos->size() > 1 ? " times" : " time") << std::endl;
    for (auto i : *qr.nos)
        out << "\t(line " << i+1 << ") " << qr.input->at(i) << std::endl;
    return out;
}
void runQueries(std::ifstream &infile)
{
        TextQuery tq(infile);
        while(true)
        {
                std::cout << "enter word to look for,or q to quit:";
                std::string s;
                if(!(std::cin >> s)|| s == "q")break;
               print(std::cout,tq.query(s)) <<std::endl;
        }
}
int main()
{
        std::ifstream in("i.txt");
        runQueries(in);
}
