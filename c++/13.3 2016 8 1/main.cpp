//13.30
/*#include<iostream>
#include<string>
#include<memory>
class HasPtr
{
private:
        std::string *ps;
        int i;
public:
        HasPtr(const std::string &s = std::string()):ps(new std::string(s)),i(0){}
        HasPtr(const HasPtr &v):ps(new std::string(*v.ps)),i(v.i){}
        friend void swap(HasPtr&,HasPtr&);
        HasPtr &operator= (const HasPtr &v)
        {
                if(this == &v)return *this;
                delete ps;
                ps = new std::string(*v.ps);
                i = v.i;
                return *this;
        }
        ~HasPtr()
        {
                delete ps;
        }
};
inline void swap(HasPtr& lhs,HasPtr& rhs)
{
        using std::swap;
        swap(lhs.ps,rhs.ps);
        swap(lhs.i,rhs.i);
        std::cout << "have swap ";

}
int main()
{
        HasPtr a("asdasd");
        HasPtr b("asda lol");
        swap(a,b);
}
*/
#include<iostream>
#include<string>
#include<vector>
#include<memory>
class HasPtr
{
private:
        std::string *ps;
        int i;
public:
        HasPtr(const std::string &s = std::string()):ps(new std::string(s)),i(0){}
        HasPtr(const HasPtr &v):ps(new std::string(*v.ps)),i(v.i){}
        friend void swap(HasPtr&,HasPtr&);
        bool operator< (const HasPtr&v,const HasPtr );
        HasPtr &operator= (const HasPtr &v)
        {
               this->swap
        }
        ~HasPtr()
        {
                delete ps;
        }
};
inline void swap(HasPtr& lhs,HasPtr& rhs)
{
        using std::swap;
        swap(lhs.ps,rhs.ps);
        swap(lhs.i,rhs.i);
        std::cout << "have swap ";

}
std::vector<HasPtr> operator< (const HasPtr& v)
{
        std::vector<HasPtr> vec;
        vec.push_back(v);
        return vec;
}
int main()
{
        HasPtr a("asdasd");
        HasPtr b("asda lol");
        swap(a,b);
        std::vector<HasPtr> x;
        x<a;
        x<b;

}
