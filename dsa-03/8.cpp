#include <iostream>
#include <list>

using namespace std;
// List DS STL : its implementation in the backend has been done by using doubly linked list (two pointers for each element: front as well as back!)

// Most methods of list are also implemented such that their time complexity is O(1), erase is O(n)

int main(int argc, char const *argv[])
{
    list<int> l;
    l.push_back(1);
    l.push_front(2);
    l.push_back(5);

    // at() method is not available for lists

    for (int i : l)
        cout << i << " ";

    cout << endl;
    cout << "Size: " << l.size() << endl;
    l.erase(l.begin());
    // l.erase(l.begin(), l.end()); // erases the whole list
    // l.erase(l.begin() + 1, l.end()); // this is not allowed in list!
    for (int i : l)
        cout << i << " ";
    cout << endl;

    list<int> l2(l); // copy the other list l to l2
    cout << l2.size() << endl;

    list<int> l3(5, 100);
    for (int element : l3)
    {
        cout << element << " ";
    }
    cout << endl;
    return 0;
}