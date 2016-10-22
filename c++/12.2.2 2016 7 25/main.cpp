#include<iostream>
#include<memory>
#include<string>
int main()
{
        std::allocator<std::string> alloc;
        auto const  p = alloc.allocate(12);
        auto q = p;
        alloc.construct(q++);
        alloc.construct(q++,10,'c');
        std::cout << *p;



}
