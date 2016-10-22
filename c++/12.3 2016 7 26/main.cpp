#include<iostream>
#include<vector>
#include<set>
#include<memory>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
class TextQuery
{
public:
        TextQuery(std::ifstream a);
private:
        std::vector<std::string> factors;
        std::map<std::string , std::set<std::size_t>> ji;
};
TextQuery::TextQuery(std::ifstream a)
{
        size_t i = 0;
        std::string word;
        while(std::getline(a, word))
        {
                ++i;
                std::istringstream ins(word);

                std::string cases;
                while(ins >> cases)
                {
                        factors.push_back(cases);

                }
        }

}
void runQueries(std::ifstream &infile)
{
        TextQuery tq(infile);
        while(true)
        {
                std::cout << "Enter word to look for, or q to quit:";
                std::string s;
                if(!(std::cin >>s)||s == "q")break;
                printf(std::cout ,tq.query) << endl;
        }
}
int main()
{
        return 0;
}
