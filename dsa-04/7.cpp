#include <iostream>
#include <vector>
using namespace std;

// implementing other way of Binary search algorithm, just a small change
int binarySearch_returnIndex(vector<int> &v, int &key)
{
    int start = 0;
    int end = v.size() - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        if (v[mid] == key)
        {
            return mid;
        }
        else if (v[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return -1;
}

int main(int argc, const char *argv[])
{
    vector<int> v;
    v.reserve(7); // we can also use vector<int> v(7) for reserving upto n i.e. 7 capacity
    // cout << v.capacity() << endl;

    // vector<int> v[N];
    // It creates a static array of N vectors of the first type i.e.  v[0]  is now a whole new and different vector than v[1] which is totally different than  v[2]  and so on. If you want to push a value into the 1st vector that is  v[0] , you will do it by  v[0].push _ back(val) .

    v.push_back(3);
    v.push_back(4);
    v.push_back(7);
    v.push_back(9);
    v.push_back(11);
    v.push_back(18);
    v.push_back(19);

    int key = 11;

    if (binarySearch_returnIndex(v, key) >= 0)
    {
        cout << "Element found at index: " << binarySearch_returnIndex(v, key) << endl;
    }
    else
    {
        cout << "Element not found." << endl;
    }

    return 0;
}