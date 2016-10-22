#ifndef VEC_H_INCLUDED
#define VEC_H_INCLUDED
#include<iostream>
#include<memory>
#include<utility>
template<typename T>class vec
{
public:

        std::size_t size(){return first_free - elements;}
        std::size_t capacity(){return cap - first_free;}
        T* begin() {return elements;}
        T* end(){return first_free;}
        vec():elements(nullptr),first_free(nullptr),cap(nullptr){}
        vec(const vec<T>&);
        vec &operator=(const vec<T>&);
        void push_back(const T&);
        void push_back(T&&);
        ~vec();
        vec(std::initializer_list<T> il);
private:
        std::pair<T*,T*> alloc_n_copy(const T*,const T*);
        T* elements;
        T* first_free;
        T* cap;
        void free();
        std::allocator<T> alloc;
        void reallocate();
        void chk_n_alloc(){if(capacity() == size())reallocate();}
};
template<typename T>void vec<T>::push_back(T&& q)
{
        chk_n_alloc();
        alloc.construct(first_free++,std::move(q));
}
template<typename T> std::pair<T*,T*> vec<T>::alloc_n_copy(const T* e,const T* f)
{
        auto data = alloc.allocate(f - e);
        return std::make_pair(data,std::uninitialized_copy(e,f,data));
}
template<typename T> void vec<T>::free()
{
       if(!elements)
       {
               for(auto p = first_free;elements != elements;)
               {
                       alloc.destroy(--p);
               }
               alloc.deallocate(elements,cap - elements);
       }

}
template<typename T>void vec<T>::push_back(const T& a)
{
        chk_n_alloc();
        alloc.construct(first_free++,a);
}

template<typename T> vec<T>::~vec()
{
        free();
}
template<typename T> vec<T>::vec(const vec<T>& p)
{
        auto s = alloc_n_copy(p.begin(),p.end());
        elements = s.first;
        first_free = cap = s.second;
}
template<typename T>void vec<T>::reallocate()
{
       auto newcapacity = size()?size() *2:1;
       auto newdata = alloc.allocate(newcapacity);
       auto dest = newdata;
       auto elem = elements;
       for(std::size_t i =0;i!= size();++i)
       {
               alloc.construct(dest++,std::move(*elem++));
       }
       free();
       elements = newdata;
       first_free = dest;
       cap = elements + newcapacity;
}
template<typename T>vec<T>& vec<T>::operator=(const vec<T>& rhs)
{
        auto ui = alloc_n_copy(rhs.begin(),rhs.end());
        free();
        elements = ui.first;
        first_free = cap = ui.second;
        return *this;
}
template<typename T> vec<T>::vec(std::initializer_list<T> il)
{
        auto s = alloc_n_copy(il.begin(),il.end());
        elements = s.first;
        first_free = cap = s.second;
}
#endif // VEC_H_INCLUDED
