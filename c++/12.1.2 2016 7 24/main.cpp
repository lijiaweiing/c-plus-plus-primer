/*#include<vector>
#include<memory>
#include<iostream>
std::vector<int>* fas()
{
        std::vector<int> vec;
        for(int i = 0;i <10 ;++i)
        {
                vec.push_back(i);
        }
        return new std::vector<int>(vec);
}
void haha()
{
        std::vector<int> *k = fas();
        for(auto i : *k)
        {
                std::cout << i<<" ";
        }
        delete k;

}
int main()
{


       haha();
}
*/
/*#include<memory>
#include<iostream>
#include<vector>
std::shared_ptr<std::vector<int>> fas()
{
        return std::make_shared<std::vector<int>>();
}
std::shared_ptr<std::vector<int>> has(std::shared_ptr<std::vector<int>> c)
{
        for(int i = 0;i <10 ; ++i)
                c->push_back(i);
        return c;
}
std::ostream& print(std::shared_ptr<std::vector<int>> c,std::ostream &os)
{
        for(auto i : *c)
                os << i <<" ";
        return os;
}
int main()
{
        auto a = has(fas());
        print(a,std::cout);
}
*/
