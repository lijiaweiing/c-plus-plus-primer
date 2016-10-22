/*#include<iostream>
const int Cities=5;
const int Years=4;

int main()
{
        using namespace std;
        const char *cities[Cities]=
        {
                "crisdds jio",
                "huashduahushduhahs",
                "jaisdjoias",
                "laskdlkal",
                "asjdoqwii"
        };
        int maxtemps[Years][Cities]=
        {
                {95,99,86,199,104},
                {97,89,98,106,102},
                {96,100,940,107,105},
                {97,102,89,108,104},

        };
	cout<<"Maxium temperatures for 2002-2005\n\n";
	for(int city=0;city<cities;++city)
        {
                cout<<cities[city]<<":\n";
                for(int year=0;year<Years;++year)
                        cout<<maxtemps[year][city]<<"\t";
                cout<<endl;
        }
        return 0;
}*/

/*#include<iostream>
int main()
{
        using namespace std;
        int x,y;
        int z=0;
        cout<<"please enter x:";
        cin>>x;
        cout<<"please enter y:";
        cin>>y;
        while(x!=(y+1))
        {
                z=z+x+y;
                x++;//p5,9 1
                y--;

        }
        cout<<"z:"<<z;
        return 0;
}*/
//not.cpp--using the not operator
/*#include<iostream>
#include<climits>
bool is_int(double);
int main()
{
        using namespace std;
        double num;
        cout<<"Yo,dude!Enter an integer value:";
        cin>>num;
        while(!is_int(num))
        {
                cout<<"Out of range --please try again";
                cin>>num;
        }
        int val=int(num);
        cout<<"You've enter the integer "<<val<<"\nBye\n";
        return 0;
}
bool is_int(double x)
{
        if(x<=INT_MAX && x>=INT_MIN)
                return true;
        else
                return false;
}*/
//limite.cpp--some integer limits
/*#include<iostream>
#include<climits>
int main()
{
        using namespace std;
        int n_int=INT_MAX;
        int n_short=INT_MIN;
        cout<<n_int;
        cout<<endl;
        cout<<n_short;
        return 0;
}
*/
//cctypes.cpp--using the ctype.h library
/*#include<iostream>
#include<cctype>
int main()
{
        using namespace std;
        cout<<"Enter text for analysic,and type @"
        "to terminate inpute.\n";
        char ch;
        int whitespace=0;
        int digits=0;
        int chars=0;
        int puncts=0;
        int others=0;
        cin.get(ch);
        while(ch!='@')
        {
                if(isalpha(ch))
                        chars++;
                else if(isspace(ch))
                {
                        whitespace++;
                }
                else if(isdigit(ch))
                        puncts++;
                else
                        others++;
                cin.get(ch);

        }
        cout<<chars<<"leters,"
        <<whitespace<<"whitespace"<<
        digits<<"digits,"<<puncts<<"punctuations,"
        <<others<<"others.\n";
        return 0;
}*/
//condits.cpp--using the condition operator
/*#include<iostream>
int main()
{
        using namespace std;
        int  a,b;
        cout<<"Enter two integers:";
        cin>>a>>b;
        cout<<"The large of "<<a<<"and"<<b;
        int c=a>b?a:b;//c=aif a>b elsse c=b
        cout<<" is "<<c<<endl;
        return 0;


}*/
//switch.cpp
/*#include<iostream>
using namespace std;
void showmenu();
void report();
void comfort();
int main()
{
        showmenu();
        int choice;
        cin>>choice;
        while(choice!=5)
        {
                switch(choice)
                {
                        case 1:cout<<"\a\n";
                                break;
                        case 2:report();break;
                        case 3:cout<<"The boss was in all day.\n";break;
                        case 4:comfort();break;
                        default:cout<<"That's not a choice";


                }
                showmenu();
                cin>>choice;
        }
        cout<<"Bye!\n";
        return 0;
}
void showmenu()
{
        cout<<"Please enter 1,2,3,4,or5:\n"
        "1)alarm        2)report\n"
        "3)alibi        4)comfort\n"
        "5)quit\n";
}
void report()
{
        cout<<"It's been an excellent week for business.\n"
        "salses are up 120%.Expenses are down 35%.\n";

}
void comfort()
{
        cout<<"YOUr employeesthink you the finest CEO\n"
        "in the industry.The board of directors thinks\n"
        "you are the finest ceo inr the industry.\n";

}
*/
//p146 5.9 n2.cpp
/*#include<iostream>
int main()
{
        using namespace std;
        int x,y=0;
        cout<<"please enter:";
        cin>>x;
        while(x!=0)
        {
                y=y+x;
                cout<<"please enter:";
                cin>>x;
        }
        cout<<y;
        return 0;

}*/
//p146 5.9 n3.cpp
/*#include<iostream>
int main()
{       using namespace std;
        int daphne,cleo=100;
        int x;

        for(x=1;cleo<=daphne;x++)
        {
                daphne=100*0.1*x+100;
                cleo=cleo*0.05*x+cleo;

        }
        cout<<"x="<<x;
        return 0;

}
*/

