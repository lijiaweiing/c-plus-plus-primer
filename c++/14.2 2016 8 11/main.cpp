/*#include <string>
#include <iostream>

class Sales_data {
    friend std::istream& operator>>(std::istream&, Sales_data&); // input
    friend std::ostream& operator<<(std::ostream&, const Sales_data&); // output
    friend Sales_data operator+(const Sales_data&, const Sales_data&); // addition

public:
    Sales_data(const std::string &s, unsigned n, double p):bookNo(s), units_sold(n), revenue(n*p){ }
    Sales_data() : Sales_data("", 0, 0.0f){ }
    Sales_data(const std::string &s) : Sales_data(s, 0, 0.0f){ }
    Sales_data(std::istream &is);
    bool operator==(const Sales_data &lhs ,const Sales_data &rhs);
    bool operator!=(const Sales_data &lhs,const Sales_data&rhs);

    Sales_data& operator+=(const Sales_data&); // compound-assignment
    std::string isbn() const { return bookNo; }

private:
    inline double avg_price() const;

    std::string bookNo;
    unsigned units_sold = 0;
    double revenue = 0.0;
};

std::istream& operator>>(std::istream&, Sales_data&);
std::ostream& operator<<(std::ostream&, const Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);

inline double Sales_data::avg_price() const
{
    return units_sold ? revenue/units_sold : 0;
}
Sales_data::Sales_data(std::istream &is) : Sales_data()
{
    is >> *this;
}

Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
    units_sold += rhs.units_sold;
    revenue += rhs.revenue;
    return *this;
}

std::istream& operator>>(std::istream &is, Sales_data &item)
{
    double price = 0.0;
    is >> item.bookNo >> item.units_sold >> price;
    if (is)
        item.revenue = price * item.units_sold;
    else
        item = Sales_data();
    return is;
}

std::ostream& operator<<(std::ostream &os, const Sales_data &item)
{
    os << item.isbn() << " " << item.units_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}

Sales_data operator+(const Sales_data &lhs, const Sales_data &rhs)
{
    Sales_data sum = lhs;
    sum += rhs;
    return sum;
}
bool Sales_data::operator==(const Sales_data&lhs,const Sales_data &rhs)
{
        return lhs.isbn() == rhs.isbn() && lhs.units_sold == rhs.units_sold &&
                lhs.revenue == rhs.revenue;
}
bool Sales_data::operator!=(const Sales_data &lhs,const Sales_data &rhs)
{
        return !(lhs == rhs);
}
int main()
{
        Sales_data a;
        std::cin >> a;
        std::cout << a;
}
*/
/*
#include<iostream>
#include<memory>
#include<utility>
class String
{
private:
        std::allocator<char> alloc;
        char *elements;
        char *first_free;
        char *cap;
        void free();
        std::pair<char* ,char*> alloc_n_copy(const char*,const char*);
         const char *c_str() const { return elements; }
public:
        friend std::ostream & operator<<(std::ostream &os,const String&);
        friend bool operator>(const String&,const String &);
        friend bool operator<(const String&,const String &);
        String();
        char operator[](unsigned i);
        String(const char*);
        String(const String&);
        char *begin()const{return elements;}
        char *end() const{return first_free;}
        ~String();
        std::size_t size()const;
        String &operator=(const String&);
        String(String &&rhs) noexcept;
        String& operator=(String&&)noexcept;
       friend bool operator==(const String& ,const String &);
       friend bool operator!=(const String&,const String&);
};
bool operator<(const String&lhs,const String &rhs)
{
        return !(lhs > rhs);
}
bool operator>(const String &lhs,const String &rhs)
{
        if(lhs.size() > rhs.size())
        {
                return true;
        }
        else
                return false;
}

String& String::operator=(String&& rhs) noexcept
{
         if (this != &rhs) {
        free();
        elements = rhs.elements;
       first_free = rhs.first_free;
        rhs.elements = rhs.first_free= nullptr;
    }
    return *this;
}
String::String(String && rhs)noexcept:elements(rhs.elements),first_free(rhs.first_free),cap(rhs.cap)
{
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
}
std::pair<char*,char*> String::alloc_n_copy(const char*b,const char*e)
{
        auto data = alloc.allocate(e - b);
        return{data,std::uninitialized_copy(b,e,data)};
}
String::String(const String& rhs)
{
        auto newdata = alloc_n_copy(rhs.begin(),rhs.end());
        elements = newdata.first;
        first_free = cap = newdata.second;
        std::cout <<  "have copy" << std::endl;
}
void String::free()
{
        if(elements)
        {
               for(auto p = first_free;p != elements ; )
               {
                       alloc.destroy(--p);
               }
        }
        alloc.deallocate(elements,first_free- elements);
}
String::~String()
{
        free();
}
String &String::operator=(const String& rhs)
{
        auto data = alloc_n_copy(rhs.begin(),rhs.end());
        free();
        elements = data.first;
        first_free = cap = data.second;
        std::cout << "have copy" << std::endl;
        return *this;
}
String::String(const char *s)
{
        char *sl = const_cast<char*>(s);
    while (*sl)
        ++sl;
    auto newstr = alloc_n_copy(s, ++sl);
    elements = newstr.first;
    first_free = newstr.second;
}

char String::operator[](unsigned i)
{
        return elements[i];
}
std::size_t String::size()const
{
        return first_free - elements -1;
}
std::ostream & operator<<(std::ostream &os,const String& data)
{
        char *c = const_cast<char*>(data.c_str());
    while (*c)
        os << *c++;
    return os;

}
bool operator==(const String&lhs , const String &rhs)
{
        return lhs.c_str() == rhs.c_str() ;
}
bool operator!=(const String&lhs , const String &rhs)
{
        return !(rhs == lhs);
}
int main()
{
        String a("asdasd");
        String b ("as");

        std::cout << a[0];
}
*/
/*
#include<memory>
#include<string>
#include<iostream>
#include<algorithm>
class StrVec
{
private:
        std::allocator<std::string> alloc;
        void chk_n_alloc(){if(size() == capacity()) reallocate();}
        std::pair<std::string*,std::string*> alloc_n_copy(const std::string*,const std::string*);
        void free();
        void reallocate();
        std::string *elements;//指向数组指针首元素的指针
        std::string *first_free;//指向数组第一个空闲元素的指针
        std::string *cap;       //指向数组尾后位置的指针
public:
        std::string& operator[](std::size_t n){return elements[n];}
        friend bool operator==(const StrVec&,const StrVec&);
        friend bool operator!=(const StrVec&,const StrVec&);
        friend bool operator>(const StrVec&,const StrVec&);
        friend bool operator<(const StrVec&,const StrVec&);
        StrVec(std::initializer_list<std::string> il);
        StrVec &operator=(std::initializer_list<std::string> );
        StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
        StrVec(const StrVec&);
        StrVec &operator= (const StrVec&);
        ~StrVec();
        void push_back(const std::string&);
        std::size_t size() const {return first_free - elements;}
        std::size_t capacity() const {return cap - elements;}
        std::string *begin() const {return elements;}
        std::string *end() const {return first_free;}

};
StrVec &StrVec::operator=(std::initializer_list<std::string> il)
{
        auto data = alloc_n_copy(il.begin(),il.end());
        free();
        elements = data.first;
        first_free = cap = data.second;
        return *this;
}
bool operator>(const StrVec&lhs,const StrVec &rhs)
{
        return lhs.size() > rhs.size();
}
bool operator<(const StrVec&lhs,const StrVec &rhs)
{
        return lhs.size() < rhs.size();
}
void StrVec::push_back(const std::string &s)
{
        chk_n_alloc();
        alloc.construct(first_free++,s);
}
std::pair<std::string*,std::string*> StrVec::alloc_n_copy(const std::string *b,const std::string *e)
{
        auto data = alloc.allocate(e - b);
        return {data , uninitialized_copy(b,e,data) };
}
void StrVec::free()
{
        if(elements){
                for(auto p = first_free;p != elements ;)
                {
                        alloc.destroy(--p);
                }
                alloc.deallocate(elements,cap - elements);
        }
}
StrVec::StrVec(const StrVec &s)
{
        auto newdata = alloc_n_copy(s.begin(),s.end());
        elements = newdata.first;
        first_free = cap = newdata.second;
}
StrVec::~StrVec()
{
        free();
}
StrVec &StrVec::operator=(const StrVec& rhs)
{
        auto data = alloc_n_copy(rhs.begin(),rhs.end());
        free();
        elements = data.first;
        first_free = cap = data.second;
        return *this;
}
void StrVec::reallocate()
{
        auto newcapacity = size() ? 2 * size() : 1;
        auto newdata = alloc.allocate(newcapacity);//分配一个新内存
        auto dest = newdata;
        auto elem = elements;
        for(std::size_t i = 0; i != size();++i)
        {
                alloc.construct(dest++,std::move(*elem++));
        }
        free();
        elements = newdata;
        first_free = dest;
        cap = elements + newcapacity;

}
StrVec::StrVec(std::initializer_list<std::string> il)
{
        auto newdata = alloc_n_copy(il.begin(),il.end());
        elements = newdata.first;
        first_free = cap = newdata.second;
}
bool operator==(const StrVec &lhs,const StrVec &rhs)
{
        return lhs.size() == rhs.size() && std::equal(lhs.begin(),lhs.end(),rhs.begin());
}
bool operator!=(const StrVec &lhs , const StrVec &rhs)
{
        return!(rhs == lhs);
}
int main()
{
        StrVec c;
      std::string s("asdasd");
      std::string a("sda");
      c.push_back(s);
      c.push_back(a);

       std::cout << c[0];
}
*/
#include<memory>
#include<vector>
#include<iostream>
#include<exception>
class StrBlobPtr;
class StrBlob
{
        friend class StrBlobPtr;
public:
        StrBlobPtr begin();
        StrBlobPtr end();
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
int main()
{
        StrBlob a1 = {"hi","bye","now"};
        StrBlobPtr p(a1);
        *p = "asd";
        std::cout << p->size();
}
