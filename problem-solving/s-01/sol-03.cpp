#include <iostream>
#include <vector>
using namespace std;

// Question:
// Given any array of integers nums and an integer target, return indices such that they add up to target.

class Solution
{
public:
    static void arrayQuestion(vector<int> &, int &);
};

void Solution::arrayQuestion(vector<int> &arr, int &n)
{
    int count = 0;
    if (n % 2 == 0)
    {
        for (int i = 0; i < arr.size() / 2; i++)
        {
            for (int j = arr.size(); j >= 0; j--)
            {
                if ((i + j == n) && i != j)
                {
                    cout << endl
                         << "Index Pair " << count + 1 << ": " << i << ", " << j << endl;
                    count++;
                    // cout << a << " " << b << endl;
                }
            }
        }
    }
    else
    {
        if (n)
        {
            /* code */
        }
    }
}

int main(int argc, char const *argv[])
{
    int arr_size, target_num;
    cout << "Enter the target number: ";
    cin >> target_num;
    cout << endl;
    cout << "Enter the size of array: ";
    cin >> arr_size;

    vector<int> num_arr(arr_size);
    cout << endl
         << "Enter the elements in array: " << endl;

    for (int i = 0; i < arr_size; i++)
    {
        cout << "Element " << i + 1 << ": ";
        cin >> num_arr[i];
        cout << endl;
    }

    Solution::arrayQuestion(num_arr, target_num);

    // for (int j = 0; j < arr_size; j++)
    // {
    //     cout << "Element " << j + 1 << ": " << num_arr[j] << endl;
    // }

    return 0;
}
