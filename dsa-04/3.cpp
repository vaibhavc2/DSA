#include <iostream>
#include <map>
using namespace std;

// map is a DS with specific keys pointing only to a specific value.

// in MAP: erase(), insert(), count(), find() all these have time complexity of O(log n) because all these are implemented through Red Black Tree or Balance Tree (self balancing BST)

int main(int argc, char const *argv[])
{
    map<int, string> m;
    m[1] = "vaibhav";
    m[2] = "chopra";
    m[13] = "sher";
    m.insert({5, "Hello"});

    cout << "Size of map m: " << m.size() << endl;
    cout << "Value at key 5 -> " << m.at(5) << endl;

    cout << "Finding 13? " << m.count(13) << endl;
    cout << "Finding -13? " << m.count(-13) << endl;

    cout << endl
         << "Printing all keys with their specific values (Before Erase) -> " << endl;

    for (auto i : m)
        cout << i.first << " : " << i.second << endl;

    cout << endl;

    m.erase(5);

    cout << endl
         << "Printing all keys with their specific values (After Erase) -> " << endl;

    for (auto i : m)
        cout << i.first << " : " << i.second << endl;

    cout << endl;

    auto itr = m.find(1); // find() returns iterator which points to the given key
    for (auto it = itr; it != m.end(); it++)
        cout << (*it).first << " " << (*it).second << endl;
    // (*it) gives the pointer value and i gives the pointer address, hence we use (*it)
    cout << m.size() << endl;
    return 0;
}