/*shared_ptr<T>sp //空智能指针，可以指向类型为T的对象
unique_ptr<T> up
p               //将p用作一个条件判断，若p指向一个对象，则为ture
*p              //解引用p，获得它指向对象
p->men          //等价于(*p).men
p.get()         //返回p中保存的指针。若智能指针释放其对象，返回指针所指向对象也消失
swap(p,q)       //交换p和q中的指针
p.swap(q)
//
make_shared<T> (arg)    //返回一个shared_ptr ,指向一个动态分配的类型为T的对象。使用args初始化此对象
shared_ptr<T>p(q)       //p 是shared_ptr 的拷贝；此操作会递增q中的计数器<1>.q中的指针必须装换为T*
p = q                   //p和q都是shared_ptr ，所保存的指针必须能相互装换。此操作会递减p的引用计数
                        //，递增q的引用计数；若p的引用计数变为0,则将其管理的原内存释放
p.unique()              //若p.use_count() 为1，返回true;否则返回flase
p.use_count()           //返回与p共享对象的智能指针数量；用于调试
//
auto r = std::make_pair<int>(42);       //r指向的int 只有一个引用者
r = q;                  //给r 赋值 ， 令它指向另一个地址
                        //递增q所指向的引用计数
                        //递减r 原来指向的对象的引用计数
                        //若r原来指向的对象没有引用者，会自动释放
void use_factory(T arg)
{
        shared_ptr<FOO> p = make_shared<FOO> (arg);
        //使用p
}//p离开了作用域,它指向的内存会被自动释放掉
*/
