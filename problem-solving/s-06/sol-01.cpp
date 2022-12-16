#include <iostream>
#include <vector> // using std::array
using namespace std;

// Sieve of Eratosthenes : Algorithm
// Q: Leetcode: Count number of primes less than a given number 'n'
// more optimised..., otherwise bruteforce method gives TLE at input "5*1000000"

class Solution
{
public:
    int countPrimes(int n)
    {
        int count = 0;
        // assuming all are prime
        vector<bool> prime(n+1, 1); // n + 1 for easy mapping
        // initialize all elements of the mapped prime' array to 1(true)

        prime[0] = prime[1] = 0; // mapping position of 0 & 1 as non-prime
        for(int i = 2; i < n; i++)
        {
            // start from 2: (now 2 is marked as prime)
            if(prime[i])
            {
                count++;
                // cancel out all multiples of this prime number as they all are composite numbers
                for(int j = 2*i; j<n; j+=i)
                {
                    prime[j] = 0;
                }
            }
        }

        return count;
    }
};

/*
Time Complexity: n-total
first marked all div. by 2 as non-prime: traversed n/2 times
then .... 3.... n/3 times...
...
== n/2 + n/3 + n/5 + n/7 + n/11 ....
== n (1/2 + 1/3 + 1/5 + 1/7 + 1/11 + ....)
==> HP of prime numbers - log(log n) (using Taylor series)
==> Time complexity : O(n*(log(log(n))))
*/

int main()
{
    int n = 5000000;
    // cin >> n;
    Solution sol;
    cout << sol.countPrimes(n) << endl;
    return 0;
}