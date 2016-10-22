#ifndef STOCK2_H_INCLUDED
#define STOCK2_H_INCLUDED
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

        void buy(int num,double price);
        void sell(int num,double price);
        void update(double price);
        void show()const;
        const stock& topval(const stock & s)const;

};


#endif // STOCK2_H_INCLUDED
