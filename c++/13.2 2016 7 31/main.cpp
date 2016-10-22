//13.22
/*
#include<iostream>
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
*/
//13,26
/*
#include<memory>
#include<vector>
#include<iostream>
#include<exception>
class StrBlob
{
public:
        typedef std::vector<std::string>::size_type size_type;
        StrBlob();
        StrBlob(const StrBlob & a);
        StrBlob& operator=(const StrBlob &a);
        StrBlob(std::initializer_list<std::string>il);
        size_type size() const{return data->size();}
        bool empty() const{return data->empty();}
        void push_back(const std::string &t ){data ->push_back(t);}
        void pop_back( );//删除尾元素
        std::string& front();
        std::string& back();

private:
        std::shared_ptr<std::vector<std::string>> data;
        void cherk(size_type i,const std::string &msg )const;
};
StrBlob::StrBlob(const StrBlob& a)
{
        data = std::make_shared<std::vector<std::string>>(*a.data);

}
StrBlob& StrBlob::operator=(const StrBlob&a)
{
        if(this == &a)return *this;
        data =  std::make_shared<std::vector<std::string>>(*a.data);
        return *this;
}
StrBlob::StrBlob():data(std::make_shared<std::vector<std::string>>()){}
StrBlob::StrBlob(std::initializer_list<std::string>il):data(std::make_shared<std::vector<std::string>>(il)){}
void StrBlob::cherk(size_type i,const std::string &msg)const
{
        if(i >= data->size())
                throw std::out_of_range(msg);
}
std::string& StrBlob::front()
{
        StrBlob::cherk(0,"front on empty StrBlob");
        return data->front();
}
std::string& StrBlob::back()
{
        StrBlob::cherk(0,"back on empty StrBlob");
        return data->back();
}
void StrBlob::pop_back()
{
        StrBlob::cherk(0,"pop_cherk on empty StrBlob");
        data->pop_back();
}
int main()
{
        StrBlob b1;
        {
                StrBlob b2 = {"a","an","the"};
                b1 = b2;
                b2.push_back("about");
                auto wc = b1.back();
                std::cout << wc;
        }
}
*/
//13.27
/*
#include<iostream>
#include<string>
class HasPtr
{
private:
        std::string *ps;
        std::size_t *t;
        int i;
public:
        HasPtr(const std::string &s = std::string()):ps(new std::string(s)),i(0),t(new std::size_t(1)){}
        HasPtr(const HasPtr &v):ps(v.ps),i(v.i),t(v.t) {++*t;}
        HasPtr &operator= (const HasPtr &v)
        {
                ++*v.t;
                if(--*t == 0 )
                {
                        delete ps;
                        delete t;
                }
                t = v.t;
                ps = v.ps;
                i = v.i;
                return *this;
        }
        ~HasPtr()
        {
               if(--*t == 0)
               {
                       delete t;
                       delete ps;
               }
        }
};
*/
//13.28 a
/*#include<iostream>
#include<string>
class TreeNode
{
private:
        std::string value;
        int count;
        TreeNode *left;
        TreeNode *right;
public:
        TreeNode():
};
class BinStrTree
{
private:
        TreeNode *root;
};
*/
#include<iostream>
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

}
int main()
{

}
