#ifndef DEBUGDELETE_H_INCLUDED
#define DEBUGDELETE_H_INCLUDED
#include<iostream>
class DequgDelete
{
private:
        std::ostream &os;
public:
        DequgDelete(std::ostream &s = std::cerr):os(s){}
        template<typename T> void operator()(T* p)
        {
                os << "deleting unique_ptr" <<std::endl;
                delete p;
        }
};


#endif // DEBUGDELETE_H_INCLUDED
