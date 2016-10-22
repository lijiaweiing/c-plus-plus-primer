#ifndef CD_H_INCLUDED
#define CD_H_INCLUDED
#include<cmath>
#include<iostream>
#include<cstring>
class cd
{
private:
        char performers[50];
        char label[20];
        int selections;
        double playtime;
public:
        cd(char* s1,char *s2,int n,double x);
        cd(const cd &d);
        virtual ~cd();
        virtual void Report()const;
        cd &operator = (const cd& d);


};
class classic:public cd
{
        char contents[30];
public:

        virtual void Report()const;
        classic(char *s1,char *s2,char *s3,int n,double x);
        classic(const cd& d,char *s3);

};
cd::cd(char* s1,char *s2,int n,double x)
{
    strncpy(performers,s1,49);
    performers[49] = '\0';
    strncpy(label,s2,19);
    label[19] = '\0';
    selections = n;
    playtime = x;

}
cd::cd(const cd &d)
{
        strncpy(performers,d.performers,49);
        performers[49] = '\0';
       strncpy(label,d.label,19);
        label[19] = '\0';
        selections = d.selections;
        playtime = d.playtime;

}
cd::~cd()
{
}
void cd::Report()const
{
        cout<<"performers:"<<performers<<std::endl;
        cout<<"label:"<<label<<std::endl;
        cout<<"selections:"<<selections<<std::endl;
        cout<<"playtime:"<<playtime<<std::endl;

}
cd &cd::operator=(const cd &d)
{
        if(this == &d)
                return *this;
         strncpy(performers,d.performers,49);
        performers[49] = '\0';
        strncpy(label,d.label,19);
        label[19] = '\0';
        selections = d.selections;
        playtime = d.playtime;
        return *this;

}
classic::classic(char *s1,char *s2,char *s3,int n,double x):cd(s1,s2,n,x)
{
        strncpy(contents,s3,29);
        contents[29] = '\0';

}
classic::classic(const cd& d,char *s3):cd(d)
{
        strncpy(contents,s3,29);
        contents[29] = '\0';
}
void classic::Report()const
{
        cd::Report();
        cout<<"contens"<<contents<<std::endl;

}




#endif // CD_H_INCLUDED
