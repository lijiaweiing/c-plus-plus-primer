#include<iostream>
#include<string>
char s(char);
int main()
{       using namespace std;
        char s;
        cout<<"Please enter one of the following"<<endl;
        cout<<"c)carnivore      p)pianist";
        cout<<endl;
        cout<<"t)tree   g)game";
        cout<<endl;
        cin>>s;




       char s(s);



return 0;

}
char s(char s)
{
         switch(s)
        {
                case 'c':cout<<"a maple is a carnivore";break;
                case 'p':cout<<"a maple is a pianist";break;
                case 't':cout<<"a maple is a tree";break;
                case 'g':cout<<"a maple is a game";break;

        }
}
