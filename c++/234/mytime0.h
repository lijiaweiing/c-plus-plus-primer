#ifndef MYTIME0_H_INCLUDED
#define MYTIME0_H_INCLUDED
class Time
{
private:
        int hours;
        int minutes;
public:
        Time();
        Time(int h,int m=0);
        void AddMin(int m);
        void AddHr(int h);
        void Reset(int h=0,int m=0);
        Time sum(const Time& t)const;
        void Show()const;

};


#endif // MYTIME0_H_INCLUDED
