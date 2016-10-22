#ifndef PLORG_H_INCLUDED
#define PLORG_H_INCLUDED
class Plorg
{
private:
        char name[15];
        int CI;
public:
        Plorg();
        Plorg(int n,const char* co);
        void show()const;
        void modify(int n);
};



#endif // PLORG_H_INCLUDED