//p146 5.9 n4.cpp
/*#include<iostream>
const int Month;
char*month[Month]={"January", "February", "March", "April",
                          "May", "June", "July", "August", "September",
                           "October", "November", "December"};
int main()
{using namespace std;
int month;
int sale;
cout<<"please enter thec++for fools ";
for(month=0;;month++)
{

}

}*/
//p147 5.6
/*#include<iostream>
struct car
{char sc[20];int ns;};
int main()
{
        using namespace std;
        int x,i;
        cout<<"How many cars do you wish to catalog";
        cin>>x;
        while(cin.get()!='\n');

        car * ps=new car[x];
        for(i=1;i<=x;i++)
        {
                cout<<"Car #"<<i<<endl;
                cout<<"Please enter the make:";
                cin.get(ps[i].sc,20);
                cout<<"Please enter the year made:";
                cin>>ps[i].ns;
                while(cin.get()!='\n');
        }
        cout<<"Here is your collection"<<endl;
	for(i=1;i<=x;i++)
                {cout<<ps[i].sc<<"      "<<ps[i].ns<<endl;}
        delete []ps;
        return 0;
}*/
/*#include <iostream>
struct car { char name[20]; int year;};
int main(void)
{
   using namespace std;
    int n;
    cout << "How many cars do you wish to catalog?: ";
    cin >> n;
    while(cin.get() != '\n')    // get rid of rest of line
        ;
    car * pc = new car [n];
    int i;
    for (i = 0; i < n; i++)
    {
        cout << "Car #" << (i + 1) << ":\n";
        cout << "Please enter the make: ";
        cin.getline(pc[i].name,20);
        cout << "Please enter the year made: ";
        cin >> pc[i].year;
        while(cin.get() != '\n')    // get rid of rest of line
            ;
    }
    cout << "Here is your collection:\n";
    for (i = 0; i < n; i++)
        cout << pc[i].year << " " << pc[i].name << "\n";
    delete [] pc;
    return 0;
}
*/
//enum.cpp --using enum
/*#include<iostream>
enum{red,organe,yellow,green,blue,violent,indigo};
int main()
{
        using namespace std;
        cout<<"Enter color code(0~6)";
        int code;
        cin>>code;
        while(code<=indigo&&code>=red)
        {
                switch(code)
                {
                        case red:cout<<"Her lips were red.\n";break;
                        case organe:cout<<"Enter hail was organge.\n";break;
                        case yellow:cout<<"Enter shose were yellow.\n";break;
                        case green:cout<<"Here nails were  green.\n";break;
                        case blue: cout<<"Here sweatsuit was blue.\n";break;
                        case violent:cout<<"here eye were violent.\n";break;
                        case indigo:cout<<"Here mood was indigo.\n";break;

                }
                cout<<"Enter color code(0~6):";
                cin>>code;
        }
        cout<<"Bye\n";
        return 0;
}*/
/*#include<iostream>
#include<string>
int main()
{       using namespace std;
        string sh;int count=0;
       cin>>sh;


                while(sh!="done")
                {
                       ++count;
                       cin>>sh;


                }
         cout<<count;
         return 0;
}*/
//p147 5.9
/*#include<iostream>
int main()
{
        using namespace std;
        int x,i; int j,k;


        cout<<"Enter number of rows:";
        cin>>x;
        for(i=1;i<=x;i++)
        {

               for(j=1;j<=x-i;j++)
               {
                       cout<<".";

               }
               for(k=1;k<=i;k++)
               {
                       cout<<"*";
               }
              cout<<endl;

        }
        return 0;
}*/
//outfile.cpp--writing to a file3
#include<iostream>
#include<iostream>
#include<fstream>
/*int main()
{
        using namespace std;
        char automobile[50];
        int year;
        double a_price;
        double b_price;
        ofstream outfile;
        outfile.open("carinfo.txt");
        cout<<"Enter the make and model of automobile:";
        cin.getline(automobile,50);
        cout<<"Enter the model year:";
        cin>>year;
        cout<<"Enter the original asking price:";
        cin>>a_price;
        b_price=0.913*a_price;
        cout<<fixed;
        cout.precision(2);
        cout.setf(ios_base::showpoint);
        cout<<"Make and model:"<<automobile<<endl;
        cout<<"Year:"<<year<<endl;
        cout<<"Was asking $"<<a_price<<endl;
        cout<<"Now asking $"<<b_price<<endl;
        outfile<<fixed;
        outfile.precision(2);
        outfile.setf(ios_base::showpoint);
        outfile<<"Make and model:"<<automobile<<endl;
        outfile<<"Year:"<<year<<endl;
        outfile<<"Was asking $"<<a_price<<endl;
        outfile<<"Now asking $"<<b_price<<endl;
        outfile.close();
        return 0;

}
*/
//sumafile.cpp--function with an array argyment
/*#include<iostream>
#include<fstream>
#include<cstdlib>
const int size=60;
int main()
{
        using namespace std;
        char filename[size];
        ifstream infile;
        cout<<"Enter name of data file:";
        cin.getline(filename,size);
        infile.open(filename);
        if(!infile.is_open())
        {
                cout<<"Could not open the file"<<filename<<endl;
                cout<<"Program terminating.\n";
                exit(EXIT_FAILURE);
        }
        double value;
        double sum=0.0;
        int count=0;
        infile>>value;
        while(infile.good())
        {
                ++count;
                sum +=value;
                infile>>value;

        }
        if(infile.eof())
                cout<<"End of file reached.\n";
        else if(infile.fail())
        {
                cout<<"Input terminated by data mismath.\n";

        }
        else
                cout<<"INput terminated for unknow reson.\n";
        if(count==0)
        {
                cout<<"NO data processed.\n";

        }
        else
        {

                cout<<"Items read :"<<count<<endl;
                cout<<"sum:"<<sum<<endl;
                cout<<"Average:"<<sum/count<<endl;
        }
        infile.close();
        return 0;
}
*/
//p180 611 1
/*#include<iostream>
#include<cctype>
#include<cstring>
#include<string>
int main()
{
        using namespace std;
        cout<<"Please cout:";
        char ch;
        cin.get(ch);


        while(ch!='@')
        {
          if(!isdigit(ch))
          {
                  if(islower(ch))
                  {
                          ch=toupper(ch);
                  }
                  else if(isupper(ch))
                  {
                          ch=tolower(ch);
                  }
                  cout<<ch;

          }
           cin.get(ch);
        }

        return 0;

}
*/
//6.11 p3
/*#include<iostream>
#include<cctype>
static int i=10;
int main()
{
        using namespace std;
        int r=0;
        int j;
        double k[r];
        double volume=0;
        cin>>k[r];
        while(isdigit(k[r])&&r<i)
        {
                r++;
                cin>>k[r];


        }
        for(j=0;j<r;j++)
        {
            volume=volume+k[j];

        }
        volume=volume/j;
        cout<<volume;

}
*/

