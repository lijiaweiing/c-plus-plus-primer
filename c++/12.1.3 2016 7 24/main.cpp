/*#include<iostream>
#include<memory>
int main()
{
        std::shared_ptr<int> p(new int(42));
        int *q  = p.get();
        {
                std::shared_ptr<int>(q);
        }
        int foo = *p;
}
*/
/*#include<memory>
#include<iostream>
void process(std::shared_ptr<int> ptr)
{

}
int main()
{
        std::shared_ptr<int> p(new int(10));
        process(std::shared_ptr<int>(p.get()));
        auto q = p;
        std::cout<< p.use_count();
}
*/
//12.14 && 12.15
#include<iostream>
struct destination;
struct connection;
connection connect("destination*");
void disconnect(connection);//关闭给定的定义
void end_connection(connection *p)
{
        disconnect(*p);
}
void  f(destination &d/*其他参数*/)
{
        connection c = connect(&d);
        shared_ptr<connection> p(&c,end_connection);
        //12.15
        shared_ptr<connection> p(&c,[](connection *p){disconnect(*p);});
}
