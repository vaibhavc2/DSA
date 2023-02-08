#include <bits/stdc++.h>
using namespace std;

// STL Vector
// functions as a dynamic array, uses heap memory and not stack! It also uses contiguous memory locations

// arrays are always passed by reference or pointer no matter how you write, (though this is not true for vectors)
// You can pass a vector either by value or by reference
void func(vector<int> v);  // a copy of this vector will be created for this function to do processing on it.
void func(vector<int> &v); // address of first element is passed, this is just like array...

int main(int argc, char const *argv[])
{
    vector<int> v_arr;
    vector<int> v1(5);                // make vector with size 5, capacity 5, and initialize with 0
    vector<int> v2(5, 2);             // similar to v1, but initialized to 2
    vector<int> v3 = {1, 2, 3, 4, 5}; // can construct a vector in this way also.
    cout << "Capacity v1: " << v1.capacity() << endl;
    cout << "Capacity v2: " << v2.capacity() << endl;
    cout << "Capacity v3: " << v3.capacity() << endl;
    cout << "Capacity v_array: " << v_arr.capacity() << endl;
    v_arr.push_back(1);
    v_arr.push_back(2);
    v_arr.push_back(3);
    cout << "Size: " << v_arr.size() << endl;
    cout << "Capacity: " << v_arr.capacity() << endl;

    // vector<int> last(v_arr); // last() is vector move constructor, it copies the input vector given to it. the newly created vector contains the exact same contents as the input vector
    vector<int> copied(v_arr); // We can use any other name as well!

    for (int &i : copied)
        cout << i << endl;

    // vector doubles it's capacity everytime it gets full and needs more...
    // basically it copies itself to a new location with double the contiguous memory bandwidth, and then removes the previous one from the memory

    int mini = *(min_element(v_arr.begin(), v_arr.end()));
    int maxi = *(max_element(v_arr.begin(), v_arr.end()));
    cout << "MIN: " << mini << " , MAX:" << maxi << endl;
    cout << "Element at 2nd index: " << v_arr.at(2) << endl;
    cout << "First element: " << v_arr.front() << endl;
    cout << "Last element: " << v_arr.back() << endl;

    cout << "Before pop" << endl;
    // for loop can be used in the following way for vector:
    for (int element : v_arr)
    {
        cout << element << endl;
    }
    v_arr.pop_back(); // pop/clear one element from the back(last), it's capacity remains same!

    cout << "After pop" << endl;
    cout << "Size: " << v_arr.size() << endl;
    cout << "Capacity: " << v_arr.capacity() << endl;
    for (int i : v_arr)
    {
        cout << i << endl;
    }

    v_arr.clear(); // clears the vector; removes all its elements; but its capacity still remains same!

    cout << "Size: " << v_arr.size() << endl;
    cout << "Capacity: " << v_arr.capacity() << endl;

    v_arr.shrink_to_fit(); // reduces the capacity to fit the size, destroys all elements beyond the capacity

    cout << "Size: " << v_arr.size() << endl;
    cout << "Capacity: " << v_arr.capacity() << endl;

    v_arr.resize(5); // changes the size of the vector, and doesnot destroy the elements (just change size, and only increase the capacity if needed, but it cannot decrease the capacity)

    cout << "Size: " << v_arr.size() << endl;
    cout << "Capacity: " << v_arr.capacity() << endl;

    return 0;
}