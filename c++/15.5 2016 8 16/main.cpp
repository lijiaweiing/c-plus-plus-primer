#include<iostream>
#include<string>
class Base
{
public:
        void pub_mem();
private:
        char priv_men;
protected:
        int prot_mem;
};
struct Pub_Derv:public Base
{
        int f(){return prot_mem;}//真确：派生类能访问protected成员
        char g(){return priv_men；}//错误: private 成员对于派生类来说是不可访问的
};
struct Priv_Derk:private Base
{
        int f() const {return prot_mem;}//private 不影响类的访问权限
};
