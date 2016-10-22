//10.20
/*#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
int main()
{
        std::vector<std::string> vec = {"the","quickasda","red","fox","jump","over","the","slow","red","trutle"};
        auto i =std::count_if(vec.begin(),vec.end() , [](const std::string &a){return a.size() > 6 ;});
        std::cout<<i;
}
*/
/*#include<iostream>
#include<algorithm>
#include<vector>
int main()
{
        int i = 6;
        auto s = [&i](){return (--i) == 0? true : false ;};
        while(!s())
                std::cout << i << std::endl;
        std::cout<< i;
}
*/
/*
#include<iostream>
#include <functional>
#include<string>
bool cherk_size(std::string &s,std::string::size_type sz)
{
        return s.size() >= sz;
}
int main()
{
        using  std::placeholders::_1;
        std::string s = "hello";
        auto cherk6 = std::bind(cherk_size,_1,2);
        bool b1 = cherk6(s,6);
        std::cout << b1;
}
*/
/*#include<iostream>
#include<numeric>
#include<algorithm>
#include<functional>
#include<vector>
#include<string>
bool cherk_size(const std::string &s,std::string::size_type sz)
{
        return s.size() <= sz;
}
bool isShort(const std::string& a,const std::string &b)
{
        return (a.size() > b.size())?true:false;
}
int main()
{
        using namespace std::placeholders;
        std::vector<std::string> vec = {"the","quasdahjhjhj","red","fox","jump","over","the","slow","red","trutle"};
        std::stable_sort(vec.begin(),vec.end(),std::bind(isShort,_1,_2));
        auto  fx = find_if(vec.begin(),vec.end(),std::bind(cherk_size,_1,6));
        auto count = vec.end() - fx;
        std::cout <<count;


}
*/
/*#include<iostream>
#include<algorithm>
#include<functional>
#include<string>
#include<numeric>
bool isShort(const int & a,const int &b)
{
        return (sizeof(a) > sizeof(b))?true:false;
}
bool cherk_size(const std::string  &s,std::string::size_type sz)
{
        return s.size() <  sz;
}
 main()
{

        using namespace std::placeholders;
        std::string a("asda");
        std::vector<int>  vec = {1,2,3,4,5};

        auto fx = find_if(vec.begin(),vec.end(), std::bind(cherk_size,a,_1));
       if(fx != vec.end())
       {
               std::cout << *fx;
       }
       else
       {
               std::cout << "not found";
       }
        return 0;
}
*/
//10.25
/*#include<iostream>
#include<algorithm>
#include<numeric>
#include<vector>
#include<functional>
bool cherk_size(const std::string  &s,std::string::size_type sz)
{
        return s.size() <  sz;
}
void elimDups(std::vector<std::string> &words)
{
        std::sort(words.begin(),words.end());
        auto end_unique = unique(words.begin(),words.end());
        words.erase(end_unique,words.end());
}
void biggies(std::vector<std::string> &words , std::vector<std::string>::size_type sz)
{
        using namespace std::placeholders;
        elimDups(words);
        auto fix = std::partition(words.begin(),words.end(),std::bind(cherk_size,_1,sz));
        words.erase(fix,words.end());
        int count = words.size();
        std::cout << count;
}
int main()
{
        std::vector<std::string> vec = {"the","quasdahjhjhj","red","fox","jump","over","the","slow","red","trutle"};
        biggies(vec,4);

}
*/
