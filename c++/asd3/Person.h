#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
class Person
{
private:
        std::string name;
        std::string addre;
public:
        Person() = default;
        Person(std::string a,std::string b):name(a),addre(b) {}

};

#endif // PERSON_H_INCLUDED
