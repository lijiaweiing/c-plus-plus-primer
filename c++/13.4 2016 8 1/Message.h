#ifndef MESSAGE_H_INCLUDED
#define MESSAGE_H_INCLUDED
#include<iostream>
#include<string>
#include<set>
class Message
{
        friend class Folder;
public:
        explicit Message(const std::string &str = ""):contents(str){}
        Message(const Message&);
        Message& operator= (const Message&);
        void save(Folder&);
        void remove(Folder &);
private:
        std::string contents;
        std::set<Folder*> folders;
        void add_to_Folder(const Message&);
        void remove_from_folders();
};
void Message::save(folder &f)
{
        folders.insert(&f);
        f.addMsg(this);
}
void Message::remove(Folder&f)
{

}

#endif // MESSAGE_H_INCLUDED
