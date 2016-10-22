/*#include<set>
#include<algorithm>
#include<iostream>
int main()
{
        std::set<int> iset = {0,1,2,3,4,5,6,7,8,9};
        if(iset.find(12) == iset.end())
                std::cout << "12 is not in the map" <<std::endl;
        auto wc = iset.count(1);
        std::cout << wc;
}
*/
/*#include<map>
#include<iostream>
#include<string>
#include<utility>
int main()
{
        std::multimap<std::string ,std::string> author = {{"Joyce","Jame"},{"Austen","Jane"},{"Austen","Charles"}};
        std::string lol("Austen");
        auto enters = author.count(lol);
        auto iter = author.find(lol);
        while(enters)
        {
                std::cout <<iter->second <<std::endl;
                ++iter;
                --enters;
        }

}
*/
/*#include<map>
#include<iostream>
#include<string>
#include<utility>
int main()
{
        std::multimap<std::string ,std::string> author = {{"Joyce","Jame"},{"Austen","Jane"},{"Austen","Charles"}};
        std::string lol("Austen");
        for(auto beg = author.lower_bound(lol), end = author.upper_bound(lol);beg != end;++beg)
        {
                std::cout << beg->second <<" ";
        }

}*/
/*#include<map>
#include<iostream>
#include<string>
#include<utility>
int main()
{
        std::multimap<std::string ,std::string> author = {{"Joyce","Jame"},{"Austen","Jane"},{"Austen","Charles"}};
        std::string lol("Austen");
        for(auto beg = author.equal_range(lol), end = author.upper_bound(lol);beg != end;++beg)
        {
                std::cout << beg->second <<" ";
        }

}
*/
/*#include<iostream>
#include<map>
#include<utility>
#include<string>
int main()
{
        std::multimap<std::string,std::string> people = {{"Monet","La Rue Montorgueil à Paris"},{"Monet","Les bateaux rouges, Argenteuil"}
        , {"he","jiasd"},{"sasjd","aksd"} };
        std::string lol("Mone");
        if(people.find(lol) == people.end())
        {
                std::cout << "lol is not in the map";
        }
        else
        {
                for(auto pos = people.equal_range(lol);pos.first != pos.second;++pos.first)
                {
                        std::cout << pos.first->second <<std::endl;
                }
        }
}
*/
