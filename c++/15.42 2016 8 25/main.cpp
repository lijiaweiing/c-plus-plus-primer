#include<iostream>
#include"Query.h"
#include<vector>
#include<map>
string prus_string(int p,const string &i,const string &l)
{
        if(p > 1)
                return i + l;
        else
                return i;
}


std::ostream &print(std::ostream &os,const QueryResult & cases)
{

        os << cases.sought <<" occurs " << cases.lines->size() << prus_string(cases.lines->size(),"time","s") <<std::endl;
        for(auto num : *cases.lines)
        {
               os << "\t(line"  << num +1<<")" <<*(cases.file->begin() + num) <<std::endl;
        }


        return os;

}
std::ostream &print(std::ostream &os,const QueryResult &cases,std::size_t n,std::size_t m)
{
        cases.changes(n,m);
        os << cases.sought <<" occurs " << cases.lines->size() << prus_string(cases.lines->size(),"time","s") <<std::endl;
        for(auto num : *cases.lines)
        {
               os << "\t(line"  << num +1<<")" <<*(cases.file->begin() + num) <<std::endl;
        }


        return os;

}
void runQueries(std::ifstream &infile)
{
        TextQuery tq(infile);
        while(true){
                std::cout <<"enter word to look for, or q to quit: ";
                string s;
                if(!(std::cin >> s)|| s == "q")break;
                print(std::cout,tq.query(s) ) <<std::endl;
        }
}

int main()
{
        std::ifstream infile("one.txt");
        TextQuery op(infile);
        Query q = Query("Alice") | Query("hair");
        print(std::cout , q.eval(op),1,2);
        Queryhistory history;
        history.add_query(q);
        print(std::cout,history[0].eval(op));


}
