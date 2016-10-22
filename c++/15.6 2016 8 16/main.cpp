#include<iostream>
#include<string>
struct Base
{
        Base():mem(0){}
protected:
        int mem;
};
struct Dericed : Base
{
    Dericed(int i):mem(i){}
    int get(){return mem;}
protected:
        int mem;
};
int main()
{
        Dericed d(42);
        std::cout << d.get();
}
