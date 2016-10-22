#include<iostream>
#include<set>
#include<map>
#include<string>
#include<cctype>
int main()
{
        std::map<std::string , std::size_t> word_count;
        std::set<std::string> exclude = {"The","But","And","Or","An","A",
        "the","but","and","or","an","a"};
        std::string word;
        int i = 0;
        while(std::cin >> word && i <= 5)
        {
                ++i;
                std::string wd;
                for(auto &c : word)
                {
                       if(isupper(c))
                        {

                                c = tolower(c);
                                wd.push_back(c);}
                       else if(ispunct(c))
                       {

                       }
                       else
                       {
                               wd.push_back(c);
                       }
                }
                if(exclude.find(word) == exclude.end())
                        ++ word_count[word];
        }
        for(std::map<std::string , std::size_t>::const_iterator w= word_count.cbegin();w != word_count.cend();++w)
                std::cout << w->first << "       occurs " << w->second << ((w->second  > 1)?"times":"time") << std::endl;
}

