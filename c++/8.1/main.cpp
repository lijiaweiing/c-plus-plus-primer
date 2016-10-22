/*#include <iostream>
#include<string>
using std::istream;
using std::ostream;
using std::cin;
using std::cout;
istream& get(istream& is)
{
        std::string a;
        while(is>>a)
        {
              std::cout<<a<<std::endl;
        }
        is.clear();
        return is;
}
int main()
{
         get(cin);
        return 0;
}
*/
/*
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;
int main()
{

        string as("one.txt");
        vector<string> cases;
        ifstream in;
        in.open(as);
        if(!in)
        {
                cerr<<"erro : unable to open in file!"<<as;
        }
        string s;
       while(getline(in,s))
                cases.push_back(s);
       in.clear();
       in.close();
       for(auto e:cases)
                cout<<e<<endl;
        return 0;
}
*/
/*
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<cctype>
using namespace std;
int main()
{

        string as("one.txt");
        vector<string> cases;
        ifstream in;
        in.open(as);
        if(!in)
        {
                cerr<<"erro : unable to open in file!"<<as;

        }
        string s;
       while(in>>s)
        {
               cases.push_back(s);
        }
       in.clear();
       in.close();
       for(auto e:cases)
                cout<<e<<endl;
        return 0;
}
*/
/*
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
using namespace std;
struct PersonInfo
{
        string name;
        vector<string> phones;
};
int main()
{
        string line,word;
        vector<PersonInfo>people;
        int i = 0;
        while(getline(cin,line))
        {
                PersonInfo info;
                istringstream record(line);
                record>>info.name;
                while(record>>word)
                        info.phones.push_back(word);
                people.push_back(info);
                i++;
                if(i>4)
                        break;
        }
        for(auto x:people)
        {
                cout<<x.name<<"         ";
                for(auto b:x.phones)
                        cout<<b<<" ";
                cout<<endl;
        }
        return 0;
}
*/
/*
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<fstream>
using namespace std;
int main()
{
       ifstream file("hello.txt");
       std::stringstream lol;
       vector<string> cases;
        if(!file)
       {
               cerr<<"erro : unable to open in file!";
       }
       else
       {
        string lines;
        cout<<"行输出：";
        while(getline(file,lines))
        {
                cases.push_back(lines);
                cout<<lines<<endl;
        }
        cout<<endl;
        for(auto x:cases)
        {
                string lop;
                lol.str(x);
                while(lol>>lop)
                {
                        cout<<lop<<endl;
                }
                lol.clear();
        }
       }
       return 0;
}
*/
#include<iostream>
#include<sstream>
#include<vector>
using std::cin;
using std::cout;
struct PersonInfo
{
        std::string name;
        std::vector<std::string> phones;
};
int main()
{
        std::string line,word;
        std::istringstream record;
        std::vector<PersonInfo> people;
        while(std::getline(cin,line))
        {
                PersonInfo info;
                record.str(line);
                record >> info.name;
                while(record >> word)
                        info.phones.push_back(word);
                people.push_back(info);
        }
        for(const auto &entry : people)
        {
                std::ostringstream formatted,badNums;
                for(const auto &nums : entry.phones)
                {
                        if(!valid(nums))
                        {
                                badNums<<" "<<nums;
                        }else
                        {
                                formatted<<" "<<format
                        }
                }
        }
        return 0;
}
