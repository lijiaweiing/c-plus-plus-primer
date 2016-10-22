
#include <iostream>
#include <string>
using namespace std;
class Cd
{
private:
char performers[50];
char label[20];
int selections;
double playtime;
public:
Cd(char *s1, char *s2, int n, double x);
Cd(const Cd &d);
Cd(){}
virtual ~Cd();
virtual void Report()const;
Cd &operator=(const Cd &d);
};
class Classic :public Cd
{
private:
char main_music[50];
public:
Classic(){}
Classic(char *m, char *s1, char *s2, int n, double x);
Classic(char *m, const Cd &c);
~Classic();
Classic &operator=(const Classic &c);
virtual void Report()const;
};


Cd::Cd(char *s1, char *s2, int n, double x)
{
strcpy(performers, strlen(s1) + 1, s1);
strcpy(label, strlen(s2) + 1, s2);
selections = n;
playtime = x;
}
Cd::Cd(const Cd &d)
{
strcpy_s(performers, 50, d.performers);
strcpy_s(label, 20, d.label);
selections = d.selections;
playtime = d.playtime;
}
Cd::~Cd()
{ }
void Cd::Report()const
{
cout << "Performers: " << performers << endl;
cout << "Label: " << label << endl;
cout << "Selections: " << selections << endl;
cout << "Playtime: " << playtime << endl;
}
Cd &Cd::operator=(const Cd &d)
{
if (this == &d)
return *this;
strcpy_s(performers, 50, d.performers);
strcpy_s(label, 20, d.label);
selections = d.selections;
playtime = d.playtime;
return *this;
}
Classic::Classic(char *m, char *s1, char *s2, int n, double x) :Cd(s1, s2, n,
x)
{
strcpy_s(main_music, strlen(m) + 1, m);
}
Classic::Classic(char *m, const Cd &c) : Cd(c)
{
strcpy_s(main_music, strlen(m) + 1, m);
}
Classic::~Classic()
{ }
Classic &Classic::operator=(const Classic &c)
{
if (this == &c)
return *this;
Cd::operator=(c);
strcpy_s(main_music, 50, c.main_music);
return *this;
}
void Classic::Report()const
{
Cd::Report();
cout << "Main Music: " << main_music << endl;
}

void Bravo(const Cd &disk);
int main()
{
Cd c1("Beatles", "Capito", 14, 35.5);
Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C",
"Alfred Brendel", "Philips", 2, 57.17);
Cd *pcd = &c1;
cout << "Using object directly:\n";
c1.Report();
c2.Report();
cout << "Using type cd * pointer to objects:\n";
pcd->Report();
pcd = &c2;
pcd->Report();
cout << "Calling a function with a Cd reference argument:\n";
Bravo(c1);
Bravo(c2);
cout << "Testing assignment: ";
Classic copy;
copy = c2;
copy.Report();
system("pause");
return 0;
}
void Bravo(const Cd &disk)
{
disk.Report();
}
