#include<iostream>
#include<cstring>
using namespace std;
#include"CD.h"
void Bravo(const cd &disk);
int main()
{
    cd c1("Beatles", "Capitol", 14, 35.5);
    classic c2 = classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brendel", "Philips", 2, 57.17);
    cd *pcd = &c1;
    cout << "Using object directly:\n";
    c1.Report(); // use Cd method
    c2.Report(); // use Classic method
    cout << "Using type cd * pointer to objects:\n";
    pcd->Report(); // use Cd method for cd object
    pcd = &c2;
    pcd->Report(); // use Classic method for classic object
    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    cout << "Testing assignment: ";
    classic copy;
    copy = c2;
    copy.Report();
}

void Bravo(const cd& disk)
{
        disk.Report();
}
