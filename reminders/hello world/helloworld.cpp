#include <iostream>
#include <string> // doesn't give an Error
using namespace std;

int main()
{
    string first_name, last_name;
    cout << "Enter your first name: ";
    cin >> first_name;
    cout << "Enter your last name: ";
    cin >> last_name;
    string result = "Hello " + first_name + " " + last_name; 
    cout << result << endl;
    return 0;
}