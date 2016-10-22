#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED
#include<iostream>
#include<fstream>
#include<vector>
#include<map>
#include<memory>
#include<set>
#include<sstream>

class student;
class liner
{
        friend class student;
private:
        std::shared_ptr<std::vector<std::string>> id;
        std::shared_ptr<std::vector<std::string>> name;
        std::shared_ptr<std::set<std::string>> subjects;

        std::shared_ptr<std::vector<std::vector<std::string>>> grades;

public:
        liner(std::ifstream &);
        std::vector<student> eval();

}
class student
{
private:
        std::shared_ptr<std::vector<std::map<std::string,double>>> file;
        std::string stuname;
        std::string stuid;
public:
        student(const std::string &s,const std::string &d,
        std::shared_ptr<std::vector<std::map<std::string,double>>> k):stuname(s),stuid(d),file(k){}

};
liner::liner(std::ifstream &is):subjects(new ):
{
        std::size_t i = 0;
        std::string x;
        while(std::getline(is,x))
        {
                if( i == 0)
                {
                        std::string n;
                        std::size_t cd = 0;
                     std::istringstream line(x);
                     while(std::getline(line,n,'\t'))
                     {
                        if(cd <= 1)
                        {

                        }
                        else
                        {
                             subjects.insert(n);
                        }
                     }
                }
                else
                {
                       std::string ny;
                       std::size_t ui = 0;
                       std::istringstream tine(x);
                       while(std::getline(tine,ny,'\t'))
                       {
                               if(ui == 0)
                               {
                                       name->push_back(ny);
                               }
                               else if(ui == 1)
                               {
                                       id->push_back(ny);
                               }
                               else
                               {
                                       std::stringstream ss;
                                       double number;
                                       ss << ny;
                                       ss>>number;
                                       grade->push_back(number);
                               }
                               ui++
                       }
                }
                ++i;
        }

}
std::vector<student> liner::eval()
{
        for(auto )
}




#endif // PERSON_H_INCLUDED
