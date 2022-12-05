#include <iostream>
#include <math.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int a, b;
    cout << "Enter value of a & b: ";
    cin >> a >> b;
    cout << endl
         << "Enter the operation : ";
    char operation;
    cin >> operation;
    switch (operation)
    {
    case '+':
        cout << a + b;
        break;
    case '-':
        cout << a - b;
        break;
    case '*':
        cout << a * b;
        break;
    case '/':
        cout << a / b;
        break;
    case '^':
        cout << pow(a, b);
        break;
    case '%':
        cout << a % b;
        break;
    }
    return 0;
}