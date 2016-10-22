#include<iostream>
#include<cstring>
using namespace std;
#include"CD.h"
void Bravo(const cd &disk);
int main()
{
        cd c1("Beatles","Captionl",14,35.5);
        classic c2 = classic("piaosjd skasl","ALfred Brendel","philips",2,57.17);
        cd *pcd = &c1;
        cout<<"Using object directy:\n";
        c1.Report();
        c2.Report();
        cout<<"Using type cd*pointer to objects:\n";
        pcd->Report();
        pcd = &c2;
        pcd->Report();
        cout<<"Calling a function with a Cd reference arguments:\n";
        Bravo(c1);
        Bravo(c2);
        cout<<"Testing assignments:";


        return 0;
}
void Bravo(const cd& disk)
{
        disk.Report();
}
