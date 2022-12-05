#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b;
    cout << "Enter value of a: ";
    cin >> a;
    cout << "\nEnter value of b: ";
    cin >> b;
    if (a > b)
    {
        cout << "Difference is: " << a - b << endl;
    }
    else
    {
        cout << "Difference is: " << b - a << endl;
    }

    return 0;
}
