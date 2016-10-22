
#include <iostream>
#include<string>
using std::istream; using std::ostream;
class Account
{
public:
        void calculate(){amount += amount * interestRate;}
        static double rate(){return interestRate;}
        static void rate(double);
private:
        std::string owner;
        double amount;
        static double interestRate;
        static double initRate();
};
void Account::rate(double )

int main()
{
        sale a = {"987",25,15.99};
        return 0;
}
