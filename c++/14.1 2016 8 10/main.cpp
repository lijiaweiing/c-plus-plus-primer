//14.7
#include<iostream>
#include<algorithm>
#include<utility>
#include<memory>
#include<vector>
#include<cstring>
#include<exception>
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
        String();
        char& operator[](unsigned i);

        String(const char*);
        String(const String&);
        char *begin()const{return elements;}
        char *end() const{return first_free;}
        ~String();
        std::size_t size()const;
        String &operator=(const String&);
        String(String &&rhs) noexcept;
        String& operator=(String&&)noexcept;
};
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

char& String::operator[](unsigned i)
{
        return *(begin() + i);
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
int main()
{
       String a("sads");
       std::cout << a;

}
*/