/*#include<iostream>
#include<cctype>
int main()
{
        using namespace std;
        double donation[10];
        int count=0;
        double sum=0;
        int i,j;
       for(i=0;i<10;i++)
       {
               if(cin>>donation[i])
               {
                       sum+=donation[i];
               }
               else break;
       }
       sum/=i;
       for(j=0;j<10;j++)
       {
               if(donation[j]>sum)
               {
                 ++count;
               }
               else break;
       }
       cout<<sum;
       cout<<endl;
       cout<<count;
       return 0;
}
*/
/*#include<iostream>
#include<string>
int main()
{       using namespace std;
        char s;
        cout<<"Please enter one of the following";
        cout<<"c)carnivore      p)pianist";
        cout<<endl;
        cout<<"t)tree   g)game";
        cout<<endl;
        cin>>s;

        switch(s)
        {
                case 'c':cout<<"a maple is a carnivore";break;
                case 'p':cout<<"a maple is a pianist";break;
                case 't':cout<<"a maple is a tree";break;
                case 'g':cout<<"a maple is a game";break;
                default:cout<<"please enter a,c,p,t,or g:";

        }
        cin>>s;





        switch(s)
        {
                case 'c':cout<<"a maple is a carnivore";break;
                case 'p':cout<<"a maple is a pianist";break;
                case 't':cout<<"a maple is a tree";break;
                case 'g':cout<<"a maple is a game";break;
        }
}
}
*/
/*#include<iostream>
int main()
{
        using namespace std;
        cout<<"Come up and c++ me some time";
        return 0;
}
*/
/*#include<iostream>
int main()
{
        using namespace std;
        int yams[3];
        yams[0]=7;
        yams[1]=8;
        yams[2]=6;
        int yamcosts[3]={20,30,5};
        cout<<"Total yams=";
        cout<<yams[0]+yams[1]+yams[2]<<endl;
        cout<<"The package whith"<<yams[1]<<" yams costs";
        cout<<yamcosts[1]<<"cents per yam.\n";
        int total=yams[0]*yamcosts[0]+yams[1]*yamcosts[1];
        total=total+yams[2]*yamcosts[2];
        cout<<"The Total yam express  is "<<total<<"cents.\n";
        cout<<"\nsize of yams array="<<sizeof yams;
        cout<<"bytes.\n";
        cout<<"Size of one element ="<<sizeof yams[0];
        return 0;
}*/
/*#include<iostream>
int main()

{
        using namespace std;
        string gu;
        char ls;
        char ks;int age;
        cout<<"WHat is your first name?";
        getline(cin,gu);
        cout<<"what is your last name?";
        cin>>ls;
        cin.get();

        cout<<"WHat letter grade do you deserve?";
        cin>>ks;
        cin.get();
        cout<<"what is your age?";
        cin>>age;
        cin.get();
        cout<<"name:"<<ls<<","<<gu<<endl;
        cout<<"Grade:"<<ks<<endl;
        cout<<"Age:"<<age<<endl;

        return 0;
}
*/
/*#include<iostream>
int main()
{
        using namespace std;
        string name;
        string dessert;
        cout<<"Enter your name:\n";
        getline(cin,name);
        cout<<"Enter your  farvorite dessert:\n";
        getline(cin,dessert);
        cout<<"I have somne delicious"<<dessert;
        cout<<"for you,"<<name<<".\n";
        return 0;

}
*/
/*
#include<iostream>

using namespace std;
const int Arsize = 16;
int main()
{
        int i;
        double factorials[Arsize];
        factorials[1]=factorials[0]=1.0;
        for(i=2;i<Arsize;i++)
                factorials[i]=i*factorials[i-1];
        for(i=0;i<Arsize;i++)
                cout<<i<<"!="<<factorials[i]<<endl;
        return 0;

}
*/
/*#include<iostream>
int main()
{
        using namespace std;
        cout<<"Enter an integer:";
        int by;
        cin>>by;
        cout<<"Counting by "<<by<<"s:\n";
        for(int i=0;i<100;i=i+by)
                cout<<i<<endl;
        return 0;
}
*/
/*#include<iostream>
int main()
{
        using namespace std;
        int a=20;
        int b=20;
        cout<<"a        ="<<a<<":       b="<<b<<"\n";
        cout<<"a++"<<a++<<": ++b "<< ++b<<"\n";
        cout<<"a        ="<<a<<":   b="<<b<<"\n";
        return 0;
}
*/
/*#include<iostream>
#include<cstring>
int main()
{
        using namespace std;
        cout<<"Enter a word";
        string word;
        cin>>word;
        char temp;
        int i,j;
        for(j=0,i=word.size()-1;j<i;--i,++j)
        {
                temp=word[i];
                word[i]=word[j];
                word[j]=temp;
        }
        cout<<word<<endl;
        return 0;
}*/
/*
#include<iostream>
void cheers(int);
double cube(double x);
int main()
{
        using namespace std;
        cheers(5);
        cout<<"Give me a number ;";
        double side;
        cin>>side;
        double volume=cube(side);
        cout<<"A"<<side<<"-foot cube has a volume of";
        cout<<volume<<" cubic feet.\n";
        cheers(cube(2));
        return 0;
}
void cheers(int n)
{
        using namespace std;
        for(int i=0;i<n;i++)
                cout<<"Cheers !";
        cout<<endl;

}
double cube(double x)
{
        return x*x*x;

}*/
/*#include<iostream>
using namespace std;
void n_chars(char,int);
int main()
{
        int times;
        char ch;
        cout<<"Enter an character:";
        cin>>ch;
        while(ch!='q')
        {
                cout<<"Enter an integer ";
                cin>>times;
                n_chars(ch,times);
                cout<<"\nEnjter another character or press the "
                "q-key to quit:";
                cin>>ch;
        }
        cout<<"The value of times is "<<times<<".\n";
        cout<<"Bye\n";
        return 0;
}
void n_chars(char c,int n)
{
        while(n-- >0)
                cout<<c;

}
*/
/*#include<iostream>
int main()
{
        using namespace std;
        int x,y;
        int pj;
        int n=0;
        cout<<"PLease Enter x,y:";
        cin>>x;
        cin>>y;
        while(x!=0 or y!=0)
        {
          pj=2*x*y/(x+y);
          n++;
          cout<<"第"<<n<<"的调和平均数="<<pj<<endl;
          cout<<"PLease Enter x,y:";
        cin>>x;
        cin>>y;

        }
        return 0;
}
*/

/*#include<iostream>
void countdown(int n);
int main()
{
        countdown(5);
        return 0;

}
void countdown(int n)
{
        using namespace std;
        cout<<"Counting down..."<<n<<"(n at "<<&n<<")"<<endl;
        if(n>0)
        {
                countdown(n-1);
        }
        cout<<n<<":Kaboom!"<<"       (n at"<<&n<<")"<<endl;
}
*/
//4.12
struct inflatable
{
        char name[20];
        float volume;
        double price;

};
int main()
{
        using namespace std;
        inflatable bouquet=
        {
                "sunflower",
                0.2,
                12.49
        };
        inflatable choice;
        cout<<"bouquet"<<bouquet.name<<"for $";
        cout<<bouquet.price<<endl;
        choice=bouquet;
        cout<<"choice:"<<choice.name<<" for $";
        cout<<choice.price<<endl;
        return 0;
}





