#include <iostream>
using namespace std;

// Q1: Given an integer number n, return the difference between the product of its digits and the sum of its digits.
// Q2: Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

class Solution
{
public:
    static int q1(int);
    static int q2(uint32_t);
};

int Solution::q1(int n)
{
    int sum = 0, product = 1;
    while (true)
    {
        if (n <= 0)
        {
            break;
        }
        int digit = n % 10;
        sum += digit;
        product *= digit;
        n /= 10;
    }

    return (product - sum);
}

int Solution::q2(uint32_t n) // returns number of 1 bits, if input is unsigned integer (also called hamming weight)
{
    int count = 0;
    while (n != 0)
    {
        // Checking last bit:
        if (n & 1) // true: last bit is 1, false: last bit is 0
        {
            count++;
        }
        n = n >> 1; // using right shift operator to shift number to right by 1 step
    }

    return count;
}

int main(int argc, char const *argv[])
{
    // int n1;
    // cin >> n1;
    uint32_t n2;
    cin >> n2;

    // cout << Solution::q1(n1) << endl;
    cout << Solution::q2(n2) << endl;

    return 0;
}
