/*#include<iostream>
#include<vector>
#include<string>
#include<memory>
#include<set>
class Folder;
class Message
{
        friend void swap(Message &lhs,Message &rhs);
        friend void swap(std::set)
        friend class Folder;
public:
        explicit Message(const std::string &str = ""):contents(str){}
        Message(const Message &);
        Message& operator= (const Message&);
        ~Message();
        void save(Folder&);
        void remove(Folder&);
private:
        std::string contents;
        std::set<*Folder> folders;
        void add_to_Folders(const Message&);
        void remove_from_Folders();
        void addfol(Folder *f){folders.insert(f);}
        void remfol(Folder *f){folders.erase(f);}

};
void Message::save(Folder &f)
{
        folders.insert(&f);//将给定Folder 添加到我们的Folder 列表中
        f.addMsg(this); // 将本Message 添加到f的Message集合中

}
void Message::remove(Folder &f)
{
        folders.erase(&f);
        f.reMsg(this);
}
void Message::add_to_Folders(const Message& m)
{
        for(auto f:m.folders)
                f->addMsg(this);
}
Message::Message(const Message&m):contents(m.contents),folders(m.folders)
{
        add_to_Folders(m);
}
void Message::remove_from_Folders()
{
        for(auto f : folders)
                f->remMsg(this);
}
Message::~Message()
{
        remove_from_Folders();
}
Message& Message::operator=(const Message &rhs)
{
        remove_from_Folders(rhs);
        contents = rhs.contents;
        folders = rhs.folders;
        add_to_Folders(rhs);
        return *this;
}
void swap(Message &lhs,Message &rhs)
{
        for(auto f: lhs.folders)
                f->remMsg(&lhs);
        for(auto f :rhs.folders)
                f->remMsg(&rhs);
        swap(lhs.folders,rhs.folders);
        swap(lhs.contents,rhs.contents);
        for(auto f:lhs.folders)
                f->addMsg(&lhs);
        for(auto f: rhs.folders)
                f->addMsg(&rhs);
}
class Folder
{
        friend class Message;
private:
        std::set<Message*> cases;
        void add_to_Message(const Folder&);
        void remove_from_Message();
        void addMsg(Message &);
        void remMsg(Message &);
public:
       Folder() = default;

};
void Folder::addMsg(Message *a)
{
        cases.insert(a);
}
void Folder::remMsg(Message *a)
{
        cases.erase(a);
}
void Folder::add_to_Message(const Folder& fol)
{
        for(auto i : fol.cases)
        {
               i->addfol(this);
        }
}
void Folder::remove_from_Message()
{
         for(auto i : fol.cases)
        {
               i->remfol(this);
        }
}
*/
