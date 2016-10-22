/*#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::cin;
int main()
{
        vector<int> c = {1,2,3,4,5};
        if(!c.empty())
        {
                c.front() = 42;
                auto &v = c.back();
                v = 1024;
                auto v2 = c.back();
                v2 = 0;
        }
        cout<<c.at(0);
}
*/
//9.24
/*#include<iostream>
#include<vector>
using std::cout;
using std::cin;
using std::vector;
int main()
{
        vector<int> c;
        auto a = c.front();
        auto b = *c.begin();
        auto x = c[0];
        auto y = c.at(0);
        return 0;
}
*/
/*
#include<iostream>
#include<list>
using std::list;
using std::cin;
using std::cout;
int main()
{
        list<int> lst = {0,1,2,3,4,5,6,7,8,9};
        auto it = lst.begin();
        while(it != lst.end())
        {
                if(*it % 2)
                        it = lst.erase(it);
                else
                        ++it;
        }
        for(auto x : lst)
                cout << x << std::endl;

}
*/
//9.26
/*#include<iostream>
#include<list>
#include<vector>
using std::vector;
using std::list;
using std::cout;
int main()
{
        vector<int> item1;
        list<int> item2;
        int ia[] = { 0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89 };
        for(auto x: ia)
        {
                item1.push_back(x);
                item2.push_back(x);
        }
        auto x1 = item1.begin();
        while(x1 != item1.end())
        {
                if(!(*x1 % 2))
                        x1 = item1.erase(x1);
                else
                        ++x1;
        }
        for(auto y1 : item1)
        {
                cout<<y1<<std::endl;
        }

        return 0;
}
*/
//9.3.4
/*
#include<iostream>
#include<forward_list>
using std::forward_list;
using std::cout;
using std::cin;
int main()
{
        forward_list<int> lst = {0,1,2,3,4,5,6,7,8,9,10};
        auto x1 = lst.before_begin();
        auto x2 = lst.begin();
        while(x2 != lst.end())
        {
                if(*x2 % 2)//若为奇数
                        x2 = lst.erase_after(x1);
                else
                {
                        x1 = x2;
                        ++x2;
                }
        }
        for(auto x3 = lst.begin()  )

}
*/
//9.28
/*
#include<iostream>
#include<string>
#include<forward_list>
using std::string;
using std::forward_list;
using std::cout;
using std::cin;
void fix(forward_list<string> &item,string &lable1,string &lable2)
{
        int i = 0;
       auto prev = item.before_begin();
       auto curr = item.begin();
       while(curr != item.end())
       {
               if(*curr == lable1)
                { curr = item.insert_after(curr,lable2);
                ++i;

               }
               else
               {
                        prev = curr;
                       ++curr;

               }


       }
        if(i == 0)
       {
            item.insert_after(prev,lable2);
       }
}
int main()
{
       forward_list<string> table = {"123","bcd","a ","fopnhas"};
        string a = "1";
        string b = "asdbnlk";
        fix(table,a,b);
        for(auto s : table)
                cout<<s<<std::endl;
        return 0;
}
*/
/*
#include<iostream>
#include<list>
#include<vector>
using std::list;
using std::cout;
using std::cin;
int main()
{
        list<int> ilist(10, 42);
        ilist.resize(15);
        for(auto i : ilist)
                cout<<i<<std::endl;
        return 0;
}
*/

