#include <iostream>
#include <vector>
// #include <set>
using namespace std;

class Vector
{
public:
    static void getInput(vector<int> &v, int &size);
    static void print(vector<int> &v);
    static int binarySearch_returnIndex(vector<int> &, int &);
    // static vector<int>::iterator binarySearch_returnIterator(vector<int> &, int &);
};

// class Set
// {
// public:
//     static int binarySearch_returnIndex(set<int> &, int &);
// };

void Vector::getInput(vector<int> &v, int &size)
{
    for (int i = 0; i < size; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
}

void Vector::print(vector<int> &v)
{
    for (auto e : v)
        cout << e << " ";
    cout << endl;
}

int Vector::binarySearch_returnIndex(vector<int> &v, int &key)
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

// vector<int>::iterator Vector::binarySearch_returnIterator(vector<int> &v, int &key)
// {
//     int start = 0;
//     int end = v.size() - 1;
//     int mid = start + (end - start) / 2;
//     // vector<int>::iterator it = v.begin() + v.size() / 2;
//     // vector<int>::iterator it = v.begin() + mid; // works like std::advance()
//     vector<int>::iterator itr = v.begin();
//     while (start <= end)
//     {
//         if (v[mid] == key)
//         {
//             advance(itr, mid);
//             return itr;
//         }
//         else if (v[mid] < key)
//         {
//             start = mid + 1;
//         }
//         else
//         {
//             end = mid - 1;
//         }
//         mid = start + (end - start) / 2;
//     }
// }