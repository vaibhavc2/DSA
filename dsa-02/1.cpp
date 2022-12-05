#include <iostream>
#include <math.h>
using namespace std;

class Solution
{
public:
    static int a;
    static int decimalToBinary(int);
    // static int reverse(int);
};

int Solution::a; // initialized to 0;static member!

int Solution::decimalToBinary(int n)
{
    int binary = 0;

    // a++;
    // cout << a << endl;

    // while (n != 0)
    // {
    //     int digit = n % 2;
    //     binary = binary * 10 + rem;
    //     n /= 2;
    // }

    int i = 0;
    while (n != 0)
    {
        int bit = n & 1;
        binary = binary + (bit * pow(10, i));
        n = n >> 1;
        i++;
    }

    return binary;
}

// int Solution::reverse(int b)
// {
//     int ans = 0;
//     while (b != 0)
//     {
//         int digit = b % 10;
//         ans = ans * 10 + digit;
//         b /= 10;
//     }
//     return ans;
// }

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;

    cout << Solution::decimalToBinary(n) << endl;
    return 0;
}