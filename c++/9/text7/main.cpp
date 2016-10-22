//6.7
/*#include <iostream>
using namespace std;
size_t count_calls()
{
        static size_t ctr = 0;

        return ctr++;
}
int main()
{
        for(size_t i = 0;i != 10; ++i)
                cout<<count_calls()<<endl;
        return 0;
}*/
//6.2
/*#include<iostream>
using namespace std;
void swop(int *i,int *p)
{
        int w;
        w = *i;
        *i = *p;
        *p = w;

}
int main()
{
        int i = 32,p = 48;
        swop(&i,&p);
        cout<<"i        "<<i<<"        p"<<p;
}*/
//6.2.2
/*#include<iostream>
using namespace std;
void reset(int &i)
{
        i =0;
}
int main()
{
        int j = 42;
        reset(j);
        cout<<"j = "<<j<<endl;
        return 0;
}*/
/*#include<iostream>
using namespace std;
string::size_type find_char(const string &s,char c,string::size_type &occurs)
{
        auto ret = s.size();
        occurs = 0;
        for(decltype(ret) i = 0;i != s.size();++i)
        {
                if(s[i] == c)
                {
                        if(ret == s.size())
                                ret = i;
                        ++occurs;
                }
        }
        return ret;

}
int main()
{
        const string s = "s";
        string::size_type ctr = 0;
        auto index = find_char(s,'o',ctr);
        cout<<index;
        cout<<ctr;
        return 0;
}
*/
/*
#include<iostream>
#include<cctype>
#include<string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
void x1(const string &s)
{
        static int num = 0;
        for(string::size_type i = 0;i < s.size();++i)
        {

                if(isupper(s[i]))
                {
                        cout<<"该字符串中有大写字母"<<endl;
                        num++;
                        break;
                }

        }
        if(num == 0)
                 cout<<"该字符串中没有大写字母"<<endl;
}
void x2(string &s)
{
       for(auto &a:s)
                a = tolower(a);
}
int main()
{
        string as("Ahsdja  asdasd");
        x1(as);
        x2(as);
        cout<<as;
        return 0;
}
*/
/*
#include<iostream>
using namespace std;
void print(int  (&arr)[10])
{
        for(auto elem : arr)
                cout<<elem<<endl;
}
int main()
{
        int k[10] = {0,1,2,3,4,5,6,7,8,9};
        print(k);
        return 0;
}
*/
/*#include<iostream>
using namespace std;
int factorial(int val)
{
        if(val > 1)
                return factorial(val-1)*val;
        return 1;
}
int main()
{
        cout<<factorial(5);
        return 0;
}
*/
/*
#include<iostream>
using namespace std;
bool str_subrang(const string &str1,const string &str2)
{
        if(str1.size() == str2.size())
                return str1 == str2;
        auto size = (str1.size() < str2.size())?str1.size():str2.size();
        for
}
*/
