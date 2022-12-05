#include <iostream>
using namespace std;

class Learning
{
public:
    static int sumOfNum1(int n)
    {
        int sum = 0;
        for (int i = 0; i <= n; i++)
        {
            sum += i;
        }
        return sum;
    }
    static float sumOfNum2(int n)
    {
        float sum = (n * (n + 1)) / 2;
        // Better because of less computation time (big O)
        return sum;
    }
    static int sumOfEvenNum(int n)
    {
        int sum = 0;
        for (int i = 2; i <= n; i += 2)
        {
            sum += i;
        }
        return sum;
    }
    static int sumOfOddNum(int n)
    {
        int sum = 0;
        for (int i = 1; i <= n; i += 2)
        {
            sum += i;
        }
        return sum;
    }
};

int main()
{
    int num;
    cout << "Enter number: ";
    cin >> num;
    cout << endl
         << Learning::sumOfNum1(num) << endl
         << Learning::sumOfNum2(num) << endl
         << Learning::sumOfEvenNum(num) << endl
         << Learning::sumOfOddNum(num) << endl;
    return 0;
}