#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;

// Binary Search
// only applicable if array or a container (Data Structure) is in monotonous order (monotonous function) i.e.  it is sorted either in ascending order or descending order
// Time complexity of Binary Search is O(log n) as opposed to O(n) in case of Linear Search

class Functions
{
public:
    static void inputFunction(vector<int> &);
    static void printFunction(vector<int> &);
    static void removeDuplicates(vector<int> &);
    static bool binarySearch(vector<int>::iterator, vector<int>::iterator, int &);
    static int binarySearch_returnIndex(vector<int> &, int &);
};

void Functions::inputFunction(vector<int> &v)
{
    int count = 0;
    for (auto &e : v) // here we have to use &e because vector is reference here!
    {
        cout << "Enter Num " << count + 1 << " : ";
        cin >> e;
        count++;
    }

    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout << "Enter element " << i + 1 << " : ";
    //     cin >> v[i];
    // }

    // int input;

    // while (cin >> input)
    // {
    //     v.push_back(input);
    // }

    cout << endl;
}

void Functions::printFunction(vector<int> &v)
{
    // cout << "Printing the array: " << endl;
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void Functions::removeDuplicates(vector<int> &v)
{
    vector<int>::iterator last = std::unique(v.begin(), v.end());
    // using resize() to change size() of vector, shrink_to_fit will change the capacity
    v.resize(std::distance(v.begin(), last));
    v.shrink_to_fit();
    v.erase(last, v.end());
}

// bool Functions::binarySearch(vector<int>::iterator start, vector<int>::iterator end, int &key)
// {
//     auto x = std::distance(start, end) / 2;
//     std::vector<int>::iterator mid = start;
//     advance(mid, x / sizeof(int));
//     // if ascending order
//     if (*mid < *mid + 1)
//     {
//         if (*mid == key)
//         {
//             return true;
//         }
//         else if (key < *mid)
//         {
//             // auto l = mid;
//             // int *m = ((start) + (l - 1)) / 2;
//             while (true)
//             {
//                 advance(mid, (distance(start, mid) / 2) / sizeof(int));
//                 if (*mid == key)
//                 {
//                     return true;
//                 }
//                 else if (*mid < key)
//                 {
//                     advance(mid, (distance(start, mid) / 2) / sizeof(int));
//                 }
//                 else
//                 {
//                     start = mid;
//                 }
//             }
//         }
//         else
//         {
//         }
//     }
//     // if descending order
//     else
//     {
//     }
//     return false;
// }

int Functions::binarySearch_returnIndex(vector<int> &v, int &key)
{
    int start = 0;
    int end = v.size() - 1;
    int mid = (start + end) / 2;

    // if ascending order
    if (v[mid] < v[mid + 1])
    {
        while (mid != start)
        {
            if (v[mid] == key)
            {
                return mid;
            }
            else if (v[mid] > key)
            {
                mid = (start + mid) / 2;
            }
            else
            {
                // mid = (end + mid) / 2;
                mid = end - ((end - mid) / 2);
                // the above is written in this way so that it doesnot cross limit of int in case of numbers of range of (2^31)-1
            }
        }
    }
    else // if descending order
    {
        while (mid != end)
        {
            if (v[mid] == key)
            {
                return mid;
            }
            else if (v[mid] < key)
            {
                mid = (start + mid) / 2;
            }
            else
            {
                // mid = (end + mid) / 2;
                mid = end - ((end - mid) / 2);
                // the above is written in this way so that it doesnot cross limit of int in case of numbers of range of (2^31)-1
            }
        }
    }

    return -1;
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter no of numbers you want to enter: ";
    cin >> n;
    cout << endl;
    // cout << "Enter numbers:" << endl;
    vector<int> v(n);

    Functions::inputFunction(v);

    int key = 0;
    cout << "Which number to find? ";
    cin >> key;
    cout << endl;

    Functions::removeDuplicates(v); // using std::unique to remove all duplicates

    sort(v.begin(), v.end());
    // sort(v.begin(), v.end(), greater<int>()); // descending order
    cout << "Printing array sorted in ascending order and with duplicate elements removed: " << endl;
    Functions::printFunction(v);

    // cout << Functions::binarySearch(v.begin(), v.end(), key) << endl;
    // cout << binary_search(v.begin(), v.end(), key) << endl;

    int index = Functions::binarySearch_returnIndex(v, key);
    cout << endl;

    if (index >= 0)
    {
        cout << "Element found at index: " << index << " in the sorted array as above." << endl;
    }
    else
    {
        cout << "Element Not Found!!" << endl;
    }

    // Functions::printFunction(v);

    return 0;
}