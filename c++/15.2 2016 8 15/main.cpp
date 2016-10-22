/*
#include<iostream>
#include<string>
class Quote
{
public:
        Quote() = default;
        Quote(const std::string &book,double sales_price):bookNo(book),price(sales_price){}
        std::string isbn()const {return bookNo;}
        virtual double net_price(std::size_t n)const
        {
                return n * price;
        }
        virtual ~Quote() = default;
        virtual void debug()const
        {
                std::cout << "ISBN " << bookNo <<" price" <<price;
        }
private:
        std::string bookNo;
protected:
        double price = 0.0;
};
class Bulk_quote:public Quote
{
public:
        Bulk_quote() = default;
        Bulk_quote(const std::string &book,double p,std::size_t qty,double disc):Quote(book,p),min_qty(qty),diconunt(disc){}
        double net_price(std::size_t n)const;
        void debug() const override;
private:
        std::size_t min_qty = 0;
        double diconunt = 0.0;
};
void Bulk_quote::debug()const
{
        std::cout << "ISBN " << isbn() <<price <<min_qty <<diconunt;
}
double Bulk_quote::net_price(std::size_t n)const
{
        if(n > min_qty)
                return n * (1 - diconunt) * price;
        else
                return n * price;
}
double print_total(std::ostream &os,const Quote &item,std::size_t n)
{
        double ret = item.net_price(n);
        os << "ISBN" << item.isbn() <<"#sold:"<<n
        <<"total due:" << ret <<std::endl;
        return ret;
}
class koko:public Quote
{
public:
        koko() = default;
        double net_price(std::size_t n)const
        {
                if(n < min_qty_co)
                        return n * price *(1 - diconunts);
                else
                        return n * price;
        }
        koko(const std::string &book,double p,std::size_t qty,double disc):Quote(book,p),min_qty_co(qty),diconunts(disc){}
private:
        std::size_t min_qty_co = 0;
        double diconunts = 0.0;
};
int main()
{
        Quote a("II --12-23-2",12);
        print_total(std::cout,a,12);
        Bulk_quote b("2014-3-4-5",12,67,0.3);
        print_total(std::cout,b,12);
        b.debug();
}
*/
#include<iostream>
#include<string>
class base
{
private:
        std::string basename;
public:
        base() = default;
        base(const std::string &a):basename(a){}
        std::string name() {return basename;}
        virtual void print(std::ostream &os)
        {
                os << basename;
        }
};
class derived:public base
{
private:
        int i;
public:
        derived() = default;
        derived(const std::string& b, int a):base(b),i(a){}
        void print(std::ostream &os)
        {
                base::print(os);
                os << " "<<i;
        }
};
int main()
{
        derived a("hase",4);
        a.print(std::cout);
}
