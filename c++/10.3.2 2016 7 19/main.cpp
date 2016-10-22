/*#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<numeric>
void eliDups(std::vector<std::string> &words)
{
        std::sort(words.begin(),words.end());
        auto end_unique = std::unique(words.begin() ,words.end());
        words.erase(end_unique,words.end());
}
int main()
{
        std::vector<std::string> word;
        eliDups(words);
        std::stable_sort(word.begin() ,word.end() ,[](const std::string &a,const std::string &b){return a<b;});
}
*/
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
void eliDups(std::vector<std::string> &word)
{

        std::sort(word.begin(),word.end());
        auto end_unique = unique(word.begin(),word.end());
        word.erase(end_unique,word.end());
}
std::string make_plural(size_t ctr ,const std::string &word,const std::string &b)
{
        return (ctr > 1)?word + b :word;
}
void biggies(std::vector<std::string> &word , std::vector<std::string>::size_type sz)
{
        eliDups(word);
       std::stable_sort(word.begin(), word.end(),[](const std::string &a , const std::string &b){return a.size()<b.size();});
       auto wc = std::find_if(word.begin(),word.end(),[sz](const std::string &a) {return a.size() >= sz;});
       auto count = word.end() - wc;
       std::cout << count << " " <<make_plural(count , "word" , "s")
       <<"of length " << sz << "or longer" <<std::endl;
       std::for_each(wc , word.end(),[](const std::string&s){std::cout << s <<" ";});
}
int main()
{
        std::vector<std::string> item = {"the","quick","red","fox","jump","over","the","slow","red","trutle"};
       biggies(item,4);
}

//10.18
/*#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<numeric>
void eliDups(std::vector<std::string> &word)
{

        std::sort(word.begin(),word.end());
        auto end_unique = unique(word.begin(),word.end());
        word.erase(end_unique,word.end());
}
std::string make_plural(size_t ctr ,const std::string &word,const std::string &b)
{
        return (ctr > 1)?word + b :word;
}
void biggies(std::vector<std::string> &word , std::vector<std::string>::size_type sz)
{
        eliDups(word);
       std::stable_sort(word.begin(), word.end(),[](const std::string &a , const std::string &b){return a.size()<b.size();});
       auto wc = std::partition(word.begin(),word.end(),[sz](const std::string &a) {return a.size() >= sz;});
      word.erase(wc,word.end());
      auto count = word.size();
       std::cout << count << " " <<make_plural(count , "word" , "s")
       <<"of length " << sz << "or longer" <<std::endl;
       std::for_each(word.begin() ,wc ,[](const std::string&s){std::cout << s <<" ";});
}
int main()
{
        std::vector<std::string> item = {"the","quick","red","fox","jump","over","the","slow","red","trutle"};
       biggies(item,4);
}
*/
//10.19
/*#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<numeric>
void eliDups(std::vector<std::string> &word)
{

        std::sort(word.begin(),word.end());
        auto end_unique = unique(word.begin(),word.end());
        word.erase(end_unique,word.end());
}
std::string make_plural(size_t ctr ,const std::string &word,const std::string &b)
{
        return (ctr > 1)?word + b :word;
}
void biggies(std::vector<std::string> &word , std::vector<std::string>::size_type sz)
{
        eliDups(word);
       std::stable_sort(word.begin(), word.end(),[](const std::string &a , const std::string &b){return a.size()<b.size();});
       auto wc = std::stable_partition(word.begin(),word.end(),[sz](const std::string &a) {return a.size() >= sz;});
      word.erase(wc,word.end());
      auto count = word.size();
       std::cout << count << " " <<make_plural(count , "word" , "s")
       <<"of length " << sz << "or longer" <<std::endl;
       std::for_each(word.begin() ,wc ,[](const std::string&s){std::cout << s <<" ";});
}
int main()
{
        std::vector<std::string> item = {"the","quick","red","fox","jump","over","the","slow","red","trutle"};
       biggies(item,4);
}
*/
