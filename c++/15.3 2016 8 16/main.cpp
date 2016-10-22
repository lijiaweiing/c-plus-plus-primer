/*#include<iostream>
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
/*class Bulk_quote:public Quote
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
class Dics_quote:public Quote
{
public:
        Dics_quote() = default;
        Dics_quote(const std::string &book,double price,std::size_t qty ,double dics):Quote(book,price),quantity(qty),discount(dics){}
        double net_price(std::size_t )const = 0;
protected:
        std::size_t quantity = 0;
        double discount = 0.0;
};
class Bulk_quote:public Dics_quote
{public:
        Bulk_quote() = default;
        Bulk_quote(const std::string &book,double price,std::size_t qty,double dics):Dics_quote(book,price,qty,dics){}
        double net_price(std::size_t )const override;
};
double Bulk_quote::net_price(std::size_t i)const
{
        if(i > quantity)
                return (i - quantity)*price + quantity *(1 - discount) *price;
        else
                return i * (1 - discount) *price;
}
int main()
{
        Bulk_quote a("12334",13,10,0.1);
        print_total(std::cout, a,12);
        Dics_quote("asd",12,3,0.5);
}
