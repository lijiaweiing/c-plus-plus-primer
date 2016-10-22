/*#include <iostream>
using namespace std;
bool str_subrang(const string &str1,const string &str2)
{
        if(str1.size() == str2.size())
                return str1 == str2;
        auto size = (str1.size()<str2.size())?str1.size():str2.size();
        for(decltype(size) i = 0;i != size;++i)
        {
                if(str1[i] != str2[i])
                        return ;
        }
}
int main()
{
      const string a1 = "adskdj akjdka";
      const string a2 = "aadnakdad adk";
      cout<<str_subrang(a1,a2);
}
*/
/*
#include<iostream>
using namespace std;
int &get(int arry[],int index){return arry[index];}
int main()
{
        int ia[10];
        for(int i = 0;i != 10;++i)
        {
                get(ia,i) = i;

        }
        for(int s = 0;s<10;s++)
                cout<<ia[s]<<endl;
        return 0;
}
*/
#include<iostream>
#include<vector>
using namespace std;

int main()
{
        int odd[] = {1,3,5,7,9};
        int even[] = {0,2,4,6,8};
        decltype(odd) &arrPtr()
        {
                return (i % 2)?odd : even;
        }



}
