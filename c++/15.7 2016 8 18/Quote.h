#ifndef QUOTE_H_INCLUDED
#define QUOTE_H_INCLUDED
#include<iostream>
#include<string>
class Quote
{
private:
        std::string bookNo;
protected:
        double price = 0.0;
public:
        Quote() = default;
        Quote(const std::string &book,double sales_price):bookNo(book),price(sales_price){}
        std::string isbn()const {return bookNo;}
        virtual double net_price(std::size_t i)const
        {
                return i * price;
        }
        virtual ~Quote() = default;
};
class Bulk_quote:public Quote
{
private:
        std::size_t min_qty = 0;
        double discount = 0.0;
public:
        Bulk_quote() = default;
        Bulk_quote(const std::string &book,double sales,std::size_t t,double k):Quote(book,sales),min_qty(t),discount(k){}
        double net_price(std::size_t i)
        {
                if( i >= min_qty)
                        return i * (1- discount) * price;
                else
                        return i * price;
        }
};

#endif // QUOTE_H_INCLUDED
