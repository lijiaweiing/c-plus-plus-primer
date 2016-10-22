#include <iostream>
#include<string>
using namespace std;
class Screen
{
public:
        typedef std::string::size_type pos;
        Screen() = default;
        Screen(pos ht, pos wd):height(ht),width(wd),contents(ht * wd,' '){ }
        Screen(pos ht, pos wd, char c):height(ht),width(wd),contents(ht * wd, c){}
        char get()const{return contents[cursor];}//    隐式内联
        inline char get(pos ht, pos wd) const;
        Screen move(pos r,pos c);
        Screen  set(char);
        Screen set(pos,pos,char);
        Screen display(std::ostream &os){do_display(os); return *this;}
        const Screen display(std::ostream &os) const {do_display(os); return *this;}
private:
        pos cursor = 0;
        pos height =0;
        pos width = 0;
        std::string contents;
        void do_display(std::ostream &os)const{os<<contents;}
};
inline Screen Screen::move(pos r,pos c)
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
inline Screen Screen::set(char c)
{
        contents[cursor] = c;
        return *this;
}
inline Screen Screen::set(pos r,pos col, char c)
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
}
