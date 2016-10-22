#include<iostream>
#include<cctype>
#include<string>
int main()
{
        std::string str(",ji");
        for(auto i = str.begin();i != str.end();++i)
        {
                if(!isalnum(*i))
                        str.erase(i);
        }
        std::cout<<str;
}
