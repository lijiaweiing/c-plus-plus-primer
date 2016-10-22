/*#include<memory>
#include<vector>
#include<iostream>
#include<exception>
class StrBlobPtr;
class constBlobPtr;
class StrBlob
{
        friend class StrBlobPtr;
        friend class constBlobPtr;
public:
        StrBlobPtr begin();
        StrBlobPtr end();
        constBlobPtr cbegin()const;
        constBlobPtr cend()const;
        typedef std::vector<std::string>::size_type size_type;
        StrBlob();
        StrBlob(std::initializer_list<std::string>il);
        size_type size() const{return data->size();}
        bool empty() const{return data->empty();}
        void push_back(const std::string &t ){data ->push_back(t);}
        void pop_back( );//删除尾元素
        std::string& front();
        std::string& back();
        friend bool operator==(const StrBlob& lhs,const StrBlob &rhs);
        friend bool operator!=(const StrBlob&lhs,const StrBlob&rhs);
        std::string operator[](std::size_t i){return *(&(data->front())+i);}



private:
        std::shared_ptr<std::vector<std::string>> data;
        void cherk(size_type i,const std::string &msg )const;
};
class constBlobPtr
{public:
        constBlobPtr():curr(0) {}
        constBlobPtr(const StrBlob&a, size_t sz = 0) : wptr(a.data),curr(sz) {}
        std::string& deref()const;
        constBlobPtr& incr();
        const std::string& operator*()const
        {
                auto p = check(curr,"der");
                return(*p)[curr];
        }
        const std::string* operator->()const
        {
                return & this->operator*();
        }
private:
        std::shared_ptr<std::vector<std::string>> check(std::size_t i,const std::string& msg)const
        {
                auto ret = wptr.lock();
                if(!ret)
                        throw std::runtime_error("unbound");
                if(i >= ret->size())
                        throw std::out_of_range(msg);
                return ret;
        }
        std::weak_ptr<std::vector<std::string>> wptr;
        std::size_t curr;
};
std::string& constBlobPtr::deref()const
{
        auto p = check(curr,"def");
        return (*p)[curr];
}
constBlobPtr& constBlobPtr::incr()
{
        check(curr,"ince");
        ++curr;
        return *this;
}
class StrBlobPtr
{
public:
        friend class StrBlob;
        StrBlobPtr():curr(0){}
        StrBlobPtr(StrBlob &a,size_t sz = 0):wptr(a.data),curr(sz) {}
        std::string &deref() const;
        StrBlobPtr& incr();
        std::string& operator[](std::size_t i)const
        {
                auto p = cherk(curr,"asda");
                return (*p)[i];
        }
        StrBlobPtr & operator++();
        StrBlobPtr& operator--();
        StrBlobPtr& operator++(int);
        StrBlobPtr& operator--(int);
        std::string& operator*()const
        {
                auto p = cherk(curr,"def");
                return (*p)[curr];
        }
        std::string* operator->()const
        {
                return & this->operator*();
        }

private:
        std::shared_ptr<std::vector<std::string>> cherk(std::size_t ,const std::string &)const;
        std::weak_ptr<std::vector<std::string>> wptr;
        std::size_t curr;
};

StrBlobPtr& StrBlobPtr::operator++(int)
{
        StrBlobPtr ret = *this;
        ++*this;
        return ret;
}
StrBlobPtr& StrBlobPtr::operator--(int)
{
        StrBlobPtr ret = *this;
        --*this;
        return ret;
}
StrBlobPtr& StrBlobPtr::operator++()
{
        cherk(curr,"increment past end of StrBlobPtr");
        ++curr;
        return *this;
}
StrBlobPtr& StrBlobPtr::operator--()
{
        --curr;
        cherk(curr,"decrement past begin of StrBlobPtr");
        return *this;
}
std::shared_ptr<std::vector<std::string>> StrBlobPtr::cherk(std::size_t i,const std::string &msg)const
{
        auto ret = wptr.lock();
        if(!ret)
                throw std::runtime_error("unbound StrBlobPtr");
        if(i >= ret->size())
                throw std::out_of_range(msg);
        return ret;
}
std::string& StrBlobPtr::deref()const
{
        auto p = cherk(curr,"def");
        return (*p)[curr];
}
StrBlobPtr& StrBlobPtr::incr()
{
        cherk(curr,"incer");
        ++curr;
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
StrBlobPtr StrBlob::begin()
{
        return StrBlobPtr(*this);
}
StrBlobPtr StrBlob::end()
{
        auto ret = StrBlobPtr(*this,data->size());
        return ret;
}
bool operator==(const StrBlob&lhs,const StrBlob &rhs)
{
        return lhs.data == rhs.data;
}
bool operator!=(const StrBlob&lhs,const StrBlob &rhs)
{
        return !(lhs == rhs);
}
constBlobPtr StrBlob::cbegin()const
{
        return constBlobPtr(*this);
}
constBlobPtr StrBlob::cend()const
{
        auto ret = constBlobPtr(*this,data->size());
        return ret;
}
int main()
{

}
*/
/*
#include<iostream>
struct absInt
{
        int operator()(int val)const
        {
                return val < 0?-val:val;
        }
};
int main()
{
        int i = -42;
        absInt ab;
        int ui = ab(i);
        std::cout << ui;
}
*/
/*#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using std::vector;
class PrintString
{
public:
        PrintString(std::ostream &o = std::cout , char c = ' '):os(o),sep(c) {}
        void operator()(const std::string &s)const{os << s <<sep;}
private:
        std::ostream &os;
        char sep;
};
int main()
{
        std::string s("as");
        PrintString printer;
        printer(s);
        PrintString errors(std::cerr,'\n');
        errors(s);
        vector<std::string> vec = {"ha","ko","asd"};
        std::for_each(vec.begin(),vec.end(),PrintString(std::cerr,'\n'));
}
*/
/*#include<iostream>
#include<string>
#include<vector>

class PrintString
{
public:
        PrintString(std::istream &i = std::cin,std::string c= " "):is(i){}
       std::string operator()()const
       {
               std::string c1;
               std::getline(is,c1);
               return is?c1 : std::string();

       }
private:
        std::istream &is;

};
int main()
{
        PrintString a;
        std::vector<std::string> vec;
       for(size_t i = 0; i < 5; ++i)
       {
               std::cout << "the" << i <<":";
               vec.push_back(a());


       }
       for(auto i : vec)
       {
               std::cout  << i <<std::endl;
       }
}
*/
/*#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
class Sizecom
{
private:
        std::size_t sz;
public:
        Sizecom(std::size_t i):sz(i){}
        bool operator()(const std::string &s)const
        {
                return s.size() == sz;
        }
};
int main()
{
        std::vector<std::string> vec = {"I","am","a","wonderful","kill","you","nonte","me"};
        std::stable_sort(vec.begin(),vec.end(),[](const std::string&a,const std::string& b){return a.size() < b.size();});
        for(std::size_t i = 1;i <= 10;++i)
        {
                auto wc = std::find_if(vec.begin(),vec.end(),Sizecom(i));
                int l = i+1;
                auto wd = std::find_if(vec.begin(),vec.end(),Sizecom(l));
                auto f = wd - wc;
                std::cout<<"size "<<i <<"is"<<f <<std::endl;
        }
}

