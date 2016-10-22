//10.3
/*#include<numeric>
#include<vector>
#include<iostream>
int main()
{
        std::vector<double> item = {1.6,2.9,3.4,5.6,7,10,23,34,45,56,67};
        int sum = std::accumulate(item.begin(),item.end(),0.0);
        std::cout<<sum;
}
*/
/*#include<iostream>
#include<numeric>
#include<vector>
int main()
{
        std::vector<int> a(10,0);
        std::fill(a.begin() , a.begin() + a.size()/2 ,10);
        std::fill_n(a.begin(), 3 , 2);
        for(auto i : a)
                std::cout<<i<<std::endl;
}
*/
//Example by back_inserter
/*
#include <iostream>     // std::cout
#include <iterator>     // std::back_inserter
#include <vector>       // std::vector
#include <algorithm>    // std::copy

int main () {
  std::vector<int> foo,bar;
  for (int i=1; i<=5; i++)
  { foo.push_back(i); bar.push_back(i*10); }

  std::copy (bar.begin(),bar.end(),back_inserter(foo));

  std::cout << "foo contains:";
  for ( std::vector<int>::iterator it = foo.begin(); it!= foo.end(); ++it )
	  std::cout << ' ' << *it;
  std::cout << '\n';

  return 0;
}
*/
/*#include<iostream>
#include<vector>
#include<iterator>
#include<numeric>
int main()
{
        std::vector<int> vec;
        std::fill_n(back_inserter(vec),10,0);
        for(auto i : vec)
        {
                std::cout<<i;
        }
}
*/
//10.6
/*#include<numeric>
#include<iostream>
#include<vector>
int main()
{
        std::vector<int> vec(10,2);
        std::fill_n(vec.begin(),vec.size(),0);
        for(auto i : vec)
                std::cout << i <<std::endl;
}
*/
//10.7 2
/*#include<iostream>
#include<string>
#include<numeric>
#include<vector>
int main()
{
        std::vector<int> vec;
        vec.reserve(10);
        std::fill_n(vec.begin(),10,1);
        for(auto i : vec)
                std::cout << i <<std::endl;
        return 0;
}
*/
//10.2.3
/*#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
void eliDups(std::vector<std::string> &word)
{

        std::sort(word.begin(),word.end());
        auto end_unique = unique(word.begin(),word.end());
        word.erase(end_unique,word.end());
}
bool isShorter(const std::string &s1,const std::string &s2)
{
        return s1.size() < s2.size();
}
int main()
{
        std::vector<std::string> item = {"the","quick","red","fox","jump","over","the","slow","red","trutle"};
        eliDups(item);
        std::stable_sort(item.begin() , item.end() , isShorter);
        for(auto i : item)
        {
                std::cout << i << std::endl;
        }
}
*/
/*#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
bool  isShorter(const std::string &s)
{
        if(s.size() >= 5)
                return true;
        else
                return false;
}
int main()
{
        std::vector<std::string> vec = {"ambualce","hava","else","computer","come else","sies"};
        auto bound = std::partition(vec.begin(),vec.end(),isShorter);
        vec.erase(bound,vec.end());
        for(auto i : vec)
                std::cout << i <<" ";
}
*/
//8.
