#ifndef CD_H_INCLUDED
#define CD_H_INCLUDED
#include<cstring>
#include<iostream>
using std::cout;
using std::endl;
using std::cin;
class cd
{
private:
        char *performers;
        char *label;
        int selections;
        double playtime;
public:
        cd(const char *s1,const char *s2,int n=0,double x=0.0);
        cd(const cd & d);

        virtual ~cd();
        void Report()const;
        cd &operator=(const cd &d);
};
class classic:public cd
{
        char *contents;
public:
        ~classic();
       classic &operator =(const classic &d);
       classic(const char *s3,const classic &d);
       classic(const classic &d);
        classic(const char *s1="" ,const char *s2="" ,const char *s3="" ,int n = 0,double x = 0.0);
       virtual void Report()const;
};
cd::cd(const char *s1,const char *s2,int n,double x)
{
        performers = new char[strlen(s1)+1];
        strcpy(performers,s1);
        label = new char[strlen(s2)+1];
        strcpy(label,s2);
        selections = n;
        playtime = x;
}
cd::cd(const cd& d)
{
         performers = new char[strlen(d.performers)+1];
        strcpy(performers,d.performers);
        label = new char[strlen(d.label)+1];
        strcpy(label,d.label);
        selections = d.selections;
        playtime = d.playtime;
}
cd::~cd()
{
        delete []performers;
        delete []label;
}
cd & cd::operator=(const cd& d)
{
        if(&d == this)
                return *this;
        delete []performers;
        delete []label;
         performers = new char[strlen(d.performers)+1];
        strcpy(performers,d.performers);
        label = new char[strlen(d.label)+1];
        strcpy(label,d.label);
        selections = d.selections;
        playtime = d.playtime;
        return *this;
}
void cd::Report()const
{
        cout<<"performers:"<<performers;
        cout<<"lable:"<<label;
        cout<<"seletions:"<<selections;
        cout<<"playtime"<<playtime;

}
classic::classic(const char *s1,const char *s2,const char *s3,int n,double x):cd(s1,s2,n,x)
{
        contents = new char[strlen(s3)+1];
        strcpy(contents,s3);
}
classic::~classic()
{
        delete []contents;
}
classic::classic(const char*s3,const classic &d):cd(d)
{
        contents = new char[strlen(s3)+1];
        strcpy(contents,s3);

}
classic::classic(const classic & d):cd(d)
{
     contents = new char[strlen(d.contents)+1];
     strcpy(contents,d.contents);
}
classic &classic::operator=(const classic& d)
{
        if(&d == this)
                return *this;
        cd::operator=(d);
        contents = new char[strlen(d.contents)+1];
        strcpy(contents,d.contents);
        return *this;
}
void classic::Report()const
{
        cd::Report();
        cout<<"constents:"<<contents<<endl;
}
#endif // CD_H_INCLUDED
