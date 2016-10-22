#ifndef BASKET_H_INCLUDED
#define BASKET_H_INCLUDED
#include<iostream>
#include<string>
#include<memory>
#include<set>
class Quote
{
private:
        std::string bookNo;
protected:
        double price = 0.0;
public:
        virtual Quote* clone()const &{return new Quote(*this);}
        virtual Quote* clone()&& {return new Quote(std::move(*this));}
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
        virtual Bulk_quote* clone()const &{return new Bulk_quote(*this);}
        virtual Bulk_quote* clone()&& {return new Bulk_quote(std::move(*this));}
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
class Basket
{
public:
        void add_item(const Quote &sale)
        {
                items.insert(std::shared_ptr<Quote>(sale.clone()));
        }
        void add_item(Quote &&sale)
        {
                items.insert(std::shared_ptr<Quote>(std::move(sale).clone()));
        }
        double total_receipt(std::ostream &)const;

private:
        static bool compare(const std::shared_ptr<Quote> &lhs,const std::shared_ptr<Quote> &rhs)
        {
                return lhs->isbn() < rhs->isbn();
        }
        std::multiset<std::shared_ptr<Quote>,decltype(compare)*> items {compare};
};

#endif // BASKET_H_INCLUDED
