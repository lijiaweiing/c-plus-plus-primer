//13.1
class Sales_data
{
public:
        Sales_data(const Sales_data&);
private:
        std::string bookNo;
        int uints_sold = 0;
        double revernue = 0.0;
};
Sales_data::Sales_data(const Sales_data &orig):bookNo(orig.bookNo),uints_sold(orig.uints_sold),revenue(orig.revenue){}

//13.4
//假定Point是一个类类型，他有一个public的拷贝构造函数，指出下面程序片段
//那些地方使用了拷贝构造函数:
Point global;
Point foo_bar(Point arg)//use copy constructor --1
{
        Point local = arg,*heap = new Point(global);//Point local use copy constrtor --2
        *heap = local;//use copy constrtor
        Point pa[4] = {local , *heap};
        return *heap;
}
//13.5
//给定下面的类框架，编写一个拷贝函数，拷贝所有成员。你的构造函数应该动态分配一个新的string
//，并将对象拷贝到ps指向的位置，而不是拷贝ps本身:
class HasPtr
{
public:
        HasPtr(const HasPtr&);
        HasPtr(const std::string &s = std::string()):ps(new std::string(s)),i(0){}
private:
        std::string *ps;
        int i;
};
HasPtr::HasPtr(const HasPtr& has):ps(new std::string(*has.ps)),i(has.i) {}
//使用default
//我们将默认构造函数或拷贝构造函数定义为=default来显式地要求编译器生成合成的版本
class Sales_data
{
public:
        Sales_data() = default;
        Sales_data(const Sales_data&)
};
