#ifndef STOCK1_H_INCLUDED
#define STOCK1_H_INCLUDED
class stock
{
private:
        char company[30];
        int shares;
        double share_val;
        double total_val;
        void set_tot(){total_val = shares*share_val;}
public:
        stock();
        stock(const char*co,int n=0,double pr=0.0);
        ~stock();
        void buy(int num,double price);
        void sell(int num,double price);
        void update(double price);
        void show();
};


#endif // STOCK1_H_INCLUDED
