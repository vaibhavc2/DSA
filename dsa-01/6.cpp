#include <iostream>
using namespace std;

class Solution
{
private:
    /* data */
public:
    Solution(/* args */);
    static bool isPrime(int n);
    ~Solution();
};

bool Solution::isPrime(int n)
{
    if (n <= 1)
    {
        return false;
    }
    else
    {
        for (int i = 2; i < n; i++)
        {
            if (n % i == 0 && n != i)
            {
                return false;
            }
            else
            {
                continue;
            }
        }
        return true;
    }
}

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    if (Solution::isPrime(n))
    {
        cout << "It is a prime number!" << endl;
    }
    else
    {
        cout << "It is not a prime number." << endl;
    }

    return 0;
}
