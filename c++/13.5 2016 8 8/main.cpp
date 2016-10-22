//13.43
/*void free()
{
        if(elements)
        {
                for_each(elements,first_free,[this](string &rhs){alloc.destory(&rhs)}  ))
        }
        alloc.deallocate(elements , cap - elements);
}
*/
/*#include<memory>
#include<iostream>
class String
{
private:
       char * ch;
       char *elements;
       char *first_free;
       char *cap;
       void chk_on_copy(const char *rhs);

        std::allocator<const char*> alloc;
public:
        String();
        String(const char * s);
        String(const String& );
        ~String();
        std::size_t size() const{return elements - first_free;}
        char *begin() const;
        char *end() const;
};
void String::chk_on_copy(const char *rhs)
{
        auto i = strlen(rhs);
        auto newcapacity = size()?i + size():1;
        auto newdata = alloc.allocate(newcapacity);
        auto dest = newdata;
        auto elem = elements;
        for(std::size_t i = 0;i != size() ;++i)
        {
                alloc.construct(dest++,std::move(*elem++));
        }
        free();
        elements = newdata;
        first_free = dest;
        cap = elements + newcapacity;
        alloc.construct(elements++ , rhs);

}
*/
/*
#include<iostream>
#include<cstring>
class String
{
private:
        char *ch;
public:
        friend std::ostream& operator<<(std::ostream &os,const String&);
        char *begin()const;
        char *end()const;
        const char& front()const;
        String();
        String(const char*);
        String(const String&);
        ~String();
        String &operator=(const String&);
        char& operator[](unsigned i);
        String operator + (const String &rhs);
        std::size_t size()const;
        std::size_t find(const char*);
};
String::String():ch(new char[1])
{
        *ch = '\0';
}
String::String(const char* k):ch(new char[strlen(k) + 1])
{
        strcpy(ch,k);
}
String::String(const String& rhs)
{
        ch = new char[strlen(rhs.ch)+1];
        strcpy(ch,rhs.ch);
}
String::~String()
{
        delete []ch;
}
String &String::operator=(const String &rhs)
{
        if(&rhs == this) return *this;
        delete ch;
        ch =  new char[strlen(rhs.ch) + 1];
        strcpy(ch,rhs.ch);
        return *this;
}
std::ostream& operator << (std::ostream &os,const String & rhs)
{
        os << rhs.ch;
        return os;
}
const char& String::front() const
{
  return ch[0];
}
char *String::begin()const
{

        return &ch[0];
}
char *String::end() const
{
        return &ch[strlen(ch) - 1];
}
char& String::operator[](unsigned i)
{
        return ch[i];
}
String String::operator+(const String &rhs)
{
      String vec;
      vec.ch = new char[strlen(ch) + strlen(rhs.ch) +1];
      strcpy(vec.ch,ch);
      strcat(vec.ch,rhs.ch);
      return vec;
}
size_t String::size()const
{
        return strlen(ch);
}
*/

#include<iostream>
#include<algorithm>
#include<utility>
#include<memory>
#include<vector>
#include<cstring>
class String
{
private:
        std::allocator<char> alloc;
        char *elements;
        char *first_free;
        char *cap;
        void free();
        std::pair<char* ,char*> alloc_n_copy(const char*,const char*);
public:
        friend std::ostream & operator<<(std::ostream &os,const String&);
        String();
        char& operator[](unsigned i);
        const char *c_str() const { return elements; }
        String(const char*);
        String(const String&);
        char *begin()const{return elements;}
        char *end() const{return first_free;}
        ~String();
        std::size_t size()const;
        String &operator=(const String&);
};
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
        std::cout <<  "have copy";
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
        std::cout << "have copy";
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
int main()
{
        String a("hjhk");
        String b = a;
        std::cout << b.c_str();


}

