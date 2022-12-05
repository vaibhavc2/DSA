#include <iostream>
using namespace std;

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    if (n > 0)
    {
        cout << endl
             << n << " is a positive integer." << endl;
    }
    else if (n < 0)
    {
        cout << endl
             << n << " is a negative integer." << endl;
    }
    else
    {
        cout << endl
             << n << " is neither a positive nor a negative integer." << endl;
    }

    return 0;
}