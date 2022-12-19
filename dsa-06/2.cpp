// CodeStudio Q: Modular Exponentiation
// here for easy explanation, assume : ^ is exponent and not bitwise XOR
// Find :: (x^n) % m, where x,n,m are like be : 0 <= x <= 10^9
#include <iostream>
using namespace std;
// Fast exponentiation algorithm
// for a(toPower)b : O(logb) is the time complexity as opposed to O(b) by brute-force method

class Solution
{
public:
    // (x^n) = ((x^n/2)^2), if n is even
    // (x^n) = (((x^n/2)^2) * x), if n is odd
    int modularExponentiation(int x, int n, int m)
    {
        int ans = 0;
        // TIP: VERY IMP:
        // Use bitwise operators whenever possible! Because they are less resource intensive and very very fast and optimised, as compared to '%' or '/'  or other similar operators.....
        while (n > 0)
        {
            if(n&1) // if n is odd
            {
                // 1ll == 1LL == (long long) 1
                // 2ll == 2LL == (long long) 2
                ans = (1ll * ans * (x % m)) % m;
                // using 1ll here, we smartly avoid the int overflow by typecasting: long long * int is always first calculated as long long and then finally the result is given as int (since ans accepts int)
            }
            x = (1ll * (x % m) * (x % m)) % m;
            n = n >> 1; // right-shift by 1 is divide by 2
        }
        return ans;
    }
};


int main(int argc, char const *argv[])
{
    int x, n, m;
    x = 0;
    n = 0;
    m = 0;
    Solution sol;
    cout << sol.modularExponentiation(x, n, m) << endl;
    return 0;
}