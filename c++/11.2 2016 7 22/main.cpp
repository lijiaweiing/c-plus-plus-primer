/*#include<map>
#include<set>
#include<iostream>
#include<string>
int main()
{
        std::map<std::string, std::size_t> word_count;
        std::set<std::string> exclude = {"the", "but", "and", "or"};
        std::map<std::string,std::string> authors = {{"Joyce","James"},{"Austen","Jane"}};
}
*/
/*#include<map>
#include<set>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<numeric>
int main()
{
        std::map<std::string,std::vector<std::string>> family_counts = {{"Joyce",{"jame","sam","doge"}}};
        std::vector<std::string> vec = {"have","li"};
        family_counts["Joyce"].insert(family_counts["Joyce"].begin(),vec.begin(),vec.end());
        for(auto i : family_counts)
        {
                std::cout << i.first << std::endl;
                for(auto s : i.second)
                        std::cout << s <<" ";
        }
        std::map<std::string,std::vector<std::string>> family_counts;
        std::vector<std::string> vec;
        std::string s,r;
        std::cout << "Please cin the issue" << std::endl;
        while(std::cin >> s && s!= "@q")
        {
                std::cout <<"play:";
                while(std::cin >> r && r != "@q")
                        family_counts[s].push_back(r);
        }
        for(const auto &a : family_counts)
        {
                std::cout << a.first << std::endl;
                for(auto l : a.second)
                        std::cout << l <<" ";
        }
}
*/
/*#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
        std::vector<int> vec = {1,2,3,4,5,1,2,1,2,12,12,1,34};
        std::sort(vec.begin(),vec.end());
        auto wc = std::unique(vec.begin(),vec.end());
        vec.erase(wc,vec.end());
        for(auto i : vec)
        {
                std::cout << i <<std::endl;
        }

}
*/
/*#include<set>
#include<iostream>
int main()
{
        std::set<int> vec = {1,2,3,1,1,1,1,3,4,5,6,7,34,12,1,3,6};
        for(auto i :vec)
                std::cout <<i <<" ";
}
*/
/*#include<iostream>
#include<utility>
#include<string>
#include<vector>
pair<std::string,int> process(std::vector<std::string> &v)
{
        if(!v.empty())
        {
            return {v.back(),v.back().size()};
        }
        else
        {
                return std::pair<std::string>();
        }
}
int main()
{
        std::pair<std::string,std::string> anon{"jame","joyce"};
        std::pair<std::string ,std::size_t> word_count;
        std::pair<std::string,std::vector<int>> line;

}
*/
/*#include<iostream>
#include<utility>
#include<vector>
#include<string>
;
int main()
{
        std::vector<std::pair<std::string ,int>> vec;
        std::string words;int s;
       while(std::cin>>words>>s)
       {
               std::pair<std::string ,int> sold{words,s};
               vec.push_back(sold);
       }
       for(auto  a: vec)
       {
               std::cout<<"string : " << a.first << " int: "<< a.second << std::endl;
       }
       return 0;
}
*/
/*#include<map>
#include<set>
#include<vector>
#include<iostream>
#include<string>
#include<algorithm>
#include<numeric>
#include<utility>
int main()
{
        std::map<std::string,std::vector<std::string>> family_counts = {{"Joyce",{"jame","sam","doge"}}};
        std::vector<std::string> vec = {"have","li"};
        family_counts["Joyce"].insert(family_counts["Joyce"].begin(),vec.begin(),vec.end());
        for(auto i : family_counts)
        {
                std::cout << i.first << std::endl;
                for(auto s : i.second)
                        std::cout << s <<" ";
        }
        std::map<std::string,std::vector<std::pair<std::string,std::string>>> family_counts;
        std::vector<std::string> vec;
        std::string s,l,dates;
        std::cout << "Please cin the issue" << std::endl;
        while(std::cout<<"please enter last name:"&&std::cin >> s && s!= "@q")
        {
               while(std::cout<<"please enter your first name:"&&std::cin >>l &&std::cout<<"please enter birthday:"&&std::cin>> dates && l != "@q")
               {
                    std::pair<std::string,std::string> lol{l,dates};
                    family_counts[s].push_back(lol);

               }
        }
        for(const auto &a : family_counts)
        {
                std::cout << a.first << std::endl;
                for(auto l : a.second)
                        std::cout << l.first <<" "<<l.second <<std::endl;
        }
}
*/
/*#include<list>
#include<map>
#include<iostream>
#include<set>
int main()
{
        std::set<int> iset = {0,1,2,3,4,5,6,7,8,9};
        std::set<int>::iterator set_it = iset.cbegin();
        while(set_it != iset.cend() )
        {
                std::cout << *set_it <<std::endl;
                ++set_it;
        }
}
*/
//
map
