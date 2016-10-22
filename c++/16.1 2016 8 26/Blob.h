#ifndef BLOB_H_INCLUDED
#define BLOB_H_INCLUDED
#include<memory>
#include<vector>
#include<string>
#include<exception>
template<typename T>class Blobptr;
template<typename T>class Blob;
template<typename T> bool operator==(const Blobptr<T>&,const Blobptr<T>&);
template<typename T> bool operator!= (const Blobptr<T>&,const Blobptr<T>&);
template<typename T> class Blob
{
        friend class Blobptr<T>;
public:
        Blobptr<T> begin();
        Blobptr<T> end();
        typedef T value_type;
        typedef typename std::vector<T>::size_type size_type;
        Blob();
        Blob(std::initializer_list<T> il);
        size_type size() const {return data->size();}
        bool empty()const {return data->empty();}
        void push_back(const T &t)const {data ->push_back(t);}
        void push_back(T&& t){data->push_back(std::move(t));}
        void pop_back();
        template<typename F>Blob(F,F);
        T& back();
        T& operator[](size_type i);
private:
        std::shared_ptr<std::vector<T>> data;
        void check(size_type i ,const std::string &msg)const;
};
template<typename T> template<typename F> Blob<T>::Blob(F a,F,b):date(std::make_shared<std::vector<T>>(a,b)){}
template<typename T> Blobptr<T> Blob<T>::begin()
{
        return Blobptr<T>(*this);
}
template<typename T> Blobptr<T> Blob<T>::end()
{
        return Blobptr<T>(*this,data->size());
}
template<typename T>void Blob<T>::check(size_type i,const std::string &msg)const
{
        if(i >= data->size())
                throw std::out_of_range(msg);
}
template<typename T>T& Blob<T>::back()
{
        check(0,"back on empty Blob");
        return data->back();
}
template<typename T>T& Blob<T>::operator[](size_type i)
{
        check(i,"subscript out of ramg");
        return (*data)[i];
}
template<typename T>void Blob<T>::pop_back()
{
        check(0,"pop_back on empty Blob");
        data->pop_back();
}
template<typename T> Blob<T>::Blob(std::initializer_list<T>il):data(std::make_shared<std::vector<T>>(il)){}
template<typename T> Blob<T>::Blob():data(std::make_shared<std::vector<T>>()){}
template<typename T> class Blobptr
{
friend bool operator==<T>(const Blobptr&,const Blobptr&);
friend bool operator!=<T>(const Blobptr&,const Blobptr&);
private:
        std::shared_ptr<std::vector<T>> check(std::size_t,const std::string &)const;
        std::weak_ptr<std::vector<T>> wptr;
        std::size_t curr;
public:
        Blobptr():curr(0){}
        Blobptr(Blob<T> &a,std::size_t sz = 0):wptr(a.data),curr(sz){}
        T& operator*()const
        {
              auto s = check(curr,"dereference past end");
              return (*s)[curr];
        }
        Blobptr operator++();
        Blobptr operator--();
        Blobptr operator++(int);
        Blobptr operator--(int);
};

template<typename T> std::shared_ptr<std::vector<T>> Blobptr<T>::check(std::size_t i,const std::string &msg)const
{
        auto ret = wptr.lock();
        if(!ret)
                throw std::runtime_error("unbound Blobptr");
        if(i >= ret->size())
                throw std::out_of_range(msg);
        return ret;
}
template<typename T> Blobptr<T> Blobptr<T>::operator++()
{
        check(curr,"incerment past end of Blobptr");
        ++curr;
        return *this;
}
template<typename T>Blobptr<T> Blobptr<T>::operator--()
{
        --curr;
        check(curr,"decrement");
        return *this;
}

template<typename T>bool operator==(const Blobptr<T> &rhs,const Blobptr<T> &lhs)
{
       return rhs.curr == lhs.curr;
}
template<typename T>bool operator!=(const Blobptr<T> &rhs,const Blobptr<T> &lhs)
{
        return!(rhs==lhs);
}
template<typename T>Blobptr<T> Blobptr<T>::operator++(int)
{
        Blobptr<T> ret = *this;
        ++*this;
        return ret;
}
template<typename T>Blobptr<T> Blobptr<T>::operator--(int)
{
        Blobptr<T> ret = *this;
        --*this;
        return ret;
}
#endif // BLOB_H_INCLUDED
