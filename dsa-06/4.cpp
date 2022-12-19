// Pointers: a bit review
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // int *a; 
    // this is called "wild pointer" & it is very wrong practice as the pointer will be assigned a random address and it can then overwrite it....

    // instead, always initialize a pointer as following:
    int* ptr = NULL; // remember: NULL is reserved for pointers only in C++, hence NULL Pointer
    int* ptr2 = 0; // same as above
    double* p2 = 0; // same as above
    string* p3 = 0;
    // (any custom data type, or class) * ==> declare pointer to any object...
    // data-type at the start indicates the data-type of the value stored in the address to which the pointer points to.
    // Always remember to initialise a nullptr and then use it:
    /*
    int *p = 0;
    p = &x;
    *p = 8; // then it is valid to use the pointer and change the value it is pointing to
    */

    // Size of any pointer in 64-bit machines is 8 bytes
    cout << sizeof(ptr) << endl; //8
    cout << sizeof(*ptr) << endl; //4 (because value at ptr is int which is of 4 bytes)
    cout << sizeof(&ptr) << endl; //8 (because the address needs 8 bytes)

    // printing null pointers
    cout << ptr << endl;
    cout << ptr2 << endl;

    int a = 5;

    // symbol table: Symbol Table is an important data structure created and maintained by the compiler in order to keep track of semantics of variables i.e. it stores information about the scope and binding information about names, information about instances of various entities such as variable and function names, classes and objects.

    // 'a' is allocated 4 bytes in stack memory and the address of the first byte is mapped to the variable 'a' by the compiler in the symbol table (at compile time)
    // Hence, '&a' helps to access the address of 'a' and 'a' helps to access the value in it.

    int* ptr3 = &a;
    (*ptr3)++; // deference operator '*': give value stored at the given address
    cout << *ptr3 << endl;

    cout << ptr3 << endl;
    ptr3++; // this moves the pointer to the next address, here it is int pointer, so it will start pointing to the address just next to the last byte of previous allocated int.

    // other ways of implementation of ptr++
    // ptr3 = ptr3 + 1;
    // std::advance(ptr3, 1);

    int* pp1 = std::next(ptr3, 1);
    ptr3 = pp1;
    // following also works
    ptr3 += 3;

    cout << ptr3 << endl;

    ptr3--;
    // another implementation
    int* pp2 = std::prev(ptr3, 1);
    ptr3 = pp2;
    ptr3 -= 3;

    // std::advance, std::next, and std::prev all work similar for iterators also.

    cout << ptr3 << endl;

    int** ptr4 = &ptr3; // double pointer: storing address of a pointer
    int*** ptr5 = &ptr4; // triple pointer: storing address of a double pointer

    int*** ptr6 = &(*ptr5);
    
    //copying a pointer
    int* q = ptr3;
    
    int i = 3;
    // void pointer
    void* vptr = &i; // void pointer can store any address and doesnot depend on the data type of the value in the address
    void* vptr2 = &ptr4;

    // but whenever using it, we have to typecast it accordingly:
    cout << (int*)vptr << endl;
    cout << (int***)vptr2 << endl;
    // to print values: we have to deference them accordingly
    cout << *(int*)vptr << endl;
    cout << ***(int***)vptr2 << endl;

    // dangling pointer concept:
    int *my_list = (int*)malloc(i * sizeof(int)); // allocate a linked list in the heap memory (dynamically) using malloc which returns a void pointer which is then typecasted into int*

    // now if we free this memory
    free(my_list); // free() is used to free memory allocated using malloc and calloc, i.e. C style

    // 'delete' is used to deallocate memory allocated using 'new' in C++ style
    char* c_ptr = NULL;
    c_ptr = new char;
    *c_ptr = 67;
    cout << *c_ptr << endl;
    delete c_ptr;
    // delete[] is used for a block of memory!

    // Now, both of the following are 'Dangling Pointers' because the memory allocated to them has been deallocated or freed...!!! So they may point to anything.....
    cout << *c_ptr << " " << *my_list << endl;
    // Hence never use Dangling Pointer!
    
    return 0;
}