/*#include<iostream>
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
*/
//4.13 arrstruc.cpp
/*#include<iostream>
struct inflatable
{
        char name[20];
        float volume;
        double price;
};
int main()
{
        using namespace std;
        inflatable guests[2]=
        {
                {"Bambi",0.5,21.99},
                {"Godzilla",2000,565.99}




        };
        cout<<"The guests "<<guests[0].name<<" and "<<guests[1].name<<endl;
        return 0;
}
*/
//4.15 pointer
/*#include<iostream>
#include<cstring>
#include<string>
int main()
{
        using namespace std;
        cout<<"Enter words(to stop, type the word done):";
        string x;int i=0;
        cin>>x;
        while( x!="done")
        {
                ++i;
                cin>>x;

        };
        cout<<i;
        return 0;
}*/
//p147 9
/*#include<iostream>
int main()
{
        using namespace std;
        cout<<"Enter number of rows:";
        int s;
        cin>>s;

        for(int x=1;x<=s;x++)
        {
                int j=0;int l=0;
                while(j<s-x)
                {
                        cout<<".";
                        j++;
                }
                while(l<x)
                {
                        cout<<"*";
                        l++;

                }

                cout<<endl;
        }
        return 0;
}*/
//6.1
/*#include<iostream>

int main()
{
        using namespace std;
        char ch;
        int spaces=0;
        int total=0;
        cin.get(ch);
        while(ch!='.')
        {
                if(ch==' ')
               {++spaces;}

        ++total;
        cin.get(ch);}
        cout<<spaces<<"spaces,"<<total;
        cout<<"character total in sentence\n";
        return 0;


}*/
//6.2
/*#include<iostream>
int main()
{
        using namespace std;
        char ch;
        cout<<"Type,and I shall repeat.\n";
        cin.get(ch);
        while(ch!='.')
        {
                if(ch=='\n')

                        cout<<ch;
                else
                        cout<<ch+1;
                cin.get(ch);
        }
        cout<<"\nPlease excume the sight confusion";
        return 0;


}*/
//6.8
/*#include<iostream>
#include<cctype>
int main()
{
        using namespace std;
        cout<<"Enter text for analysis,and type @"
        " to terminate input.\n";
        char ch;
        int whitespace=0;
        int digits=0;
        int chars=0;
        int puncts=0;
        int othes=0;
        cin.get(ch);
        while(ch!='@')
        {
                if(isalpha(ch))
                        chars++;
                else if(isspace(ch))
                        whitespace++;
                else if(isdigit(ch))
                        digits++;
                else if(ispunct(ch))
                        puncts++;
                else
                        othes++;
                cin.get(ch);

        }
        cout<<chars<<"letters,"<<whitespace<<" whitespace,"<<digits<<"digists,"
        <<puncts<<"puncts,"<<othes<<"other.\n";
        return 0;
}
*/
//6.7
/*#include<iostream>
#include<fstream>
int main()
{
        using namespace std;
        char automobile[50];
        int year;
        double a_price;
        double d_price;
        ofstream outFile;
        outFile.open("carinfo.txt");
        cout<<"Enter the make and model of automobile:";
        cin.getline(automobile,50);
        cout<<"Enter the model year:";
        cin>>year;
        cout<<"Enter the original asking price:";
        cin>>a_price;
        d_price=0.913*a_price;
        cout<<fixed;
        cout.precision(2);
        cout.setf(ios_base::showpoint);
        cout<<"Make and model:"<<automobile<<endl;
        cout<<"Year:"<<year<<endl;
        cout<<"Was asking $"<<a_price<<endl;
        cout<<"Was asking $"<<d_price<<endl;
        outFile<<fixed;
        outFile.precision(2);
        outFile.setf(ios_base::showpoint);
        outFile<<"Make and model:"<<automobile<<endl;
        outFile<<"Year:"<<year<<endl;
        outFile<<"Was asking $"<<a_price<<endl;
        outFile<<"Now asking $"<<d_price<<endl;
        outFile.close();
        return 0;
}*/
/*#include<iostream>
#include<cctype>
int main()
{
        using namespace std;
        char ch;
        cin.get(ch);
        while(ch!='@')
        {
                if(islower(ch))
                {
                        ch=toupper(ch);
                        cout<<ch;

                }
                else
                {
                        ch=tolower(ch);
                        cout<<ch;
                }


                cin.get(ch);

        }
        cout<<ch;

        return 0;
}*/
/*#include<iostream>
int main()
{
        using namespace std;
     char ch;
        while(ch=='c'||ch=='p'||ch=='t'||ch=='g')
       {

                cout<<"Please enter one of the following choices:"<<endl;
        cout<<"c)carnivore      p)pianit"<<endl;
        cout<<"t)tree           g)game"<<endl;

        cout<<"Please enter a,c,p,t,or g:";
        cin>>ch;

        switch(ch)
        {
                case'c':cout<<"a maple is a carnivore";
                        break;
                case 'p':cout<<"a maple is a piant";
                         break;
                case't':cout<<"a maple is a tree";
                        break;
                case'g':cout<<"a maple is a game";
                        break;
                default:cout<<"Please enter a,c,p,t,or g:";

        }
          cin>>ch;
       }
        return 0;

}
*/
//7.5
/*#include<iostream>
const int ArSize=8;
int sum_arr(int arr[],int n);
int main()
{
        using namespace std;
        int cookied[ArSize]={1,2,4,8,16,32,64,128};

        int sum=sum_arr(cookied,ArSize);
        cout<<"Total cookies eaten:"<<sum<<"\n";
        return 0;
}
int sum_arr(int arr[],int n)
{
        int total=0;
        for(int i=0;i<n;i++)
        {
                total=total+arr[i];
        }
        return total;
}
*/
/*#include<iostream>
int main()
{
        using namespace std;
        int money;
        int w;
        cin>>money;
        while(money>0)
        {
                switch(money)
                {
                        case money<=5000:w=0;cout<<w;break;
                        case money<=35000:w=(money-5000)*10%;cout<<w;break;

                }
                cin>>money

        }
        return 0;
}
*/
/*#include<iostream>
const int ArSize=8;
int sum_arr(int arr[],int n);
int main()
{
        int cookies[ArSize]={1,2,4,8,16,32,64,128};
        std::cout<<cookies<<"=array address,";
        std::cout<<sizeof cookies<<"sizeof cookes\n";
        int sum=sum_arr(cookies,ArSize);
        std::cout<<"Total cookies eaten:"<<sum<<std::endl;
        sum=sum_arr(cookies,3);
        std::cout<<"First three eaten ate "<<sum<<"cookies.\n";
        sum=sum_arr(cookies+4,4);
        std::cout<<"Last four eaters ate"<<sum<<"cookies.\n";
        return 0;

}
int sum_arr(int arr[],int n)
{
        int total=0;
        std::cout<<arr<<"=arr,";
        std::cout<<sizeof arr<<"=sizeof arr\n";
        for(int i=0;i<n;i++)
        {
                total=total+arr[i];
        }
        return total;
}
*/
/*#include<iostream>
const int Max=5;
int fill_array(double arr[],int limit);
void show_array(const double arr[],int n);
void revalue(double r,double arr[],int n);
int main()
{
        using namespace std;
        double properties[Max];
        int size=fill_array(properties,Max);
        show_array(properties,size);
        cout<<"Enter revaluation factor:";
        double factor;
        cin>>factor;
        revalue(factor,properties,size);
        show_array(properties,size);
        cout<<"Done.\n";
        return 0;
}
int fill_array(double arr[],int limit)
{
        using namespace std;
        double temp;
        int i;
        for(i=0;i<limit;i++)
        {
                cout<<"Enter value#"<<(i+1)<<":";
                cin>>temp;
                if(!cin)
                {
                        cin.clear();
                        while(cin.get()!='\n')
                                continue;
                      cout<<"Bad input;input process terminated.\n";
                      break;

                }
                else if(temp<0)
                        break;
                arr[i]=temp;
        }
        return i;
}
void show_array(const double arr[],int n)
{
        using namespace std;
        for(int i=0;i<n;i++)
        {
                cout<<"Property #"<<(i+1)<<":$";
                cout<<arr[i]<<endl;

        }
}
void revalue(double r,double arr[],int n)
{
        for(int i=0;i<n;i++)
        {
                arr[i]*=r;
        }
}
*/
//7.8
/*#include<iostream>
const int ArSize=8;
int sum_arr(const int* begin,const int* end );
int main()
{
        using namespace std;
        int cookies[ArSize]={1,2,4,8,16,32,64,128};
        int sum=sum_arr(cookies,cookies+ArSize);
        cout<<"Total cookies eaten:"<<sum<<endl;
        sum=sum_arr(cookies,cookies+3);
        cout<<"First three eaten ate "<<sum<<"cookies .\n";
        sum=sum_arr(cookies+4,cookies+8);
        cout<<"Last four eaters ate "<<sum<<"cookies.\n";
        return 0;
}
int sum_arr(const int* begin,const int *end)
{
        const int *pt;
        int total=0;
        for(pt=begin;pt!=end;pt++)
        {
                total=total+*pt;

        }
        return total;
}
*/
/*#include<iostream>
int main()
{
        using namespace std;
       const float g_earth=9.80;
      const float *pe=&g_earth;
       cout<<*pe;
}
*/
/*#include<iostream>
using namespace std;
void showmenu();
void weup();
int main()
{        showmenu();
        char w;
        cin>>w;
        while(w!='c'&& w!='p' && w!='t'&&w!='q')
        {
           cout<<"Please enter a,c,p,t,or q:";
           cin>>w;
        }







                switch(w)
                {
                        case 'c':weup();
                                cout<<"carnivore"<<endl;
                                break;
                        case 'p':weup();
                                cout<<"pianist"<<endl;
                                break;
                        case 't':weup();
                                        cout<<"tree"<<endl;
                                        break;
                        case 'q':weup();
                                cout<<"game"<<endl;break;
                        default:cout<<"Please enter a,c,p,t,or q:";
                }




        return 0;



}
void showmenu()
{
        cout<<"Please enter one of the following choice:";
        cout<<"c)carnivore      p)pianist"<<endl;
        cout<<"t)tree           g)gme"<<endl;

}
void weup()
{
        cout<<"a maple is a ";
}
*/
//
/*#include<iostream>
const int strsize=20;
struct bop{
        char fullname[strsize];
        char tiltle[strsize];
        char bopname[strsize];
        int preference;};
const bop member[5]=
{

}
*/
//strgfun.cpp
/*#include<iostream>
int c_in_str(const char *str,char ch);
int main()
{
        using namespace std;
        char mmm[15]="minimum";
        char*wail="ululate";
        int ms=c_in_str(mmm,'m');
        int us=c_in_str(wail,'u');
        cout<<ms<<"m character in "<<mmm<<endl;
        cout<<us<<"u character in "<<wail<<endl;
        return 0;

}
int c_in_str(const char*str,char ch)
{
        int count=0;
        while(*str)
        {
                if(*str==ch)
                        count++;
                str++;
        }
        return count;
}
*/
/*#include<iostream>
char *buildstr(char c,int n);
int main()
{
        using namespace std;
        int times;
        char ch;
        cout<<"Enter an character :";
        cin>>ch;
        cout<<"Enter an integer:";
        cin>>times;
        char *ps=buildstr(ch,times);
        cout<<ps<<endl;
        delete []ps;
        ps=buildstr('+',20);
        cout<<ps<<"-DONE-"<<ps<<endl;
        delete []ps;
        return 0;


}
char *buildstr(char c,int n)
{
        char*pstr=new char[n+1];
        pstr[n]='\0';
        while(n-->0)
                pstr[n]=c;
        return pstr;
}
*/
/*
#include<iostream>
struct travel_time
{
        int hours;
        int mins;
};
const int Mins_per_hr=60;
travel_time sum(travel_time t1,travel_time t2);
void show_time(travel_time t);
int main()
{
        using namespace std;
        travel_time day1={5,45};
        travel_time day2={4,45};
        travel_time trip=sum(day1,day2);
        cout<<"Two-day total:";
        show_time(trip);
        travel_time day3={4,32};
        cout<<"Three-day total:";
        show_time(sum(trip,day3));
        return 0;

}
travel_time sum(travel_time t1,travel_time t2)
{
        travel_time total;
        total.mins=(t1.mins+t2.mins)%Mins_per_hr;
        total.hours=t1.hours+t2.hours+total.mins;
        return total;
}
void show_time(travel_time t)
{
        using namespace std;
        cout<<t.hours<<"hours,"<<t.mins<<"minutes\n";

}
*/
//7.12
/*#include<iostream>
#include<cmath>
struct polar
{
        double distance;
        double angle;

};
struct rect
{
        double x;
        double y;
};
polar rect_to_polar(rect xypos);
void show_polar(polar dapos);
int main()
{
        using namespace std;
        rect rplace;
        polar pplace;
        cout<<"ENter the x and y vluaes:";
        while(cin>>rplace.x>>rplace.y)
        {
                pplace=rect_to_polar(rplace);
                show_polar(pplace);
                cout<<"Next two number (q to quit)";

        }
        cout<<"Done.\n";
        return 0;

}
polar rect_to_polar(rect xypos)
{
        using namespace std;
        polar answer;
        answer.distance=sqrt(xypos.x*xypos.x+xypos.y*xypos.y);
        answer.angle=atan2(xypos.y,xypos.x);
        return answer;
}
void show_polar(polar dapos)
{
        using namespace std;
        const double Rad_to_deg=57.2957795;
        cout<<"distance="<<dapos.distance;
        cout<<",angle"<<dapos.angle*Rad_to_deg;
        cout<<"degrees\n";
}
*/
//strctptr.cpp
/*
#include<iostream>
#include<cmath>
struct polar
{
        double distance;
        double angle;

};
struct rect
{
        double x;
        double y;

};
void recct_to_polar(const rect*pxy,polar *pda);
void show_polar(const polar* pda);
int main()
{
        using namespace std;
        rect rplace;
        polar pplace;
        cout<<"Enter the x and y values:";
        while(cin>>rplace.x>>rplace.y)
        {
                recct_to_polar(&rplace,&pplace);
                show_polar(&pplace);
                cout<<"Next two number(q to quit):";


        }
        cout<<"Done.\n";
        return 0;
}
void show_polar(const polar *pda)
{
        using namespace std;
        const double Rad_to_deg=57.29577951;
        cout<<"distance="<<pda->distance;
        cout<<"angle="<<pda->angle*Rad_to_deg;
        cout<<"degress\n";

}
void recct_to_polar(const rect*pxy,polar *pda)
{
        using namespace std;
        pda->distance=sqrt(pxy->x*pxy->x+pxy->y*pxy->y);
        pda->angle=atan2(pxy->y,pxy->x);

}
*/
//topfive.cpp
/*#include<iostream>
#include<string>
using namespace std;
const int SIZE=5;
void display(const string sa[],int n);
int main()
{
        string list[SIZE];
        cout<<"Enter your "<<SIZE<<" favorite astronomical sight:\n";
        for(int i=0;i<SIZE;i++)
        {
                cout<<i+1<<":";
                getline(cin,list[i]);

        }
        cout<<"your list:\n";
        display(list,SIZE);
        return 0;
}
void display(const string sa[],int n)
{
        for(int i=0;i<n;i++)
                cout<<i+1<<":"<<sa[i]<<endl;
}
*/
//recur.cpp
/*#include<iostream>
const int Len=66;
const int Divs=6;
void subdivide(char ar[],int low,int high,int level);
int  mian()
{
        char ruler[Len];
        int i;
        for(i=1;i<Len-2;i++)
                ruler[i]=' ';
        ruler[Len-1]='\0';
        int max=Len-2;
        int min=0;
        ruler[min]=ruler[max]='|';
        std::cout<<ruler<<std::endl;
        for(i=1;i<=Divs;i++)
        {
                subdivide(ruler,min,max,i);
                std::cout<<ruler<<std::endl;
                for(int j=1;j<Len-2;j++)
                        ruler[j]=' ';
        }
        return 0;
}
void subdivide(char ar[],int low,int high,int level)
{
        if(level==0)
                return ;
        int mid=(high+low)/2;
        ar[mid]='|';
        subdivide(ar,low,mid,level-1);
        subdivide(ar,mid,high,level-1);
}
*/
/*#include<iostream>
double betsy(int);
double pam(int);
void estimate(int lines,double(*pf)(int));
int main()
{
        using namespace std;
        int code;
        cout<<"How many lines of code do you need?";
        cin>>code;
        cout<<"Here's Betsy estimate:\n";
        estimate(code,betsy);
        cout<<"Here's pam's estimate:\n";
        estimate(code,pam);
        return 0;
}
double betsy(int lns)
{
        return 0.05*lns;
}
double pam(int lns)
{
        return 0.03*lns+0.0004*lns*lns;
}
void estimate(int lines,double (*pf)(int))
{
      using namespace std;
      cout<<lines<<"lines will take";
      cout<<(*pf)(lines)<<"hour(s)\n";
}
*/
/*#include<iostream>
#include<string>
struct juanxian
{
        std::string name;
        double money;
};
const int Arsize=4;
int main()
{
        using namespace std;

        juanxian *ps=new juanxian[Arsize];

       for(int i=0;i<Arsize;++i)
       {

         cout<<"第"<<i+1<<"捐献人姓名:";
         getline(cin,ps[i].name);
         cout<<"第"<<i+1<<"捐献数额:";
         cin>>ps[i].money;
         cin.get();



       }
       int temp=0;
       cout<<"Grand Patrons:\n";
       for(int j=0;j<Arsize;++j)
       {
               if(ps[j].money>10000)
               {
                       cout<<ps[j].name<<endl;
                        temp++;
               }
       }
       if(temp==0)
       {
               cout<<"none\n";
       }

       int lop=0;
       cout<<"Patrons:"<<endl;
       for(int l=0;l<Arsize;++l)
       {
               if(ps[l].money<=10000)
               {
                       cout<<ps[l].name<<endl;
                       lop++;
               }
       }
       if(lop==0)
       {
               cout<<"none\n";
       }
       return 0;

*/
/*#include<iostream>
#include<string>
#include<fstream>
struct juanxian
{
        std::string name;
        double money;
};
const int Arsize=4;
int main()
{
        using namespace std;

        juanxian *ps=new juanxian[Arsize];
        ofstream outFile;
        outFile.open("carinfo.txt");

       for(int i=0;i<Arsize;++i)
       {

         cout<<"第"<<i+1<<"捐献人姓名:";
         getline(cin,ps[i].name);
         cout<<"第"<<i+1<<"捐献数额:";
         cin>>ps[i].money;
         cin.get();
       }
       for(int j;j<Arsize;++j)
       {
               outFile<<ps[j].name<<endl;
               outFile<<ps[j].money<<endl;
       }




       outFile.close();
       delete []ps;
       return 0;

}
*/
/*#include<iostream>
#include<string>
#include<cctype>>
int main()
{
        char *pt=new char;
        using namespace std;
        int vowels=0;
        int consonants=0;
        int others=0;
        char ch;
        cout<<"Enter word(q to quit):";
        cin.get(ch);
        while(ch!='q')
        {
                if(isalpha())

        }


}
*/
/*#include<iostream>

double hf(double,double);
int main()
{
        using namespace std;
        double x,y;
        cin>>x>>y;
        while(x!=0 &&y!=0)
        {
                double th=hf(x,y);
                cout<<"调和平均数为"<<th<<endl;
                cout<<"请输入:";
                cin>>x>>y;
        }
        return 0;
}
double hf(double x,double y)
{
        double h;
        h=2.0*x*y/(x+y);
        return h;
}
*/
/*#include<iostream>
int X(int n);
int main()
{
        using namespace std;
        int temp;
        cin>>temp;
        while(temp>0)
        {
            cout<<X(temp)<<endl;
            cin>>temp;
        }
        return 0;
}
int X(int n)
{       using namespace std;
              double f;
     if(n<=1)
     {
             f=1;
     }
     else
                f=X(n-1)*n;
     return f;
}
*/
/*#include<iostream>
#include<cctype>
int fill_array(double arr[],int limit);
void show_array(const double arr[],int limit);
void Rever_array(double arr[],int limit);
const int Arsize=10;
int main()
{
        using namespace std;
        double pro[Arsize];
        int size=fill_array(pro,Arsize);
        show_array(pro,size);
        Rever_array(pro,size);
        return 0;


}
int fill_array(double arr[],int limit)
{
        using namespace std;
        double temp;
        int i;
        for(i=0;i<limit;i++)
        {
                cout<<"Enter value#"<<i+1<<":";
                cin>>temp;
                if(!cin)
                {
                        cin.clear();
                        while(cin.get()!='\n')
                                continue;
                        cout<<"Bad input;input process terminated.\n";
                        break;
                }
                else if(temp<0)
                        break;
                arr[i]=temp;
        }
        return i;
}
void show_array(const double arr[],int limit)
{
        using namespace std;
        for(int i=0;i<limit;i++)
        {
                cout<<"第"<<i+1<<":"<<arr[i]<<endl;
        }
}
void   Rever_array(double arr[],int limit)
{
        double temp;
        for(int i=1;i<(limit/2);i++)
        {
                temp=arr[i];
                arr[i]=arr[limit-i-1];
                arr[limit-i-1]=temp;

        }
        show_array(arr,limit);
}
*/
/*#include<iostream>
inline double square(double x){return x*x;}
int main()
{
        using namespace std;
        double a,b;
        double c=13.0;
        a=square(5.0);
        b=square(4.5+7.5);
        cout<<"a="<<a<<"b="<<b<<"\n";
        cout<<"c="<<c;
        cout<<",c square="<<square(c++)<<"\n";
        cout<<"Now c="<<c<<"\n";
        return 0;

}*/
/*#include<iostream>
int main()
{
        using namespace std;
        int rats=101;
        int &rodents=rats;
        cout<<"rats="<<rats;

}
*/
/*#include <iostream>
#include <cctype>
#include<cstring>

int main()
{
    using namespace std;

    int vowel=0,consonant=0,other=0;
    char word[15];

    cout<<"Enter words (q to quit):\n";
    while(cin>>word)
    {
          if(isalpha(word[0]))
          {
              if(word[0]=='q'&& strlen(word)==1)
              break;
              else if(word[0]=='a'||word[0]=='i'||
              word[0]=='u'||word[0]=='e'||word[0]=='o')
              ++vowel;
              else
              ++consonant;
           }
           else
           ++other;
    }

    cout<<vowel<<" words beginning with vowels\n";
    cout<<consonant<<" words beginning with consonants\n";
    cout<<other<<" others\n";
    return 0;
}
*/
/*#include<iostream>
const double Subtraction(const double,const double);
 const double add(const double,const double);
void calculate( const double,const  double,const  double(*pf)(const double,const double));
int main()
{
        using namespace std;
        double x,y;
        char symbol;
       while(cin>>x>>symbol>>y)
        {
                switch(symbol)
                {
                        case '+':calculate(x,y,add);break;
                        case '-':calculate(x,y,Subtraction);break;
                        default:break;
                }
        }


        return 0;
}
const double add(const double x,const double y)
{
        return x+y;
}
void  calculate(const double k,const double z,const double(*pf)(const double,const double))
{
        using namespace std;
        cout<<"calculate is:";
        cout<<(*pf)(k,z)<<endl;
}
const double Subtraction(const double x,const double y)
{
        return x-y;
}
*/
/*#include<iostream>
#include<cctype>
#include<cstring>
int main()
{
        using namespace std;
        char word[15];
        cout<<"Enter word (q to quit):\n";
        int other=0;
        int vowels=0;
        int consonants=0;
        while(cin>>word)
        {
                if(isalpha(word[0]))
                {
                        if(word[0]=='q' && strlen(word)==1)
                                break;
                        else if(word[0]=='a'||word[0]=='e'||word[0]=='i'||word[0]=='o'||word[0]=='u')
                                ++consonants;
                                else
                                        vowels++;

                }
                else
                        other++;

        }
        cout<<vowels<<" word beginning with vowels\n";
        cout<<consonants<<" word beginning with consonants\n";
        cout<<other<<" other";
        return 0;
}
*/
/*#include<iostream>
using namespace std;
struct person
{
        char name[10];
        double money;
};
int main()
{
        person *ps=new person [5];
        for(int i=0;i<5;i++)
        {
                cout<<"Enter value#:"<<i+1<<":"<<endl;
                cout<<"name:";
                cin.get(ps[i].name,10);
                cin.get();
                cout<<"money:";
                cin>>ps[i].money;
                cin.get();
        }
        int temp=0;
        cout<<"Grand Patrons\n";
        for(int i=0;i<5;i++)
        {
                if(ps[i].money>=10000)
                {
                        cout<<ps[i].name<<endl;
                        ++temp;

                }


        }
        if(temp==0)
        {
                cout<<"none\n";
        }

}
*/
//strtref.cpp
/*#include<iostream>
using namespace std;
struct sysop
{
        char name[26];
        char qoute[64];
        int used;
};
const sysop& use (sysop &sysopref);
int main()
{
        sysop looper=
        {
                "Rick\"Fortran\"Looper",
                "I'm a goto kind of guy",
                0
        };
        use(looper);
        cout<<"Looper :"<<looper.used<<"use(s)\n";
        sysop copycat;
        copycat=use(looper);
        cout<<"Copyat:"<<copycat.used<<"used(s)\n";
        cout<<"Looper:"<<looper.used<<"used(s)\n";
        cout<<"use(looper):"<<use(looper).used<<"use(s)\n";
        return 0;
}
const sysop & use(sysop &sysopref)
{
        cout<<sysopref.name<<"say:\n";
        cout<<sysopref.qoute<<"\n";
        sysopref.used++;
        return sysopref;

}
*/
//strquote.cpp
/*#include<iostream>
#include<cstring>
class stock
{
private:
        char company[30];
        int shares;
        double share_val;
        double total_val;
        void set_tot(){total_val=shares*share_val;}
public:
        void acquire(const char*co,int n,double pr);
        void buy(int num,double price);
        void sell(int num,double price);
        void update(double price);
        void show();

};
void stock::acquire(const char *co,int n,double pr)
{
        std::strncpy(company,co,29);
        company[29]='\n';
        if(n<0)
        {
                std::cerr<<"Number of shares can't be negative."
                <<company<<"shares set to 0.\n";
                shares=0;
        }
        else
                shares=n;
        shares=n;
        share_val=pr;
         set_tot();
}
void stock::buy(int num,double price)
{
        if(num<0)
        {
                std::cerr<<"Number of shares purchared cant's be negative."
                <<"Transaction is aborted.\n";

        }
        else
        {
                shares+=num;
                share_val=price;
                set_tot();
        }
}
void stock::sell(int num ,double price )
{

        using std::cerr;
        if(num<0)
        {
                std::cerr<<"Number of shares purchared cant's be negative."
                <<"Transaction is aborted.\n";
        }
        else if(num>shares)
        {
                cerr<<"you can't sell more than you have!"
                <<"Transaction is aborted.\n";

        }
        else
        {
                shares-=num;
                share_val=price;
                set_tot();
        }

}
void stock::update(double price)
{
        share_val=price;
        set_tot();
}
void stock::show()
{
        using std::cout;
        using std::endl;
        cout<<"company :"<<company
        <<"shares :"<<shares<<endl
        <<"share Price:$"<<share_val
        <<"Total Worth:$"<<total_val<<endl;
}
int main()
{
        using namespace std;
        using std::ios_base;
        stock stock1;
        stock1.acquire("NanoSmart",20,12.50);
        cout.setf(ios_base::fixed);
        cout.precision(2);
        stock1.show();
        stock1.buy(15,18.25);
        stock1.show();
        stock1.sell(400,20.00);
        stock1.show();
        return 0;
}
*/
/*
#include"stock1.h";
#include<iostream>
#include<cstring>
stock::stock()
{
        std::cout<<"Default constructor called\n";
        std::strcpy(company,"no name");
        shares =0;
        share_val=0.0;
        total_val=0.0;

}
stock::stock(const char* co, int n,double pr)
{
        std::cout<<"Constructor using "<<co<<"called\n";
        std::strncpy(company,co,29);
        company[29]='\0';
        if(n<0)
        {
                std::cerr<<"Number of shares can't be negative;"
                <<company<<" shares set to 0.\n";

        }
        else
                shares=n;
        share_val=pr;
        set_tot();
}
void stock::buy(int num,double price)
{
        if(num<0)
        {
                std::cerr<<"Number of shares purchared cant's be negative."
                <<"Transaction is aborted.\n";

        }
        else
        {
                shares+=num;
                share_val=price;
                set_tot();
        }
}
void stock::sell(int num ,double price )
{

        using std::cerr;
        if(num<0)
        {
                std::cerr<<"Number of shares purchared cant's be negative."
                <<"Transaction is aborted.\n";
        }
        else if(num>shares)
        {
                cerr<<"you can't sell more than you have!"
                <<"Transaction is aborted.\n";

        }
        else
        {
                shares-=num;
                share_val=price;
                set_tot();
        }

}
void stock::update(double price)
{
        share_val=price;
        set_tot();
}
void stock::show()
{
        using std::cout;
        using std::endl;
        cout<<"company :"<<company
        <<"shares :"<<shares<<endl
        <<"share Price:$"<<share_val
        <<"Total Worth:$"<<total_val<<endl;
}
stock::~stock()
{
        std::cout<<",Bey, "<<company<<"!\n";
}
int main()
{
        using namespace std;
        using std::ios_base;
        stock stock1("NanoSmart",20,12.50);
        cout.setf(ios_base::fixed);
        cout.precision(2);
        stock1.show();
        stock1.buy(15,18.25);
        stock1.show();
        stock1.sell(400,20.00);
        stock1.show();
        return 0;
}
*/
/*
#include<iostream>
#include"stock2.h"
#include<cstring>
stock::stock()
{
        std::cout<<"Default constructor called\n";
        std::strcpy(company,"no name");
        shares =0;
        share_val=0.0;
        total_val=0.0;

}
stock::stock(const char* co, int n,double pr)
{

        std::strncpy(company,co,29);
        company[29]='\0';
        if(n<0)
        {
                std::cerr<<"Number of shares can't be negative;"
                <<company<<" shares set to 0.\n";

        }
        else
                shares=n;
        share_val=pr;
        set_tot();
}
void stock::buy(int num,double price)
{
        if(num<0)
        {
                std::cerr<<"Number of shares purchared cant's be negative."
                <<"Transaction is aborted.\n";

        }
        else
        {
                shares+=num;
                share_val=price;
                set_tot();
        }
}
void stock::sell(int num ,double price )
{

        using std::cerr;
        if(num<0)
        {
                std::cerr<<"Number of shares purchared cant's be negative."
                <<"Transaction is aborted.\n";
        }
        else if(num>shares)
        {
                cerr<<"you can't sell more than you have!"
                <<"Transaction is aborted.\n";

        }
        else
        {
                shares-=num;
                share_val=price;
                set_tot();
        }

}
void stock::update(double price)
{
        share_val=price;
        set_tot();
}
void stock::show()const
{
        using std::cout;
        using std::endl;
        cout<<"company :"<<company
        <<"shares :"<<shares<<endl
        <<"share Price:$"<<share_val
        <<"Total Worth:$"<<total_val<<endl;
}
const stock &stock::topval(const stock& s)const
{
        if(s.total_val>total_val)
                return s;
        else
                return *this;
}
const int size=4;
int main()
{
        using std::cout;
        using std::ios_base;
        stock stocks[size]=
        {
                stock("Nanosmart",12,20.0),
                stock("Boffo Objects",200,2.0),
                stock("Monolithic Obe",130,13.4),
                stock("Fleep",60,6.5)
        };
        cout.precision(2);
        cout.setf(ios_base::fixed,ios_base::floatfield);
        cout.setf(ios_base::showbase);
        cout<<"stock holdings:\n";
        int st;
        for(st = 0;st<size;st++)
                stocks[st].show();
        stock top=stocks[0];
        for(st=1;st<size;st++)
                top=top.topval(stocks[st]);
        cout<<"\nMost valueable holding :\n";
        top.show();
        return 0;
}
*/
/*
#include<iostream>
#include<cstring>
#include"Plorg.h"
Plorg::Plorg()
{
        std::strcpy(name,"Plorga");
        CI=0;
}
Plorg::Plorg(int n,const char* ps)
{
        std::strcpy(name,ps);
        CI=n;

}
void Plorg::show()const
{
        using namespace std;
        cout<<"Plorg's name:"<<name<<"\n";
        cout<<"Plorg's number:"<<CI<<"\n";

}
void Plorg::modify(int n)
{
        CI=n;
}

int main()
{
        using std::cout;
        using std::endl;
        Plorg s1(2,"ji ji");
        s1.show();
        return 0;


}
*/

