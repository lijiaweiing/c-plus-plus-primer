#ifndef SALES_DATA_H_INCLUDED
#define SALES_DATA_H_INCLUDED
#include<string>
#include<iostream>
class Sales_data
{
private:

        std::string bookNo;      // implicitly initialized to the empty string
        unsigned units_sold = 0; // explicitly initialized
        double revenue = 0.0;
public:
        Sales_data(const Sales_data&);
        Sales_data(){}
        friend std::ostream &operator<<(std::ostream &,const Sales_data&);
        friend std::istream &operator>>(std::istream&,Sales_data&);
        Sales_data& operator+(const Sales_data&);
        Sales_data& operator+=(const Sales_data&);
};
Sales_data& Sales_data::operator+(const Sales_data& data)
{
        units_sold = units_sold + data.units_sold;
        revenue +=  data.revenue;
        return *this;
}
Sales_data& Sales_data::operator+=(const Sales_data &date)
{
         units_sold = units_sold + data.units_sold;
        revenue +=  data.revenue;
        return *this;
}
std::ostream & operator<<(std::ostream &os,const Sales_data& date)
{
        os << date.bookNo <<" "
        <<date.revenue <<" "
        <<date.units_sold;
        return os;
}
std::istream & operator>>(std::istream &is,Sales_data &date)
{
        double price = 0.0;
        is >> date.bookNo >> date.revenue >>price;
        if(is)
                date.revenue = date.units_sold * price;
        else
                date = Sales_data();
        return is;

}
#endif // SALES_DATA_H_INCLUDED
