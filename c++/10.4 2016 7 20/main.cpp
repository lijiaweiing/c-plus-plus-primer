//10.27
/*#include<iostream>
#include<iterator>
#include<algorithm>
#include<vector>
#include<list>
#include<numeric>
#include<functional>
bool iSshort(const int &a,const int &b)
{
        return (a<b)?true:false;
}
int main()
{
        using namespace std::placeholders;
        std::vector<int> vec = {1,2,3,3,4,5,7,5};
        std::list<int> lst1;
        std::sort(vec.begin(),vec.end(),std::bind(iSshort,_1,_2));
        std::unique_copy(vec.begin(),vec.end() ,back_inserter(lst1));

       for(auto i : lst1)
                std::cout << i <<std::endl;
}
*/
/*#include<vector>
#include<iterator>
#include<iostream>
#include<list>

int main()
{
        std::vector<int> vec = {1,2,3,4,5,6,7,8,9};
        std::list<int> lst1,lst2,lst3;
        std::copy(vec.cbegin() , vec.cend() ,back_inserter(lst1));
        for(auto i : lst1)
                std::cout << i <<std::endl;
}
*/
/*
#include <iostream>     // std::cin, std::cout
#include <iterator>     // std::istream_iterator

int main () {
  double value1, value2;
  std::cout << "Please, insert two values: ";

  std::istream_iterator<double> eos;              // end-of-stream iterator
  std::istream_iterator<double> iit (std::cin);   // stdin iterator

  if (iit!=eos) value1=*iit;

  ++iit;
  if (iit!=eos) value2=*iit;

  std::cout << value1 << "*" << value2 << "=" << (value1*value2) << '\n';

  return 0;
}
*/
/*#include<iterator>
#include<iostream>
#include<vector>
#include<algorithm>
int main()
{
     std::istream_iterator<int> in(std::cin),eof;
     std::cout << std::accumulate(in,eof,0) <<std::endl;
}
*/
/*#include<iostream>
#include<iterator>
#include<vector>
#include<algorithm>
int main ()
{
        std::ostream_iterator<int> out_iter(std::cout," " );
        std::vector<int> vec = {1,2,3,4};
        std::copy(vec.begin(),vec.end(),out_iter);

}
*/
//10.29
/*#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>
#include<iterator>
int main()
{
        std::string word;
        std::ifstream infile("D:\\c++2008\\hi.txt");
        std::istream_iterator<std::string> string_iter(infile),eof;
       if(!infile)
       {
               std::cerr << "cannot open it";
       }
       else
       {
               std::vector<std::string> vec(string_iter,eof);
               for(auto i : vec)
                        std::cout << i << " " ;
       }
        return 0;
}
*/
/*#include<vector>
#include<iostream>
#include<iterator>
#include<algorithm>
#include<functional>
bool isShort(const int &a,const int&b)
{
        return (a<b)?true : false;
}
int main()
{
        using namespace std::placeholders;
        std::ostream_iterator<int> iter(std::cout," " );
        std::vector<int> vec = {1 ,2,5,3,5,6,7,8,9,9,8,21,17};
        std::sort(vec.begin(),vec.end(),std::bind(isShort,_1,_2));
        std::unique_copy(vec.begin(),vec.end(),iter);
}
*/
/*#include<iostream>
#include"Sales_item.h"
int main()
{
        Sales_item total;
        if(std::cin >> total)
        {
                Sales_item trains;
                while(std::cin >> trains)
                {
                        if(total.isbn() == trains.isbn())
                                total += trains;
                        else
                        {
                                std::cout << total <<std::endl;
                                total = trains;
                        }
                }
                std::cout << total << std::endl;
        }
        else
        {
                std::cerr << "No data?!" <<std::endl;
                return -1;
        }
        return 0;

}
*/
/*#include<iostream>
#include"Sales_item.h"
#include<iterator>
#include<vector>
#include<algorithm>
#include<numeric>
#include<functional>
#include<string>
bool cases(const Sales_item &a,const Sales_item &b)
{
        return (a.isbn() == b.isbn())?true : false;
}
bool isShort(const Sales_item &a,const Sales_item &b)
{
        return (a.isbn().size() > b.isbn().size())?true : false;
}
int main()
{
        using namespace std::placeholders;
        std::vector<Sales_item> vec;
        Sales_item item;
        int i = 0;
        while(std::cin >> item && i <5)
        {
                vec.push_back(item);
                ++i;
        }
        std::sort(vec.begin(),vec.end(),bind(isShort,_1,_2));
        for(std::vector<Sales_item>::iterator it = vec.begin() ; it != vec.end() ;)
        {

               auto wc = std::find_if(it,vec.end(),[it](const Sales_item &a){return it->isbn() < a.isbn();});
               Sales_item b = std::accumulate(it,wc,Sales_item(it->isbn()));
               std::cout << b <<std::endl;
               it = wc+1;
        }
        return 0;

}
*/
/*#include<vector>
#include<iterator>
#include<iostream>
int main()
{
        std::vector<int> vec = {0,1,2,3,4,5,6,7,8};
        for(auto r_iter = vec.crbegin();r_iter != vec.crend(); ++ r_iter)
        {
                std::cout << *r_iter;
        }
}*/
#include<iostream>
#include<iterator>
#include<vector>
int main()
{
        std::vector<int> vec = {1,2,3,4,5,6,7,8};
        for(auto i = vec.end() ; i = vec.begin();--i)
                std::cout << *i <<" ";
}
