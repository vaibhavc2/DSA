#include <iostream>
using namespace std;

int factorial(int x)
{
    int res = 1;
    for (int i = 0; i < x; i++)
    {
        res = res * (i + 1);
    }
    return res;
}

int nCr(int n, int r)
{
    int res = factorial(n) / (factorial(r) * factorial(n - r));
    return res;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int r;
    cin >> r;
    cout << nCr(n, r) << endl;
    return 0;
}