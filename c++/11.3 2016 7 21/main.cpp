/*#include<iostream>
#include<map>
#include<set>
#include<utility>
#include<string>
#include<algorithm>
int main()
{
        std::map<std::string ,std::size_t> word_count;
        std::string word;
        while(std::cin >> word && word != "@q")
        {
                auto wc = word_count.insert({word,1});
                if(!wc.second)
                        ++(wc.first)->second;
        }
        for(auto i : word_count)
        {
                std::cout << i.first <<"        "<<i.second <<std::endl;
        }
}
*/
//11.22
/*#include<map>
#include<iostream>
#include<algorithm>
#include<string>
#include<utility>
#include<vector>
void seek(std::map<std::string, std::vector<int>> &vec,const std::string s,const std::vector<int> a)
{
        vec.insert({s,a});
}
int main()
{
        std::string cont = "inasd";
        std::vector<int> lol = {1,2,3,4,5};
        std::map<std::string, std::vector<int>> cases;
        seek(cases,cont,lol);
        for(auto i : cases)
        {
                std::cout << i.first <<" ";
                for(auto l : i.second)
                {
                        std::cout << l <<"    ";
                }
        }
}
*/
#include<iostream>
#include<utility>
#include<map>
#include<vector>
int main()
{
        std::multimap<std::string,std::string> families;
        families.insert({"jame","map"});
        families.insert({"jame","have"});
       auto wn= families.erase("jame");
       for(auto i : families)
       {
               std::cout << i.first <<i.second;

       }
       std::cout <<wn;
}
