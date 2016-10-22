#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED
template<typename elemType> class ListItem;
template<typename elemType> class List
{public:
        List();
        List(const ListItem<elemType>&);
        List &operator=(const list<elemType> &);
        ~List();
        void insert(ListItem<T> *ptr,elemType value);
private:
        ListItem<T> *front,*end;
};


#endif // LIST_H_INCLUDED
