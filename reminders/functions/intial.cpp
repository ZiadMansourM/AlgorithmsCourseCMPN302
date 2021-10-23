#include<iostream>
using namespace std;

int Multiply(int a, int b) 
{
    return a*b;
}

int main()
{
    int first, second;
    cout << "Welcome to our Calculator ^^"<<endl;
    cout << "Enter first number: ";
    cin >> first;
    cout << "Enter second number: ";
    cin >> second;
    int result = Multiply(first, second);
    cout << "Result is: " << result << endl;
}