#ifndef SCREEN_H_INCLUDED
#define SCREEN_H_INCLUDED
#include<iostream>
#include<string>
class Screen
{
private:
        pos cursor = 0;
        pos height =0,width = 0;
        std::string contents;
public:
        typedef std::string::size_type pos;
        Screen() = default;
        Screen(pos ht ,pos wd, char c): height(ht),width(wd),contents(ht * wd ,c){}
        char get()const{return contents[cursor];}
        inline char get (pos ht,pos wd)const ;
        Screen &move(pos r,pos c);
};
inline Screen &Screen::move(pos r,pos c)
{
        pos row = r * width;
        cursor = row + c;
        return *this;
}
char Screen::get(pos r,pos c)const
{
        pos row = r * width;
}

#endif // SCREEN_H_INCLUDED
