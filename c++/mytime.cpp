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
total=coding+fixing;
cout<<"coding + fixing=";
total.show();
cout<<endl;
return 0;}