#include<iostream>
#include<cstring>
class time
{
private:
	int hours;
	int minutes;
public:
	time();
	time(int h,int m=0);
	void AddMin(int m);
	void AddHr(int h);
	void Reset(int h=0,int m=0);
	time operator+(const time &t)const;
	void show()const;
};
time::time()
{
hours=minutes=0;
}
time::time(int h,int m)
{
hours=h;
minutes=m;
}
void time::AddMin(int m)
{
minutes+=m;
hours+=minutes/60;
minutes%=60;
}
void time::AddHr(int h)
{
hours+=h;
}
void time::Reset(int h,int m)
{
hours=h;
minutes=m;
}
time time::operator+(const time &t)const
{
time sum;
sum.minutes=minutes+t.minutes;
sum.hours=t.hours+sum.minutes/60;
sum.minutes%=60;
return sum;
}
void time::show()const
{std::cout<<hours<<"hours,"<<minutes<<"minutes";
}
int main()
{
using std::cout;
using std::endl;
time planning;
time coding(2,40);
time fixing(5,55);
time total;
cout<<"planning time=";
planning.show();
cout<<endl;
cout<<"coding time:";
fixing .show();
cout<<endl;

total=coding+fixing;
cout<<"coding + fixing=";
total.show();
cout<<endl;
return 0;}

