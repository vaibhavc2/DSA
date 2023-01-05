#include <iostream>
#include <vector>
using namespace std;

#define Type int // Type can be anything...

int main(int argc, char const* argv[])
{
    vector<Type> v1(10); // allocates the vector object on the stack, but the elements of 'Type' are allocated in free store i.e. heap
    vector<Type>* v2 = new vector<Type>(2); // allocates both the vector object and the elements of 'Type' in the free store or heap memory, but the pointer is allocated in the stack memory which points to the object allocated on the heap
    vector<Type*> v3; // allocates the vector on the stack and a bunch of pointers on the free store, but these pointers can individually point to any memory location (either heap or stack)

    // also the size of the vector object (of std::vector class) doesn't change if it contains more elements.
    // sizeof() function hence gives the size of the internal data used to store that vector instance: three pointers (_M_start, _M_finish, and _M_end_of_storage), 8 bytes each == 24bytes
    cout << sizeof(v1) << endl; // 24 bytes
    cout << sizeof(v2) << endl; // 8 bytes : size of pointer
    cout << sizeof(v3) << endl; // 24 bytes

    for (auto i: v1)
        cout << i << " ";
    cout << endl;

    delete v2;

    // delete[] v2 // ! This is not valid because v2 is a pointer pointing to a vector object allocated in the heap memory, and hence it will just delete that object.
    // * The vector manages its elements in the heap memory internally and we never have to delete the elements allocated by the vector in the heap memory explicitly.

    return 0;
}