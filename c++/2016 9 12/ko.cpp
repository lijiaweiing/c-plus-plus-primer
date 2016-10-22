#include<vector> // 可变大小数组 中间位置添加删除耗时
#include<list>  //双向列表 在任何位置插入和删除都很快 不支持随机访问
#include<forward_list> //单向列表  在任何位置插入和删除都很快 不支持元素随机访问 没有size 操作
#include<array> // 固定大小数组 不支持添加 删除元素以及改变容器大小
#include<deque> //双端列表 支持随机访问


#include<iostream>
#include<list>
#include<string>
int mian()
{
        std::list<std::string> a = {"Milton" , "Shankepear" , "Austen"};
        list<string>::iterator it1 = a.begin(); //
        list<string>::const_iterator it2 = a.cbegin();
        auto it3 = a.begin(); // list<string>::iterator
        auto it4 = a.cgegin(); //list<string>::const_iterator
        std::cout << *it1;
        std::cout << *it2;
        std::cout <<*it3;
        std::cout <<*it4;
}
