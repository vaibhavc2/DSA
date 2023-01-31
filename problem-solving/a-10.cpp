#include <iostream>
using namespace std;

// Q: Find full square root (floating part i.e. decimals also) of a given number without using mathematical algorithms or functions (like pow())
// Try to get as precise as possible. So it can give ans acc to given precision,
// say precision = 3, ans upto 3 decimal places... so on

// implementing binary search for integer part first
long long int sqRoot_BinarySearch(int &x)
{
    int start = 0;
    int end = x;
    long long int mid = start + (end - start) / 2;

    long long int ans = 0;
    while (start <= end)
    {
        long long int sq = mid * mid;
        if (sq == x)
        {
            ans = mid;
            break;
        }
        else if (sq < x)
        {
            ans = mid;
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}

// long double squareRoot_Precision(int x)
// {
//     long double ans = sqRoot_BinarySearch(x); // integer part
//     while (ans * ans < x)
//     {
//         ans += 0.1;
//     }
//     ans -= 0.1;
//     while (ans * ans < x)
//     {
//         ans += 0.01;
//     }
//     ans -= 0.01;
//     return ans;
// }

long double squareRoot_Precision_Better(int x, int precision)
{
    long double factor = 1;
    long double ans = sqRoot_BinarySearch(x);

    for (int i = 0; i < precision; i++)
    {
        factor /= 10;
        // so for every iteration till the given precision, factor becomes 0.1, 0.01, and so on

        for (long double j = ans; j * j < x; j += factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << endl;

    // cout << "Sq Root: " << squareRoot_Precision(n) << endl;
    // cout << "Sq Root: " << squareRoot_Precision_Better(n,2) << endl;
    cout << "Sq Root: " << squareRoot_Precision_Better(n, 3) << endl;
    return 0;
}