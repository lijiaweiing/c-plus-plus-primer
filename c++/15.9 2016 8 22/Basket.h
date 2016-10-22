#ifndef BASKET_H_INCLUDED
#define BASKET_H_INCLUDED
#include<iostream>
#include<memory>
#include<string>
#include<set>
#include<map>
#include<vector>
class Quote
{
private:
        std::string name;
protected:
        double price = 0.0;
public:
        Quote() = default;
        virtual Quote* clone()const &{return new Quote(*this);}
        virtual Quote* clone()&&{return new Quote(std::move(*this));}


        Quote(const std::string &s,double a):name(s),price(a){}
        std::string isbn()const
        {
                return name;
        }
        virtual double net_price(std::size_t i)const
        {
                return i * price;
        }
};
class Dus_Quote:public Quote
{
protected:
        std::size_t amount = 0;
        double discount = 0.0;
public:
        Dus_Quote() = default;
        Dus_Quote(const std::string &s,double a,std::size_t si,double lol):Quote(s,a),amount(si),discount(lol){}
        double net_price(std::size_t i)const = 0;
};
class Bulk_Quote:public Dus_Quote
{
public:
        Bulk_Quote* clone()const &{return new Bulk_Quote(*this);}
        Bulk_Quote* clone()&&{return new Bulk_Quote(std::move(*this));}
        Bulk_Quote() = default;
        Bulk_Quote(const std::string &s,double a,std::size_t si,double lol):Dus_Quote(s,a,si,lol){}
        double net_price(std::size_t i) const override;
};
class Blasket
{public:
        void add_item(const Quote &i)
        {
                item.insert(std::shared_ptr<Quote>(i.clone()));
        }
        void add_item(Quote &&i)
        {
                item.insert(std::shared_ptr<Quote>(std::move(i).clone()));
        }
        double total_recepit(std::ostream &)const;

private:
        static bool compare(const std::shared_ptr<Quote> &a,const std::shared_ptr<Quote> &b)
        {
                return a->isbn() < b->isbn();
        }
        std::multiset<std::shared_ptr<Quote>,decltype(compare)*> item{compare};
};
#endif // BASKET_H_INCLUDED
