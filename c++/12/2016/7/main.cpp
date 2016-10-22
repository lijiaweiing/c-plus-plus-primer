//7.3.2
/*
#include <iostream>
#include<string>
#include<vector>
using namespace std;
class Screen;
class Window_mgr
{
public:
       typedef std::vector<Screen>::size_type ScreenIndex;
        void clear(ScreenIndex);
        ScreenIndex addScreen(const Screen&);
private:
        vector<Screen> screens;
};
class Screen
{
public:
        typedef std::string::size_type pos;
        pos size()const;
        Screen() = default;
        Screen(pos ht, pos wd):height(ht),width(wd),contents(ht * wd,' '){ }
        Screen(pos ht, pos wd, char c):height(ht),width(wd),contents(ht * wd, c){}
        char get()const{return contents[cursor];}//    隐式内联
        inline char get(pos ht, pos wd) const;
        Screen &move(pos r,pos c);
        Screen  &set(char);
        Screen &set(pos,pos,char);
        Screen &display(std::ostream &os){do_display(os); return *this;}
        const Screen &display(std::ostream &os) const {do_display(os); return *this;}
        friend void Window_mgr::clear(ScreenIndex);
private:
        pos cursor = 0;
        pos height =0;
        pos width = 0;
        std::string contents;
        void do_display(std::ostream &os)const{os<<contents;}
};
Screen::pos Screen::size()const
{
        return height * width;
}
Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen&s)
{
        screens.push_back(s);
        return screens.size() - 1;
}
void Window_mgr::clear(ScreenIndex i)
{
        Screen &s = screens[i];
        s.contents = string(s.height * s.width,' ');
}
inline Screen &Screen::move(pos r,pos c)
{
        pos row = r * width;
        cursor = row + c;
        return *this;
}
char Screen::get(pos ht,pos wd)const
{
        pos row = ht * width;
        return contents[row + wd];
}
inline Screen &Screen::set(char c)
{
        contents[cursor] = c;
        return *this;
}
inline Screen &Screen::set(pos r,pos col, char c)
{
        contents[r*width + col] = c;
        return *this;

}

int main()
{
        Screen my(5,3,'X');
        my.move(4,0).set('#').display(cout);
        cout<<"\n";
        my.display(cout);
        cout<<"\n";
        Screen::pos ht = 10,wd = 10;
        Screen scr(ht,wd,'h');
        scr.move(4,6).set('a');
        Screen *p = &scr;
        char c = scr.get();
        scr.display(cout);
}
*/
/*#include<iostream>
class X
{
public:

        Y *next = nullptr;
};
class Y
{
        X s;
};*/
//7.4.1
#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::string;
typedef double Money;
string bal;
class Account
{
public:
        Money balance {return bal;}//Monkey的类型 为double bal 的类型为double
private:
        Money bal;
};
