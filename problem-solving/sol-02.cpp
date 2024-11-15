// Q1: Given a signed 32-bit integer x , return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-2^31, (2^31) - 1], then return 0.
// Q2: The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.
// Q3: Given an integer n, return true if it is a power of two. Otherwise, return false. An integer n is a power of two, if there exists an integer x such that n == 2^x.

// ------------------------------------------------------------------------

#include <iostream>
#include <math.h>
#include <limits> //* use this since this is the c++ way of limits: use std::numeric_limits
#include <climits> // use this if want to use C style limits: INT_MAX & INT_MIN

//* use these:
// int imin = std::numeric_limits<int>::min(); // minimum value
// int imax = std::numeric_limits<int>::max(); // maximum value
//* OR USE:
#define IMIN std::numeric_limits<int>::min()
#define IMAX std::numeric_limits<int>::max()
using namespace std;

class Solution
{
public:
    int reverse(int x)
    {
        int digit, ans = 0;
        while (x != 0)
        {
            digit = x % 10;
            // ans * 10 <= IMAX because if not then, the number will excede the limits of int. Also we can't use the same form because ans may be such that if multiplied by 10 exceeds the limit of int, but otherwise is within the limits
            if (ans > IMAX / 10 || ans < IMIN / 10)
            {
                return 0;
            }
            ans = ans * 10 + digit;
            x /= 10;
        }
        return ans;
    }

    int bitwiseComplement(int n)
    {
        int ans = 1, i = 0;
        while (n != 0)
        {
            if (n & 1)
            {
                i++;
            }
            else
            {
                ans = pow(10, i) + ans;
                i++;
            }
            n = n >> 1;
        }

        return ans;
    }

    // bool isPowerOfTwo(int n)
    // {
    //     while (n != 1)
    //     {
    //         int rem = n % 2;
    //         if (rem != 0)
    //         {
    //             return false;
    //         }
    //         n /= 2;
    //     }

    //     return true;
    // }

    // The above approach is good enough, we can have more solutions:

    // Brute force solution, very inefficient!
    // bool isPowerOfTwo(int n)
    // {
    //     int arr[31];
    //     // int range ends at 2^31-1
    //     for (int i = 0; i < 31; i++)
    //     {
    //         arr[i] = pow(2, i);
    //     }
    //     for (int i = 0; i < 31; i++)
    //     {
    //         if (arr[i] == n)
    //         {
    //             return true;
    //         }
    //     }
    //     return false;
    // }

    //  a more efficient approach can be following:

    // bool isPowerOfTwo(int n)
    // {
    //     int currentPower = 1;
    //     for (int i = 1; i <= 31; i++)
    //     {
    //         if (currentPower == n)
    //         {
    //             return true;
    //         }
    //         // this eliminates the possibility of exceeding the range limit of int (2^31)-1 :
    //         if (currentPower < INT_MAX / 2)
    //             currentPower = currentPower * 2;
    //     }
    //     return false;
    // }

    // Another different approach : Number of setbits is always 1 in any power of two
    // bool isPowerOfTwo(int n)
    // {
    //     int setbits = 0;
    //     while (n != 0)
    //     {
    //         if (n & 1)
    //             setbits++;
    //         n = n >> 1;
    //     }
    //     if (setbits == 1)
    //         return true;
    //     return false;
    // }

    //* Most efficient implementation: O(1)
    bool isPowerOfTwo(int n)
    {
        if (n == 0)
            return false;

        return (ceil(log2(n)) == floor(log2(n)));
    }
    //* in the following approaches, INT OVERFLOW may occur
    // bool isPowerOfTwo(int x)
    // {
    //     /* First x in the below expression is for the case when
    //      x is 0 */
    //     return x && (!(x & (x - 1)));
    // }
    // bool isPowerofTwo(long long n)
    // {
    //     if (n == 0)
    //         return 0;
    //     if ((n & (~(n - 1))) == n)
    //         return 1;
    //     return 0;
    // }
};

// Lambda expression (or function) for INPUT-OUTPUT to file
auto fileIO = [](){
    #ifdef LOCAL_PROJECT // or, ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
};

int main()
{
    fileIO();
    Solution sol;
    int n;
    // cout << "Enter a number: ";
    cin >> n;
    // cout << "\nThe reverse of the given number is: " << sol.reverse(n) << endl;
    // cout << "The bitwise complement of the given number is: " << sol.bitwiseComplement(n) << endl;
    if (sol.isPowerOfTwo(n))
    {
        cout << "The given number is a power of two." << endl;
    }
    else
    {
        cout << "The given number is not a power of two." << endl;
    }
    return 0;
}