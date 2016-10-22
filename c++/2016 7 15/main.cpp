/*#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::cin;
bool seek(vector<int>::const_iterator begin,vector<int>::const_iterator end,int a)
{
        int o = 0;
        while(begin != end)
        {
                if(*begin == a)
                {
                        ++o;
                        break;
                }
                begin++;
        }
        if(o > 0)
        {
                return true;
        }else
        {
                return false;
        }
}
int main()
{
        std::vector<int> cha;
        for(int i; i<5 ;i++)
        {
                cha.push_back(i);
        }
        int ex = 2;
        std::cout<<seek( cha.begin(),cha.end(),ex);
        return 0;

}
*/
/*
#include<iostream>
#include<vector>
#include<list>
using std::list;
using std::vector;
using std::cout;
using std::cin;
int main()
{
        list<int> a = {1,2,3,4,5,6,7,8,9,10};
        vector<double> b;
        b.assign(a.begin(),a.end());
        list<std::string> slist1(1);
        slist1.assign(10,"Hiya!");
        return 0;
}
*/
//9.14
/*
#include<iostream>
#include<vector>
#include<list>
#include<cstring>
#include<string>
using std::string;
using std::vector;
using std::list;
using std::cin;
using std::cout;
int main()
{
        list<const char *> a = {"asd","hjk"};
        vector<string> b;
        b.assign(a.begin(),a.end());
        return 0;
}
*/
//9.15
/*#include<iostream>
#include<vector>
using std::vector;
using std::cin;
using std::cout;
bool get(vector<int> a,vector<int> b)
{
        if(a == b)
                return true;
        else
                return false;
}
int main()
{
        vector<int> s = {1,4};
        vector<int> y = {1,4};
        std::cout << (std::vector<int>(s.begin(), s.end()) == y ? "true" : "false") << std::endl;

}
*/
//
/*
#include<iostream>
#include<vector>
#include<string>
#include<list>
using std::list;
using std::vector;
using std::string;
int main()
{
        list<int> ilist;
        for(size_t ix = 0;ix != 4;++ix)
                ilist.push_back(ix);
        list<int> v = {5,6,7};
        ilist.insert(begin(ilist),v.begin(),v.end());
        for(auto x:ilist)
                std::cout<<x<<std::endl;
        return 0;
}
*/
/*
#include<string>
#include<iostream>
#include<deque>
using std::string;
using std::deque;
using std::cin;
using std::cout;
using std::endl;
int main()
{
        deque<string> s;
        string a;
        int i = 0;
        while(cin>>a && i <= 5)
        {
                s.push_back(a);
                i++;
        }
        for(auto m : s)
        {
                cout<<m<<endl;
        }
        return 0;
}
*/
//9.19
/*
#include<string>
#include<list>
#include<iostream>
#include<deque>
using std::string;
using std::deque;
using std::cin;
using std::list;
using std::cout;
using std::endl;
int main()
{
       list<string> s;
        string a;
        int i = 0;
        while(cin>>a && i <= 5)
        {
                s.push_back(a);
                i++;
        }
        for(auto m : s)
        {
                cout<<m<<endl;
        }
        return 0;
}
*/
//9.20
/*#include<list>
#include<iostream>
#include<deque>
using std::list;
using std::cin;
using std::deque;
using std::cout;
using std::endl;
int main()
{
        list<int> item1 = {1,2,3,4,5,6,7,8,9,10};
        deque<int> item2;
        deque<int> item3;
        for(list<int>::const_iterator i = item1.begin();i != item1.end() ; i++)
        {
                if(*i%2 == 0)
                {
                     item2.insert(item2.end(),*i);
                }else
                {
                        item3.insert(item3.begin(),*i);
                }
        }
        cout<<"Item2's element:";
        for(auto a : item2)
        {
                cout << a << " ";
        }
        cout<<endl;
        cout<<"Item3's element:";
        for(auto b : item3)
        {
                cout << b << " ";
        }
        return 0;
}
*/
//9.20
/*
#include<iostream>
#include<list>
#include<string>
using std::cin;
using std::cout;
using std::string;
using std::list;
int main()
{
        list<string> lst;
        string word;
        auto iter = lst.begin();
        while(cin >> word)
                iter = lst.insert(iter, word);

}
*/
//9.22

#include<iostream>
#include<vector>
using std::vector;
using std::cout;
using std::cin;
int main()
{
        vector<int>iv = {1,3,5,3,9,3,13,3};
        int some_val = 3;
        auto mid = iv.begin() + iv.size()/2;
        auto iter = iv.begin();
        while(iter != mid)
        {
                if(*mid == some_val)
                {
                mid = iv.insert(mid, 2 * some_val);}
                else{
                        --mid;
                }
        }
        for(auto x : iv)
        {
                cout << x <<std::endl;
        }
        return 0;
}

/*
#include <iostream>
#include <vector>

void double_and_insert(std::vector<int>& v, int some_val)
{
    auto mid = [&]{ return v.begin() + v.size() / 2; };
    for (auto curr = v.begin(); curr != mid(); ++curr)
        if (*curr == some_val)
            ++(curr = v.insert(curr, 2 * some_val));
}

int main()
{
    std::vector<int> v{ 1, 9, 1, 9, 9, 9, 1, 1 };
    double_and_insert(v, 1);

    for (auto i : v)
        std::cout << i << std::endl;
}
*/
