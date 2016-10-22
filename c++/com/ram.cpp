#include <iostream>
#include <cstring>
const int SIZE = 20;
int main()
{
   using namespace std;
    char firstName[SIZE];
    char lastName[SIZE];
    char fullName[2*SIZE + 1];
    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;
    strncpy(fullName,lastName,SIZE);
    strcat(fullName, ", ");
    strncat(fullName, firstName, SIZE);
    fullName[SIZE - 1] = '\0';
    cout << "Here's the information in a single string: "
         << fullName << endl;
    return 0;
}
