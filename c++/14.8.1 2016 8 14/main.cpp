/*
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include<sstream>
#include<map>
#include<algorithm>
class SizeComp
{
private:
        std::size_t front;
        std::size_t back;
public:
        SizeComp(std::size_t a,std::size_t b):front(a),back(b){}
        bool operator()(const std::string &s)
        {
                return s.size() >= front && s.size() <back;
        }

};
int main()
{
        std::map<std::size_t,std::size_t>vec;

        std::ifstream infile("one.txt");
        if(!infile)
        {
                std::cerr << "can not open this file";
        }
        else
        {
                std::string a1;
                while(infile >> a1)
                {
                        ++vec[a1.size()];
                }
               for(size_t i = 1; i <= 10;++i)
               {
                       std::cout <<"the"<<i <<" "<<vec[i] <<std::endl;
               }
        }
}
*/
/*
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
class ShortComp
{

public:
        bool operator()(const std::string &a,const std::string &b)
        {
               return  a.size() < b.size();
        }

};
class PrintShort
{
private:
        std::ostream &os;
        char sep;
public:
        PrintShort(std::ostream &o = std::cout ,char a = ' '):os(o),sep(a){}
        void operator()(const std::string &s)
        {
               os << s <<sep;
        }
};
class ShortString
{
private:
        std::size_t sz;
public:
        ShortString(std::size_t a = 0):sz(a){}
        bool operator()(const std::string &s)
        {
                return s.size() >= sz;
        }
};
void elimDups(std::vector<std::string> &word)
{
        std::sort(word.begin(),word.end());
        auto end_op = std::unique(word.begin(),word.end());
        word.erase(end_op,word.end());
}
std::string make_plural(int i,std::string a,std::string s)
{
        if(i > 1)
        {
                return a + s;

        }
        else
        {
                return a;
        }
}
void biggies(std::vector<std::string> &words,std::vector<std::string>::size_type sz)
{
        elimDups(words);
        std::stable_sort(words.begin(),words.end(),ShortComp());
        auto wc = std::find_if(words.begin(),words.end(),ShortString(sz));
        auto count = words.end() - wc;
        std::cout <<count <<" "<<make_plural(count,"word","s")
        <<"of length" << sz << " or longer" <<std::endl;
        std::for_each(wc,words.end(),PrintShort());
        std::cout <<std::endl;


}
int main()
{
        std::vector<std::string> vec = {"asd","klol","sad","ui"};
        biggies(vec,2);
}
*/
/*#include<iostream>
#include<string>
#include<algorithm>
#include<functional>
#include<vector>
int main()
{
        std::vector<int> vec = {1,23,344,54,90,789980,52637346,123314345,4554565,343234,23423423,423,454};
        std::sort(vec.begin(),vec.end(),std::less<int>());
        auto wc = std::find_if(vec.begin(),vec.end(),[](const int i){return i > 1024;});
        auto i = vec.end() - wc;
        std::cout << i;
        std::vector<std::string> vecs = {"pooh","pooh","have",""}

}
*/
/*
#include<functional>
#include<iostream>
#include<map>
#include<string>
int add(int i ,int j){return i + j;}
auto mod = [](int i , int j ){return i % j;};
struct divide
{
        int operator()(int i,int j)
        {
                return i / j;
        }
};
int main()
{
        std::map<std::string , std::function<int(int,int)>> binops ={{"+",add},{"-",std::minus<int>()},{"/",divide()},
        {"*",[](int i,int j){return i * j;}} ,{"%",mod} };
        std::cout << binops["+"](2,5);
}
*/
