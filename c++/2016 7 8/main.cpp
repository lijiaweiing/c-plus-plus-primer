#include <iostream>
#include<string>
#include<cstring>
#include<vector>
#include<fstream>
using namespace std;
const string pass_word = "123456";

class lesson
{
private:
        string name;
        string college;
        char sex[2];
        int num;

public:
        lesson();
        ~lesson();
        lesson(string a,string b,char c,int d);
        void import();
        void output();

};
lesson::lesson()
{
        name = nullptr;
        college = nullptr;
        sex = nullptr;
        num = 0;
}
lesson::~lesson()
{

}
lesson::lesson(string a,string b,char c,int d)
{
        name = a;
        college = b;
        sex = c;
        num = d;
}
void lesson::import()
{
        cout<<"姓名:";
        cin>>name;
        cout<<"院:";
        cin>>college;
        cout<<"性别:";
        cin>>sex;
        cout<<"学号:";
        cin>>num;
}
void lesson::output()
{
        cout<<
}
int main()
{
        cout<<'\n'<<'\n'<<'\n'<<'\n'
        <<"             欢迎进入教务管理系统"<<'\n'
        <<"                   1学生登录     "<<'\n'
        <<"                   2教师登录     "<<'\n'
        <<"                   3退出系统     "<<'\n';
        int a;
        char amd;
        cin>>a;
        switch(a)
        {
        case 1:
                ;
        case 2:
                cout<<"please import teacher's password";
                cin>>amd;
                if(amd == pass_word)
                        ;
                else



        case 3:
                exit(0);
        }
        return 0;

}
