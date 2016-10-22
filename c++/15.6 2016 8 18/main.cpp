/*#include<iostream>
class Base
{
public:
        virtual int fcn()
        {
                std::cout <<"haha";
        }
};
class D1:public Base
{
public:
        int fcn(int a)
        {
                std::cout << a <<"D1";
        }
        virtual void f2()
        {
                std::cout << "hello";
        }
};
class D2:public D1
{
public:
        int fcn(int a)
        {
                std::cout << a <<"D2";
        }
        int fcn()
        {
                std::cout << "D2 fcn";
        }
        void f2()
        {
                std::cout << "f2()";
        }
};
int main()
{
        D2 d2obj;
        Base *p1 = &d2obj;
        D1 *p2 = &d2obj;
        D2 *p3 = &d2obj;
        p2->fcn(42);
        p3->fcn(42);

}
*/
#include<iostream>
class Base
{
public:
        virtual int fcn()
        {
                std::cout << "Base";
        }
};
class D1:public Base
{
public:
        int fcn() override
        {
                std::cout << "D1";
        }
        virtual void f2()
        {
                std::cout << "f2";
        }
};
int main()
{
        Base bobj;
        D1 Dobj;
        Base *p1 = &bobj;
        Base *p2 = &Dobj;
        p1->fcn();
        p2->fcn();
}
