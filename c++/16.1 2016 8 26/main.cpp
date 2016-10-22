#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<list>
#include<memory>
#include"vec.h"
/*int campare(const std::string &v1,const std::string &v2)
{
        if(v1 < v2) return -1;
        if(v1 > v2) return 1;
}
int compare(const double &v1,const double &v2)
{
        if(v1 < v2) return -1;
        if(v1 > v2) return 1;
}*/
template<typename T>int compare(const T &v1,const T &v2)
{
        if(v1 < v2) return -1;
        if(v1 > v2) return 1;
        return 0;
}
template<typename T,typename U>T finds(const T &v1,const T& v2,const U& v3)
{
        T i;
        for(i = v1;i == v2;++i)
        {
                if(*i ==v3)
                        break;
        }
        return i;
}

template<typename U,unsigned T>constexpr std::size_t um(const U (&p)[T])
{
        return T;
}
template<typename U,unsigned T>U* arry_begin( U (&p)[T])
{
        return p;
}
template<typename U,unsigned T> U* arry_end(U (&p)[T])
{
        return p + T;
}
/*template<typename T> void sort_op( T const& t)
{
        for(typename T::size_type i = 0;i != t.size();++i)
        {
                std::cout << t[i];
        }
}*/
template<typename T>std::ostream& print(std::ostream &os,T const &t)
{
        for(auto i = t.begin();i != t.end();++i)
        {
                os << *i <<std::endl;
        }
        return os;
}




int main()
{
    vec<std::string> s = {"op","hello","jasd"};
    for(auto i : s)
    {
        std::cout <<i << std::endl;
    }
}
