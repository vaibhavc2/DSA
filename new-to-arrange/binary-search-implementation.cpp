#include <bits/stdc++.h>
// using namespace std;

// Binary Search Implementation with Iterators: return type 'bool'
// ascending order sorted vector

//* keyword 'typename' and 'class' are completely interchangeable and work exactly same in case of Templates

template<typename T> bool binarySearch(typename std::vector<T>::iterator f_itr, typename std::vector<T>::iterator b_itr, const T& key)
{
    // T* f_ptr = &(*f_itr);
    // T* b_ptr = &(*b_itr);
    // int const size = abs(f_ptr - b_ptr); // abs() : absolute value function // pointer arithmetic only allows substraction, and not other operations like +, -, /
    int const size = abs(f_itr - b_itr); // iterators act like pointers only
    int search_space = size;

    typename std::vector<T>::iterator mid_itr = std::next(f_itr, size/2);

    while (f_itr != b_itr)
    {
        // ! VERY BAD MISTAKE: while trying to optimise, one may think to do this, but it can cause errors because at times, f_itr & b_itr may be pointing to some address outside the memory block, e.g. at the start, b_itr points one next to the end of the memory block!
        // if (*mid_itr == key || *f_itr == key || *b_itr == key)

        if (*mid_itr == key)
        {
            return true;
        }
        else if (*mid_itr > key)
        {
            // ! v.end() returns iterator to next memory location after the last element's memory location. This way it helps to correctly predict size and also helps to iterate over the given memory block correctly
            //// b_itr = std::prev(mid_itr);
            // The above one using std::prev() gives the iterator such that it reduces the search space. It is a good practice to use the standard way of end iterators: point next memory location after the last element's memory location

            b_itr = mid_itr;
        }
        else
        {
            f_itr = std::next(mid_itr);
        }
        // here we use search_space instead of size
        search_space = abs(f_itr - b_itr);
        mid_itr = std::next(f_itr, search_space/2);
    }

    // std::cout << search_space << std::endl;

    return false;
}

int main(int argc, char const *argv[])
{
    // todo Testing Multiple Test Cases:
    // std::vector<int> v = {2, 5, 9, 17, 99, 102, 301, 1990, 5678, 93493};
    // int key = 5678;
    // std::vector<int> v = {2,2,2,2,3,3,3,3,3,3,3,3,3,3,3,3,3,4,5,7,7,7,8,9};
    // int key = 3;
    // std::vector<int> v = {2};
    // int key = 3;
    // std::vector<double> v = {3.5, 6.7, 8.9 ,2323.65654, 99697.9785667};
    // double key = 99697.9785667;
    std::vector<char> v = {'a', 'b', 'c', 'd', 'e', 'f'};
    char key = 'f';
    binary_search(v.begin(), v.end(), key);

    // ! This is WRONG:
    // * int* ptr = &key;
    // * int* ptr2 = NULL;
    // * ptr2 = key + 1;

    // * v.end() returns iterator to next memory location after the last element's memory location. This way it helps to correctly predict size and also helps to iterate over the given memory block correctly
    // if(binarySearch<int>(v.begin(), v.end(), key))
    //     std::cout << "true" << "\n";
    // if(binarySearch<double>(v.begin(), v.end(), key))
    //     std::cout << "true" << "\n";
    if(binarySearch<char>(v.begin(), v.end(), key))
        std::cout << "true" << "\n";

    return 0;
}