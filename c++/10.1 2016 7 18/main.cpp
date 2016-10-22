//10.1
/*#include<algorithm>
#include<vector>
#include<iostream>
int main()
{
        std::vector<int> item;
        int word , i = 0;
        while(std::cin >> word && i < 8)
        {
                item.push_back(word);
                ++i;
        }
        const int val = 6;
        auto result = std::find(item.begin(),item.end(),val);
        int cases = std::count(item.begin(),item.end(),val);
        if( result == item.end())
        {
                std::cout << "is not present";
        }
        else
        {
                std::cout<<cases;
        }
}
*/
//10.2
/*#include<algorithm>
#include<list>
#include<iostream>
#include<string>
int main()
{
        std::list<std::string> item;
        std::string word; int i = 0;
        while(std::getline(std::cin,word) && i < 6)
        {
                item.push_back(word);
                ++i;
        }
        std::string val("has");
        auto result = std::find(item.begin(),item.end(),val);
        int cases = std::count(item.begin(),item.end(),val);
        if( result == item.end())
        {
                std::cout << "is not present";
        }
        else
        {
                std::cout<<cases;
        }

}
*/
