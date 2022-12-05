// STL : Standard Template Library in C++
// using bits/stdc++.h may seem good as it includes all other libraries (like vector, array, string) as well otherwise we have to write to include each library separately, BUT it is not good practice: it slows down code, decreases portability, and even changing the compiler may break some things!
// so dont use this:
// #include <bits/stdc++.h>

// instead use:

#include <iostream>
#include <array>

using namespace std;

// STL Array

int main(int argc, char const *argv[])
{
    // this is normal array in cpp
    // int basic_array[] = {1, 2, 3};
    // int basic_array[3] = {1, 2, 3}; // both are correct

    // STL array in cpp
    array<int, 4> arr{1, 2, 3, 4};
    // array<int, 4> arr = {1,2,3,4};
    // array<int> arr = {1, 2, 3, 4}; // this is incorrect because you have to mention the number of elements in array
    // STL array is also static array and similar DS to normal array in working

    int size = arr.size();

    cout << "Element at second index: " << arr.at(2) << endl;
    cout << "Empty or NOT? " << arr.empty() << endl;
    cout << "First Element: " << arr.front() << endl;
    cout << "Last Element: " << arr.back() << endl;

    return 0;
}