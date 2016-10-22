#include<iostream>
#include"Basket.h"
double print_total(std::ostream &os,const Quote &item,std::size_t n)
{
        double ret = item.net_price(n);
        os << "ISBN:" << item.isbn()
        << "# sold:" << n << "total due" <<ret <<std::endl;
        return ret;
}
double Basket::total_receipt(std::ostream &os)const
{
        double sum = 0.0;
        for(auto iter = items.cbegin();iter != items.cend();iter = items.upper_bound(*iter))
        {
                sum+= print_total(os,**iter,items.count(*iter));
        }
        os << "Total Sale: " << sum << std::endl;
        return sum;
}
int main()
{
        Basket ask;
        ask.add_item(Bulk_quote("0-201-54848-8",50,10,0.5));
        ask.total_receipt(std::cout);
}

