#include <iostream>
using namespace std;

// Dynamic Memory Allocation according to C++ Style (in heap memory)
// Run-Time allocation of memory, as opposed to compile-time
// use of 'new' keyword

// new (data-type) ==> allocates the object/variable in heap memory and then returns a pointer of the same data-type, pointing to the address of the variable/object allocated in the heap memory

int main(int argc, char const *argv[])
{
    // here in case of int, memory block of the size of 'int' will be allocated in the heap memory and the address of it's first byte will be returned.
    // the 'int' pointer 'x' is created in the stack memory and it stores the address returned from dynamic memory allocation
    // The symbol-table mapping exists only for stack memory! i.e. for the pointer 'x' there is symbol-table mapping

    int* x = new int; // uses total of (8 + 4) = 12 bytes. 8: in stack (for pointer) & 4: in heap (for dynamic memory allocation of int)
    *x = 1;
    // OR we can use this:
    // int* x = new int(1);
    cout << *x << endl;
    char* ch = new char('A');
    cout << (char)(*ch + *x) << endl;

    int n = 6;
    // cin >> n;
    int* arr = new int[n]; // dynamic memory allocation of array
    for (int i = 0; i < n; i++)
    {
        *(arr + i) = i;
        cout << i[arr] << " ";
    }
    cout << endl << sizeof(arr) << endl; // here, this prints the size of the pointer and not the array!

    // Must delete the dynamically allocated memory, otherwise it causes Memory Leak. There is no automatic memory management (garbage collectors in Java) in C++. So whenever we use the keyword 'new', we must use delete or delete[] respectively to delete the dynamically allocated heap memory.
    delete x, ch;
    delete[] arr;

    // Statically allocated memory:
    // non-static ('static' keyword) & local variables are allocated memory mostly in stack memory and in some cases, in cpu registers.
    // these are called automatic variables/objects OR objects/variables with automatic storage duration: these are automatically deleted once their scope is finished (say, a function() has its own stack with some allocated variables, and they are freed automatically once the function call is over.)

    return 0;
}