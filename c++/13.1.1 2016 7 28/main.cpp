//13.5
/*#include<iostream>
#include<string>
class HasPrt
{
public:
        HasPrt(const std::string &s = std::string):ps(new std::string(s)),i(0) {}
        HasPrt(const HasPrt& ptr):ps(new std::string(*ptr.ps)),i(ptr.i){}
private:
        std::string *ps;
        int i;
};
*/
//13.4
/*class Point;
Point global;
Point foo_bar(Point arg)//拷贝
{
        Point local = arg; //拷贝
        *heap = new Point(global);//拷贝
        *heap = local;
        Point pa[2] = {local , *heap};//拷贝
        return *heap;
}
*/
//13.8
/*#include<iostream>
#include<string>
class HasPrt
{
public:
        HasPrt(const std::string &s = std::string):ps(new std::string(s)),i(0) {}
        HasPrt(const HasPrt& ptr):ps(new std::string(*ptr.ps)),i(ptr.i){}
        HasPrt& operator=(const HasPrt& ptr);
private:
        std::string *ps;
        int i;
};
HasPrt& HasPrt::operator=(const HasPrt& ptr)
{
        if(*this == ptr ) return *this; //认同测试 如果是自我赋值就不会做任何事
        delete ps;
        ps = new std::string(*ptr.ps);
        i = ptr.i;
        return *this;
}
*/
//13.11
/*#include<iostream>
#include<string>
class HasPrt
{
public:
        HasPrt(const std::string &s = std::string):ps(new std::string(s)),i(0) {}
        HasPrt(const HasPrt& ptr):ps(new std::string(*ptr.ps)),i(ptr.i){}
        HasPrt& operator=(const HasPrt& ptr);
        ~HasPrt();
private:
        std::string *ps;
        int i;
};
HasPrt& HasPrt::operator=(const HasPrt& ptr)
{
        if(*this == ptr ) return *this; //认同测试 如果是自我赋值就不会做任何事
        delete ps;
        ps = new std::string(*ptr.ps);
        i = ptr.i;
        return *this;
}
HasPrt::~HasPrt()
{
        delete ps;
}
*/
/*#include<iostream>
class numbered
{
private:
        int mysn;
public:
        numbered(const numbered& num):mysn(num.mysn){}
        friend void f(const numbered &s);
        numbered(const int a):mysn(a){}
        numbered &operator=(const numbered &num)
        {
                mysn = num.mysn;
                return *this;
        }

};
void f(const numbered &s)
{
        std::cout << s.mysn << std::endl;
}
int main()
{
 numbered a(12),b = a;
 f(a);f(b);
}
*/
#include <iostream>

class numbered {
public:
    numbered() {
        mysn = unique++;
    }

    numbered(const numbered& n) {
        mysn = unique++;
    }

    int mysn;
    static int unique;
};

int numbered::unique = 10;

void f(numbered s) {
    std::cout << s.mysn << std::endl;
}

int main()
{
    numbered a, b = a, c = b;
    f(a);
    f(b);
    f(c);
}
