#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::string;
class person
{
private:
        string name;
        string address;
public:
        person() = default;
        person(const string &a,const string&b):name(a),address(b) {}
        string GetName()const{return name;}
        string GetAdd()const {return address;}
        friend std::ostream &print(std::ostream&,const person&);
        friend std::istream &read(std::istream&,const person&);
};
person::person()
{
        name = nullptr;
        address = nullptr;
}

std::ostream &print(std::ostream& os, const person& item)
{
        os<<"姓名"<<item.name<<"      "<<"地址"<<item.address<<endl;
        return os;
}
std::istream &read(std::istream &is,const person &item)
{
        getline(is,item.name);
        getline(is,item.address);
        return is;
}
#endif // PERSON_H_INCLUDED
