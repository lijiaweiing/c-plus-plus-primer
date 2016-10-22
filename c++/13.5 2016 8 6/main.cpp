#include<iostream>
#include<utility>
#include<memory>
#include<string>
#include<algorithm>
#include<sstream>
#include<fstream>
#include<map>
#include<set>

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
        friend std::ostream& operator<<(std::ostream &os,const StrVec& rhs);
        StrVec(std::initializer_list<std::string> il);
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

class QueryResult;
class TextQuery
{
public:
        TextQuery(std::ifstream&);
        QueryResult query(const std::string&)const;
private:
        std::shared_ptr<StrVec>file;
        std::map<std::string ,std::shared_ptr<std::set<std::size_t>>> wm;
};
TextQuery::TextQuery(std::ifstream &is):file()








