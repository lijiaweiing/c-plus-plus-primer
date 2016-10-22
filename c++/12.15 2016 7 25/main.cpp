#include<iostream>
#include<vector>
#include<memory>
#include<string>
#include<exception>
class StrBlobPtr;
class StrBlob
{
        friend class StrBlobPtr;
public:

        StrBlobPtr begin() ;
        StrBlobPtr end() ;
        typedef std::vector<std::string>::size_type size_type;
        StrBlob();
        StrBlob(std::initializer_list<std::string>il);
        size_type size() const{return data->size();}
        bool empty() const{return data->empty();}
        void push_back(const std::string &t ){data ->push_back(t);}
        void pop_back( );
        std::string& front();
        std::string& back();

private:
        std::shared_ptr<std::vector<std::string>> data;
        void cherk(size_type i,const std::string &msg )const;
};
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
class StrBlobPtr
{
public:
        StrBlobPtr():curr(0){}
        StrBlobPtr(StrBlob &a,size_t sz = 0):wptr(a.data),curr(sz){}
        std::string& deref()const;
        StrBlobPtr& incr();
        bool operator!=(const StrBlobPtr& p) { return p.curr != curr; }
private:
        std::shared_ptr<std::vector<std::string>> cherk(std::size_t ,const std::string&)const;
        std::weak_ptr<std::vector<std::string>> wptr;
        std::size_t curr;
};
std::shared_ptr<std::vector<std::string>> StrBlobPtr::cherk(std::size_t i, const std::string &msg) const
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
        auto p = cherk(curr,"defeference past end");
        return (*p)[curr];
}
StrBlobPtr& StrBlobPtr::incr()
{
        cherk(curr,"increment past end of StrBlobPtr");
        ++curr;
        return *this;
}
inline StrBlobPtr StrBlob::begin()
{
    return StrBlobPtr(*this);
}

inline StrBlobPtr StrBlob::end()
{
    auto ret = StrBlobPtr(*this, data->size());
    return ret;
}

int main()
{
        StrBlob b2 = {"a","an","the"};
 for(auto i= b2.begin();i != b2.end() ; i.incr())
        std::cout << i.deref() << std::endl;
}
