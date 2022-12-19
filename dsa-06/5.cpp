// Pointers review revision continued....
// Pointers with arrays
#include <iostream>
using namespace std;

int main()
{
    // in C style programming, 'arr' by default is the pointer to the first element of the array
    int arr[5] = {1, 2, 3, 4, 5};
    cout << arr << " " << *arr << endl;
    cout << &arr[0] << " " << arr[0] << endl;
    // 'arr' basically points to the first byte (of any data-type) allocated to the element
    for (int i = 0; i < 5; i++)
    {
        // IMPORTANT: we cannot advance the 'arr' pointer, since it is mapped in the symbol table, and The content of Symbol Table cannot be changed under any circumstances.
        // std::advance(arr, 1);
        // arr++;
        
        // But this is correct:
        // int *ptr = arr + i;
        // cout << *ptr << endl;

        // OR:
        cout << *(arr + i) << endl;
    }
    cout << endl;

    // Internally, the compiler implementation of arr[i] is like: (not same! but similar kind of a way) :: 
    // *(arr + i) == arr[i]

    int i = 2; // arr[2]
    int *p = arr + i;
    auto e = std::next(arr, i);
    cout << *e << " " << *p << endl; // prints arr[2]
    
    i++;
    // also, IMP::
    // i[arr] == *(i + arr)
    cout << i[arr] << " " << *(i + arr) << " " << *(arr + i) << endl;

    // The content of Symbol Table cannot be changed under any circumstances.
    // 'arr' is mapped to "the address of the first byte of the first element of the array" in the symbol table.
    // &arr, arr and &arr[0] all give address of the first byte of the first element of the array
    // there is no address of arr pointer: it is not stored in some separate address since &arr == arr
    cout << &arr << " " << arr << endl << &arr[0] << endl;

    int temp[10] = {0};
    cout << sizeof(temp) << endl;
    cout << sizeof(*temp) << endl;
    cout << sizeof(&temp) << endl;
    cout << &temp << " " << temp << endl << &temp[0] << endl;

    int* ptr = &temp[0];
    cout << ptr << endl;
    cout << *ptr << endl;
    cout << &ptr << endl;

    /*
    int i = 2;
    int *p = &i;
    int **q = &p;
        In Symbol Table:
            i --> address given to 'i'
            p --> address given to 'p'
            q --> address given to 'q'
    */

    // The following works perfectly fine:
    int tp[] = {11, 21, 31};
    int *pointer = tp;
    cout << pointer[2] << endl; //31
    cout << 2[pointer] << endl; //31

    // REMEMBER: *(ptr+i) = ptr[i] = i[ptr]
    int x = 11;
    int* y = &x;
    cout << y[4] << endl;
    cout << 4[y] << endl;
    cout << *(y+4) << endl;

    return 0;
}