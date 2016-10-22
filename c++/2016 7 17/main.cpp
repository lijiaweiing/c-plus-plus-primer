/*#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::string;
void get(string &s, const string   oldVal,const string newVal)
{
        for(auto curr = s.begin();curr != s.end() - oldVal.size();)
        {

                if(oldVal == string {curr, curr + oldVal.size()})
                {
                        curr = s.erase(curr,curr + oldVal.size());
                        curr = s.insert(curr,newVal.begin(),newVal.end());
                        curr += newVal.size();
                }
                else
                {
                        ++curr;
                }
        }
}
int main()
{
        string item = "I'm tho asjd thru jkl";
        get(item,"tho","though");
        cout<<item;
}
*/
/*#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::string;
void get(string &s, const string   oldVal,const string newVal)
{
        for(size_t curr = 0;curr <= s.size() - oldVal.size();)
        {

                if (s[curr] == oldVal[0] && s.substr(curr, oldVal.size()) == oldVal)

                {
                        s.replace(curr, oldVal.size(),newVal);
                        curr += newVal.size();
                }
                else
                {
                        ++curr;
                }
        }
}
int main()
{
        string item = "I'm tho asjd thru jkl";
        get(item,"tho","though");
        cout<<item;
}
*/
/*#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::string;
string files(string &s,const string& a , const string &b)
{
        s.insert(s.begin(),a.begin(),a.end());

       s.insert(s.end(),b.begin(),b.end());
        return s;
}
int main()
{
        string a("linda");
        cout<<files(a,"Mr","Jr");

}
*/
/*#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::cin;
int main()
{
        string numbers("01234689");
        string name("r2d1");
       string::size_type pos = 0;
       while((pos = name.find_first_of(numbers , pos))!= string::npos)
       {
               cout << "found number at index:" << pos
               << "element is " << name[pos] <<std::endl;
               ++pos;
       }
       return 0;
}
*/
/*#include<iostream>
#include<string>
using std::string;
using std::cin;
using std::cout;
int main()
{
        string number("0123456789");
        string name("ab2c3d7R4E6");
        string::size_type pos = 0 , pis = 0;
        while((pos = name.find_first_of(number,pos)) != string::npos)
        {
                cout<<"Found number at index :" << pos << "element is " <<name[pos]<<std::endl;
                ++pos;
        }
        while( (pis = name.find_first_not_of(number,pis) )!= string::npos)
        {
                cout<<"Found number at index :" << pis << "element is " <<name[pis]<<std::endl;
                ++pis;
        }
        return 0;
}
*/
/*#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::cin;
int main()
{
         string numbers("01234689");
        string name("r2d2");
       string::size_type pos = name.find(numbers);
       cout<<pos;
}
*/
//9.49
/*#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
using std::fstream;
using std::string;
int main()
{
        std::ifstream infile("hi.txt");
        if(!infile)
        {
                std::cerr<<"unable to open this file"<<std::endl;
        }
        string word;
        string lists;
        string number("aceimnorsuvwxz");
        std::vector<string> cases;
        while(infile >> word)
        {
                string::size_type pos = 0;
               int i = 0;
               while((pos = word.find_first_not_of(number , pos)) != string::npos)
               {
                       ++i;
                       ++pos;
               }
               if(i > 0)
               {
                       continue;
               }
               else if(word.size() > lists.size())
               {
                       lists = word;
               }
        }
        std::cout<<lists;

}
*/
/*#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::string;
int main()
{
        string s("teacher");
        string number("dfpq");
        string::size_type pos = 0;
        int i = 0;
        while((pos = s.find_first_of(number , pos)) != string::npos)
        {
                ++i;
                ++pos;
        }
        cout<<i;
}
*/
/*#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::cin;
int main()
{
        string s2 = "pi =3.14";
        double d = std::stod(s2.substr(s2.find_first_of("+-.0123456789")));
        cout<<d;
}
*/
/*#include<iostream>
#include<string>
#include<vector>
int main()
{
        std::vector<std::string> item ;
        for(size_t i = 0; i < 10 ;++i)
        {
                item.push_back(std::to_string(i));
        }
       double sum = 0.0;
        for(auto s : item)
        {
                sum += std::stod(s);
        }
        std::cout<<sum;
}
*/
/*#include<iostream>
#include<string>
class time
{
private:
        unsigned year;
        unsigned month;
        unsigned day;
public:
        time(std::string &a);
};
time::time(std::string &a)
{
        string c("JAFMOSOND");
        auto curr = a.find_first_of(c);

}*/
