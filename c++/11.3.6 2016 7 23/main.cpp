#include<fstream>
#include<sstream>
#include<map>
#include<iostream>
#include<string>
#include<stdexcept>
std::map<std::string ,std::string> buildMap(std::ifstream &map_file)
{
        std::map<std::string,std::string> trans_map;
        std::string key;
        std::string value;
        while(map_file >> key && std::getline(map_file,value))
        {
                if(value.size() > 1)
                       trans_map.insert({key,value.substr(1)});
                else
                        throw std::runtime_error("no rule for" + key);
        }
        return trans_map;
}
const std::string & transform(const std::string &s, const std::map<std::string,std::string>&m)
{
        auto map_t = m.find(s);
        if(map_t == m.end())
                return s;
        else
                return map_t->second;
}
void word_transform(std::ifstream &map_file,std::ifstream &input)
{
        auto trans_map = buildMap(map_file);
        std::string text;
        while(std::getline(input,text))
        {
             std::istringstream stream(text);
             std::string word;
             bool firstword = true;
             while(stream >> word)
             {
                if(firstword)
                        firstword = false;
                else
                        std::cout << " ";
                std::cout << transform(word,trans_map);
             }
             std::cout << std::endl;
        }
}
int main()
{
       std::ifstream out("01.txt");
       if(!out)
       {
               std::cerr<< "can not open this file";
       }
       std::ifstream in("02.txt");
         if(!in)
       {
               std::cerr<< "can not open this file";
       }
       word_transform(out,in);
}
