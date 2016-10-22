#include<iostream>
int main()
{

        using namespace std;
        int count=0;
        char ch;
        cout<<"Enter character; enter # to quite :\n";
        cin>>ch;
        while(ch!='#')
        {

                cout<<ch;
                cin>>ch;
                ++count;


        }
        cout<<endl<<count<<"charater read\n";
        return 0;
}
