#include<iostream>
#include<string>
class Employee
{
friend void f(Employee s);
static int  numll;
private:
        std::string name;
        int num;
public:
        Employee()
        {
                num = numll++;
        }
        Employee(const Employee &m)
        {
                name = m.name;
                num = numll++;
        }
        Employee(std::string &a)
        {
                num = numll++;
                name = a;
        }

};
int Employee::numll = 10;

void f(Employee s)
{
        std::cout << s.name << "        "<< s.num <<std::endl;
}
int main()
{
        std::string as("asd");
        Employee x1(as);
        Employee x2 = x1;
        f(x1);
}