/*#include<iostream>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
int main()
{
        vector<int> vi = {0 ,1,2,3,4,5,6,7,8,9,10};
        auto iter = vi.begin();
        while(iter != vi.end())
        {
                if(*iter % 2)
                {
                        iter = vi.insert(iter,*iter);
                        iter += 2;
                }else
                {
                        iter = vi.erase(iter);
                }
        }
        for(auto i : vi)
        {
                cout<<i<<std::endl;
        }
}
*/
/*#include<iostream>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
int main()
{
        vector<int> vi = {0 ,1,2,3,4,5,6,7,8,9,10};
        auto begin = vi.begin();
        while(begin != vi.end())
        {
                ++begin;
                begin = vi.insert(begin,42);
                ++begin;
        }
        for(auto i : vi)
        {
                cout<<i<<std::endl;
        }
}
*/
/*
#include<iostream>
#include<list>
using std::list;
using std::cout;
using std::cin;
int main()
{
        list<int> vi = {0 ,1,2,3,4,5,6,7,8,9,10};
        auto iter = vi.begin();
        while(iter != vi.end())
        {
                if(*iter % 2)
                {
                        iter = vi.insert(iter,*iter);
                        ++iter;
                        ++iter;
                }else{
                iter = vi.erase(iter);
                }
        }
        for(auto i: vi)
        {
                cout<<i<<std::endl;
        }
        return 0;
}
*/
//9.31
/*
#include<iostream>
#include<forward_list>
using std::forward_list;
using std::cin;
using std::cout;
int main()
{
        forward_list<int> vi = {0 ,1,2,3,4,5,6,7,8,9,10};
        auto prev = vi.before_begin();
        auto curr = vi.begin();
        while(curr != vi.end())
        {
                if(*curr % 2)
                {
                        curr = vi.insert_after(curr,*curr);
                        prev = curr;
                        ++curr;
                }else
                {
                        curr = vi.erase_after(prev);
                }
        }
        for(auto i: vi)
        {
                cout<<i<<std::endl;
        }
}
*/
//9.4章
/*#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::cin;
int main()
{
        vector<int> ivec;
        cout<<"ivec: size:"<<ivec.size()
        <<"capacity: "<<ivec.capacity() << std::endl;
        for(vector<int>::size_type ix = 0;ix != 24;++ix)
        {
                ivec.push_back(ix);
        }
        ivec.reserve(50);
        cout<<"ivec: size:"<<ivec.size()
        <<"capacity: "<<ivec.capacity() << std::endl;
        while(ivec.size() != ivec.capacity())
        {
                ivec.push_back(0);
        }
        cout<<"ivec: size:"<<ivec.size()
        <<"capacity: "<<ivec.capacity() << std::endl;
        ivec.push_back(90);
        cout<<"ivec: size:"<<ivec.size()
        <<"capacity: "<<ivec.capacity() << std::endl;
        ivec.shrink_to_fit();
        cout<<"ivec: size:"<<ivec.size()
        <<"capacity: "<<ivec.capacity() << std::endl;
        return 0;
}
*/
/*#include<string>
#include<iostream>
using std::cin;
using std::cout;
using std::string;
int main()
{
        const char cp[] = "Hello world";
        char noNull[] = {'h','i'};
        string s1(cp);  cout<<s1<<'\n';
        string s2(noNull,2); cout<<s2<<'\n';
        return 0;
}*/
/*#include<iostream>
#include<vector>
#include<cstring>
#include<string>
using std::vector;
using std::string;
using std::cout;
using std::cin;
int main()
{
        vector<char> item = {'h','e','l','l','o','w','r','o','l','d', '\0'};
        auto x = item.begin() + 6;
        string s1 (item.begin(),x);
        cout<<s1;

}
*/
/*#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::cin;
int main()
{
        /*const char *cp = "Stately, plump Buck";
        string s = {"12"};
        s.insert(s.size(), cp + 7);
        s.assign(cp,12);
        cout<<s<<std::endl;*/
        /*string s = "some string",s2 = "some other string";
        s.insert(0,s2);
        s.insert(0,s2,0,s2.size());
        cout<<s;
        string s("C++ Primer");
        string s2 = s;
        s.insert(s.size()," 4th Ed.");
        s.erase(11 , 3); cout<<s<<std::endl;
        s.insert(11,"5th");cout<<s;
        return 0;
}
*/
/*#include<iostream>
#include<string>
using std::string;
using std::cout;
using std::cin;
using std::endl;
void fix(string &s , string const &oldVal,string const &newVal)
{
        for(auto curr = s.begin();curr != s.end() ; ++curr)
        {
                if(oldVal == )
                {

                }
                else
                {
                        continue;
                }
        }
}
int main()
{

}
*/
