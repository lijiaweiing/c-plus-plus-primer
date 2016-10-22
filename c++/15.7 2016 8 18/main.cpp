#include<iostream>
#include<vector>
#include"Quote.h"
#include<memory>
/*int main()
{
        std::vector<Quote> basket;
        double sum = 0;
        basket.push_back(Bulk_quote("2011",50,3,0.9));
        basket.push_back(Bulk_quote("2022",40,4,0.9));
        basket.push_back(Bulk_quote("2023",56,6,0.8));
        for(auto i : basket)
        {
                int lol ;
                std::cin>> lol;
                sum += i.net_price(lol);
        }
        std::cout<< sum;
}
*/
int main()
{
        std::vector<std::shared_ptr<Quote>> basket;
        double sum = 0;
        basket.push_back(std::make_shared<Bulk_quote>("2011",50,3,0.9));
        basket.push_back(std::make_shared<Bulk_quote>("2022",40,4,0.9));
        basket.push_back(std::make_shared<Bulk_quote>("2023",56,6,0.8));
        for(auto i : basket)
        {
                int lol ;
                std::cin>> lol;
                sum += i->net_price(lol);
        }
        std::cout<< sum;
}
