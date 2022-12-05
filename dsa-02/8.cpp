#include <iostream>
using namespace std;

// total number of set bits in two numbers a and b

int countSetBits(int a, int b)
{
    int count = 0;
    while (a != 0)
    {
        if (a & 1)
        {
            count++;
        }
        a >>= 1; // a = a >> 1
    }
    while (b != 0)
    {
        if (b & 1)
        {
            count++;
        }
        b >>= 1; // b = b >> 1
    }
    return count;
}

int main(int argc, char const *argv[])
{
    int a, b;
    cin >> a >> b;
    cout << countSetBits(a, b) << endl;
    return 0;
}