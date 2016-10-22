#include<iostream>
int main()
{
        using namespace std;
        cout<<"Enter the starting countdown value: ";
        int limite;
        cin>>limite;
        int i;
        for(i=limite;i;i--)
                cout<<"i="<<i<<"\n";
        cout<<"Done now that i="<<i<<"\n";
        return 0;

}
