#include <iostream>
#include <set>
using namespace std;

// SET DS: it is implemented in C++ using BST: Binary Search Tree
// it stores only unique elements in it. if same element is pushed (say, 5 is pushed 2 times), still it is counted as one element. Also set returns the elements in Sorted order (ascending order)

int main(int argc, char const *argv[])
{
    set<int> s;

    s.insert(1);
    s.insert(3);
    s.insert(1);
    s.insert(4);
    s.insert(1);
    s.insert(5);
    s.insert(1);
    s.insert(3);
    // insert(), find(), erase() and count() have time complexity O(log n)
    // others like size(), begin(), end(), empty() have O(1)

    cout << "Size of set: " << s.size() << endl;
    for (auto i : s) // can use auto instead of int
        cout << i << " ";

    cout << endl;

    // We can use iterator in the following way:
    set<int>::iterator it = s.begin();
    // it++;
    // it++;

    // it+=2 is incorrect!!!

    // we can use advance() function to increment iterator:
    advance(it, 2);

    s.erase(it);

    for (auto i : s) // can use auto instead of int
        cout << i << " ";

    cout << endl;

    // count() function returns boolean that if the given element is present in the set

    cout << "is element 1 present: " << s.count(1) << endl;
    cout << "is element -1 present: " << s.count(-1) << endl;

    // find() tries to locate the given element in the set

    set<int>::iterator itr = s.find(3);

    // iterator is a pointer refering to a value at a particular position in the set or other STL Data Structures

    cout << "Value present at itr: " << *itr << endl;

    for (auto it = itr; it != s.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}