/*
#include<iostream>
#include<cmath>
#include"vect.h"
#include<stdlib.h>
using std::sin;
using std::cos;
using std::atan2;
using std::cout;


        const double Rad_to_deg=57.295;
       void Vector::set_mag()
       {
               mag=sqrt(x*x,y*y);
       }
       void Vector::set_any()
       {
               if(x==0.0&&y==0.0)
                age=0.0;
                else
                        any=atan2(y,x);

       }
       void Vector::set_x()
       {
               x=mag*cos(any);
       }
       void Vector::set_y()
        {
                y=mag*sin(any);

        }
        Vector::Vector()
        {
                x=y=mag=any=0.0;
        }
        Vector::Vector(double n1,double n2,char form)
        {
                mode=form;
                if(form=='r')
                {
                        x=n1;
                        y=n2;
                        set_mag();
                        set_any();
                }
                else if(form=='p')
                {
                        mag=n1;
                        any=n2;
                        set_x();
                        set_y();

                }
                else
                {
                        cout<<"Incorrect 3rd argument to vector()--";
                        cout<<"vector set to 0\n";
                        x=y=mag=any=0.0;
                        mode='r';
                }
        }
        void Vector::set(double n1,double n2,char form)
        {
                mode=form;
                if(form=='r')
                {
                        x=n1;
                        y=n2;
                        set_mag();
                        set_any();
                }
                else if(form=='p')
                {
                        mag=n1;
                        any=n2;
                        set_x();
                        set_y();

                }
                else
                {
                        cout<<"Incorrect 3rd argument to vector()--";
                        cout<<"vector set to 0\n";
                        x=y=mag=any=0.0;
                        mode='r';
                }

        }
        Vector::~Vector()
        {

        }
        void Vector::polar_made()
        {
                mode='p';
        }
        void Vector::rect_mode()
        {
                mode='r';
        }
        Vector Vector::operator+(const Vector&b)const
        {
                return Vector(x+b.x,y+b.y);
        }
        Vector Vector::operator-(const Vector&b)const
        {
                return Vector(x-b.x,y-b.y);
        }
        Vector Vector::operator-(double n)const
        {
                return Vector(-x,-y);
        }
        Vector Vector::operator*(double n)const
        {
                return a*n;
        }
        std::ostream &operator<<(std::ostream &os,const Vector &v)
        {
                if(v.mode=='r')
                {
                        os<<"(x,y)=("<<v.x<<","<<v.y<<")";
                }
                else if(v.mode=='p')
                {
                        os<<"(m,a)=("<<v.mag<<","<<v.any*Rad_to_deg<<")";
                }
                else
                {
                        os<<"Vector object mode is invalid";

                }
                return os;

        }
int main()
{
        using namespace std;
        strand(time(0));
        double direction;
        Vector step;
        Vector result(0.0,0.0);
        unsigned long steps=0;
        double target;
        double dstep;
        cout<<"Enter target distance(q to quit):";
        while(cin>>target)
        {

        }

}
*/
/*
#include<iostream>
using std::cout;
#include"stone.h"
Stonewe::Stonewe(double lbs)
{
        stone=int(lbs)/Lbs_per_stn;
        pds_left=int(lbs)%Lbs_per_stn+lbs-int(lbs);
        pounds=lbs;

}
Stonewe::Stonewe(int stn,double lbs)
{
        stone=stn;
        pds_left=lbs;
        pounds=stn*
}
*/
