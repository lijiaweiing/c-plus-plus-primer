#include<iostream>
#include<string>
#include<algorithm>
#include<fstream>
#include<vector>
#include<sstream>
#include"Query.h"
/*int main()
{
        std::ifstream infile("one.txt");
        std::string s;
        std::string file;std::vector<std::string> vec;
        std::string word;

        while(std::getline(infile ,word ,'.'))
        {
        std::replace(word.begin(),word.end(),'\n','\0');

                vec.push_back(word);

        }
        for(auto i : vec)
        {
                std::cout << i <<std::endl;
        }



}
*/
std::string prus_string(int i ,std::string a,std::string b)
{
        if(i > 1)
                return a + b;
        else
                return a;
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
void runQueries(std::ifstream &infile)
{
        TextQuery tq(infile);
        while(true){
                std::cout <<"enter word to look for, or q to quit: ";
                string s;
                if(!(std::cin >> s)|| s == "q")break;
                print(std::cout,tq.query(s)) <<std::endl;
        }
}
int main()
{
        std::ifstream infile("one.txt");
        runQueries(infile);
}
