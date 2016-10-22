#include<iostream>
#include"Query.h"
int main()
{
std::ifstream is("one.txt");
    TextQuery t1(is);
    std::string word;
   // Query q =( Query("fiery") & Query("bird") )| Query("wind");
    Query q = Query("fiery");
    //Query q = Query("A");
    std::cout << q << std::endl;
        print(std::cout,q.eval(t1) );
}
