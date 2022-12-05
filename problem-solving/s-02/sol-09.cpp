#include <iostream>
using namespace std;

// Q: Find square root of a given number without using mathematical algorithms or functions (like pow())

// in the answer, we have to return just the integer part of the sqrt(x) ignoring the decimals, basically floor() of the sqrt(x)

// one method is bruteforce : by comparing sq(1) till sq(n) where it matches the given number or exceeds. But here complexity is O(sqrt(n)) and we are trying to solve this in time complexity O(log(n))

class Solution
{
public:
    static long long int squareRoot_binarySearch(int &x);
};

long long int Solution::squareRoot_binarySearch(int &x)
{
    int start = 0;
    int end = x;
    long long int mid = start + (end - start) / 2;
    // we have to use long long int to deal with large integers here

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
        else // sq > x
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter a number: ";
    cin >> n;
    cout << endl;

    long long int sq_root = Solution::squareRoot_binarySearch(n);
    cout << "Square Root : " << sq_root << endl;

    return 0;
}