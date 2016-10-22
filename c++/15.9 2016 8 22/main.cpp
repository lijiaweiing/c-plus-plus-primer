#include<iostream>
#include<algorithm>
#include<map>
#include<cctype>
#include"Query.h"
/*double Bulk_Quote::net_price(std::size_t i) const
{
        if(i > amount)
                return price * i *(1 - discount);
        else
                return price * i;
}
double print(std::ostream &os,const Quote& q,std::size_t n)
{
        double ret = q.net_price(n);
        os << "ISBN" <<q.isbn() <<"total due" << ret <<std::endl;
        return ret;

}
double Blasket::total_recepit(std::ostream &os)const
{
        double sum = 0;
        for(auto beg = item.begin(); beg != item.end();beg = item.upper_bound(*beg))
        {
               sum+= print(os,**beg,item.count(*beg));
        }
        return sum;
}
*/






string prus_string(int p,const string &i,const string &l)
{
        if(p > 1)
                return i + l;
        else
                return i;
}


std::ostream &print(std::ostream &os,const QueryResult & cases)
{
        os << cases.sought <<" occurs " << cases.lines->size() << prus_string(cases.lines->size(),"time","s") <<std::endl;
        for(auto num : *cases.lines)
        {
               os << "\t(line"  << num +1<<")" <<*(cases.file->begin() + num) <<std::endl;
        }
        return os;

}
void runQueries(std::ifstream &infile)
{
        TextQuery tq(infile);
        while(true){
                std::cout <<"enter word to look for, or q to quit: ";
                string s;
                if(!(std::cin >> s)|| s == "q")break;
                print(std::cout,tq.query(s)) <<std::endl;
        }
}
int main()
{
        std::ifstream infile("one.txt");
        TextQuery l(infile);
        Query q = (Query("fiery") & Query("bird") )| Query("wind");
        print(std::cout , q.eval(l));

}
