#include <iostream>
using namespace std;

class Learn
{
public:
    static int fibonacciRecursion(int n);
    static void fibonacciSwap(int n);
};

int Learn::fibonacciRecursion(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    else
    {
        return fibonacciRecursion(n - 1) + fibonacciRecursion(n - 2);
    }
}

void Learn::fibonacciSwap(int n)
{
    int a = 0, b = 1;
    cout << a << ", " << b << ", ";
    for (int i = 0; i < n - 2; i++)
    {
        int nextTerm = a + b;
        cout << nextTerm << ", ";
        a = b;
        b = nextTerm;
    }
    cout << "..." << endl;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    // for (int i = 0; i < n; i++)
    // {
    //     cout << Learn::fibonacciRecursion(i) << ", ";
    // }
    // cout << "..." << endl;

    Learn::fibonacciSwap(n);
    return 0;
}