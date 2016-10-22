#ifndef COMPLEX0_H_INCLUDED
#define COMPLEX0_H_INCLUDED
#include<iostream>
class complex
{
private:
        float realpart;
        float imagepart;
public:
        complex();
        complex(double )
        friend std::istream  & operator >>(std::istream &is,const complex &c);
        friend std::ostream& operator<<(std::ostream &os,const complex &c);

};


#endif // COMPLEX0_H_INCLUDED
