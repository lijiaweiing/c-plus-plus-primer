#include<iostream>
#include<string>
#include<list>
#include<vector>
#include<deque>
#include<forward_list>
#include<array>
using namespace std；
/*int main()
{
        list<string>authors = {"Milton" , "Shakespeard" , "Austen"}; //列表初始化 C c ={a,b,c}
        vector<const char*> arithis = {"a","an" ,"the"};
        list<string> list2(authors); // C c1(c2) 类型匹配 true
        deque<string> authList(authors); //false 类型不匹配
        //正确 可以把const char* 转换为string
        //C c(b,e) c初始化为 迭代器b 和 迭代器e 指定范围元素的拷贝
        forward_list<string> words (arithis.begin(),arithis.end());
        vector<int> ivec(10,-1); //10个int 元素，每个初始化为-1
        forward_list<string> serc(10); //10个元素 ， 每个都是空string

}*/
int main()
{
        array<int  , 10> a1 = {0 , 1, 2 , 3, 4 , 5 , 6};
        array<int  , 10> a2 = {0};
        a1 = a2; // 替换a1中的成员
        a2 = {0} //错误 :不能将一个花括号表赋值数组
        list<string> names;
        vector<const char *> oldstyle;
        names = oldstyle; // 错误容器类型不匹配
        //sqe.assgin(b,e) 将seq 中元素替换为迭代器b 和 e 所表示的元素
        names.assign(oldstyle.begin(),oldstyle.end());//正确 可以将const char * 转换为string
        //seq.assgin(n , t) 将seq中的元素替换为n个值的为t的元素
        //等价于 slist.clear()
        //slist1.insert(silst1.begin(),10 , "Hiya");
        std::list<string> silst(1);
        silst.assign(10,)

}
