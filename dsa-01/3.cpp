#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // int a, b;
    // cout << "Enter value of a: ";
    // cin >> a;
    // cout << "\nEnter value of b: ";
    // cin >> b;
    // if (a > b)
    // {
    //     cout << "Difference is: " << a - b << endl;
    // }
    // else
    // {
    //     cout << "Difference is: " << b - a << endl;
    // }

    // SIZE OF DIFFERENT DATA-TYPES 
    cout << sizeof(int) << endl;
    cout << sizeof(char) << endl;
    cout << sizeof(bool) << endl;
    cout << sizeof(unsigned int) << endl;
    cout << sizeof(float) << endl;
    cout << sizeof(double) << endl;
    cout << sizeof(1ll) << endl; // 1ll : long long
    long long a = 5; // 8
    long long int b = 6; // 8
    long double c = 6.9; // 16
    long int d = 8; // 4
    cout << sizeof(a) << " " << sizeof(b) << " " << sizeof(c) << " " << sizeof(d) << endl;
    cout << sizeof(short int) << endl;

    // The decreasing order is :
    // long long >= long >= int >= short >= char


    return 0;
}
