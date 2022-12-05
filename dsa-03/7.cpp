#include <iostream>
#include <deque>
using namespace std;

// deque : (pronounced deck) (double ended queue)
// dynamic DS
// can be changed from both sides (front, and back) unlike vector
// Heap memory, non contiguous
// Most methods of deque & vector are implemented such that their time complexity is O(1), erase is O(n)

int main(int argc, char const *argv[])
{
    deque<int> d;
    deque<int> d2;
    d.push_back(1);
    d.push_front(2);
    d.push_back(8);
    d.push_front(9);

    cout << endl;
    for (int i : d)
        cout << i << " ";

    cout << endl;
    // d.pop_back();
    // for (int i : d)
    //     cout << i << " ";

    // d.pop_front();
    // cout << endl;
    // for (int i = 0; i < d.size(); i++)
    // {
    //     cout << d[i] << " ";
    // }

    cout << "Element at index 2: " << d.at(2) << endl;

    cout << "Front: " << d.front() << endl;
    cout << "Back: " << d.back() << endl;

    cout << "Empty? " << d.empty() << endl;
    cout << "Empty? " << d2.empty() << endl;

    cout << "Before erase: " << d.size() << endl;
    d.erase(d.begin() + 1, d.begin() + 3); // the range is as follows [), that is including the starting but not ending...!!
    cout << "After erase: " << d.size() << endl;
    for (int i : d)
        cout << i << " ";

    cout << endl
         << (d.max_size() == d2.max_size()) << endl;
    // max_size gives the largest possible deque on the system!

    // erase() function changes size but has no effect on max_size i.e. memory allocated...!
    // Unlike vector, the memory is not contiguous in case of a deque and hence it uses more memory than a vector

    return 0;
}