#include <iostream>
using namespace std;

// Q2 You are given an array 'ARR' of size 'N' containing each number between 1 and 'N' - 1 at least once.There is a single integer value that is present in the array twice. Your task is to find the duplicate integer value present in the array.

class Solution
{
public:
    static int duplicate(int *array, int &size);
};

int Solution::duplicate(int *array, int &size)
{
    int ans = 0;

    // XOR all array elements
    // and then
    // XOR numbers from 1 to N-1 (in array, there are numbers from 1 to N-1, and there is one number which is duplicate)
    // then according to the rules of XOR, all the numbers will come twice and hence make 0, but the duplicate number will be present thrice in the XOR equation which will make it the final answer!
    // 1,2,3,4,5,...,9,5
    // 1,2,3,4,5,...,9
    // Basically we XOR above 2 expressions... and hence the duplicate (above case, 5) remains as the answer

    for (int i = 0; i < size; i++)
    {
        ans = ans ^ array[i] ^ i; // XOR of i starting from 0 makes no change....
        // ans = ans ^ array[i];
    }

    // for (int i = 1; i < size; i++)
    // {
    //     ans = ans ^ i;
    // }

    return ans;
}

int main(int argc, char const *argv[])
{
    // int array[] = {1, 2, 3, 4, 5, 6, 7, 4};
    int array[] = {1, 8, 9, 2, 3, 4, 5, 9, 7, 6};
    int size = sizeof(array) / sizeof(int);

    cout << Solution::duplicate(array, size) << endl;

    return 0;
}