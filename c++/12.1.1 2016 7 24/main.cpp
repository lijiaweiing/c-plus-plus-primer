/*#include<memory>
#include<iostream>
#include<list>
#include<string>
int main()
{
        std::shared_ptr<std::string> p1 = std::make_shared<std::string>("");
        if(p1 && p1->empty())
        {
                *p1 = "hi";
        }
        std::cout << *p1;
}
*/
/*#include<memory>
#include<vector>
#include<iostream>
#include<exception>
class StrBlob
{
public:
        typedef std::vector<std::string>::size_type size_type;
        StrBlob();
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
