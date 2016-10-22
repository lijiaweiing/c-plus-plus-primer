/*#include<iostream>
#include<string>

class HasPtr {
public:
        HasPtr(HasPtr &&p)noexcept : ps(std::move(p.ps)),i(p.i){p.ps = 0;}
        friend void swap(HasPtr &lhs,HasPtr &rhs);
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) { }
    HasPtr& operator=(const HasPtr &rhs_hp) {
        if(this != &rhs_hp){
            std::string *temp_ps = new std::string(*rhs_hp.ps);
            delete ps;
            ps = temp_ps;
            i = rhs_hp.i;
        }
        return *this;
    }
private:
    std::string *ps;
    int i;
};
void swap(HasPtr &lhs,HasPtr &rhs)
{
        using std::swap;
        swap(lhs.ps,rhs.ps);
        swap(lhs.i,rhs.i);
}
int main()
{
        return 0;
}
*/
/*
#include<iostream>
#include<utility>
#include<string>
#include<vector>
#include<algorithm>
class StrVec
{
public:
        StrVec():elements(nullptr),first_free(nullptr),cap(nullptr){}
        StrVec(const StrVec&);
        StrVec(StrVec &&)noexcept;
        StrVec& operator=(StrVec&&)noexcept;
        StrVec& operator=(const StrVec&);
        ~StrVec();
        std::size_t size()const {return first_free - elements;}
        std::size_t capacity()const {return cap - first_free;}
        std::string *begin()const {return elements;}
        std::string *end()const {return first_free;}
private:
        std::string *elements;
        std::string *first_free;
        std::string *cap;
        std::allocator<std::string>alloc;
        std::pair<std::string* ,std::string*> alloc_n_copy(const std::string*,const std::string*);
        void free();
        void reallocate();
        void chk_n_alloc(){if(size() == capacity()) reallocate();}
};
std::pair<std::string*,std::string*> StrVec::alloc_n_copy(const std::string* e,const std::string *c)
{
        auto data = alloc.allocate(c - e);
        return {data ,uninitialized_copy(e,c,data)};
}

void StrVec::free()
{
        if(elements)
        {
                for_each(elements,first_free,[this](const std::string &rhs){alloc.destroy(&rhs);});
                alloc.deallocate(elements,cap - elements);
        }
}
StrVec::~StrVec()
{
        free();
}
void StrVec::reallocate()
{
        auto newszie = size() ?2 * size() :1;
        auto data = alloc.allocate(newszie);
        auto dest = data;
        auto quest = elements;
        for(size_t i = 0; i != size();++i)
        {
                alloc.construct(dest++,std::move(*quest ++));
        }
        elements = data;
        first_free = dest;
        cap = dest + newszie;

}
StrVec::StrVec(const StrVec &rhs)
{
        auto data = alloc_n_copy(rhs.begin(),rhs.end());
        elements = data.first;
        first_free = cap = data.second;
}
StrVec& StrVec::operator=(const StrVec& rhs)
{
        if(&rhs == this) return *this;
        auto date = alloc_n_copy(rhs.begin(),rhs.end());
        free();
        elements = date.first;
        first_free = cap = date.second;
        return *this;
}
StrVec::StrVec(StrVec &&rhs)noexcept:elements(rhs.elements),first_free(rhs.first_free),cap(rhs.cap)
{
        rhs.first_free = rhs.elements = rhs.cap = nullptr;
}
StrVec& StrVec::operator=(StrVec && rhs)noexcept
{
        if(this != &rhs)
        {
                free();
                elements = rhs.elements;
                first_free = rhs.first_free;
                cap = rhs.cap;
                rhs.cap = rhs.elements = rhs.first_free = nullptr;
        }
        return *this;
}
int main()
{
        return 0;
}
*/
#include<string>
#include<iostream>
class HasPtr {
public:
        HasPtr(HasPtr &&p)noexcept : ps(std::move(p.ps)),i(p.i){p.ps = 0;}
        friend void swap(HasPtr &lhs,HasPtr &rhs);
        ~HasPtr();
        std::string get_ps();
    HasPtr(const std::string &s = std::string()) : ps(new std::string(s)), i(0) { }
    HasPtr(const HasPtr &hp) : ps(new std::string(*hp.ps)), i(hp.i) { }
    HasPtr& operator=(HasPtr rhs_hp) {
        swap(*this,rhs_hp);
        return *this;
    }
private:
    std::string *ps;
    int i;
};
HasPtr::~HasPtr()
{
        delete ps;
}
void swap(HasPtr &lhs,HasPtr &rhs)
{
        using std::swap;
        swap(lhs.ps,rhs.ps);
        swap(lhs.i,rhs.i);
}
std::string HasPtr::get_ps()
{
        return *ps;
}
int main()
{
        HasPtr a("asdas");
        HasPtr b;
        b = a;

       std::cout << b.get_ps();
}
