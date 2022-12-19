#include <iostream>
using namespace std;

// Pointers passed to functions:
// here a copy of the pointer to the value is sent, so the pointer can't be changed, but the value it is pointing to can be changed

void print(int* p)
{
    cout << *p << endl;
}

void print2(int** p)
{
    cout << **p << endl;
}

void update(int *p)
{
    (*p)++; // *p++ is incorrect!
}

void update2(int** ptr)
{
    (**ptr) += 12;
}

int a = 0;
void updatePointer(int* &x) // passing the pointer by reference so that we can change the value of the pointer
{
    // change the value of the pointer: i.e. change the address it is pointing to
    x = &a;
}

int b = 69;
int *pointer = &b;
void updateDoublePointer(int** &p)
{
    // p = &pointer;
    // OR
    *p = pointer;
}

// Similar working
// void arrayFunc(int *arr)
//OR
void arrayFunc(int arr[])
{
    (*arr)++;
}

void printArr(int *p, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << i[p] << " ";
    }
    cout << endl;
}

void printReverseArr(int *p, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << *(p-i) << " ";
        // cout << p[i] << " "; // this will not work because p[i] == *(p+i)
    }
    cout << endl;
}

int main(int argc, char const *argv[])
{
    int value = 5;
    int *ptr = &value;

    print(ptr);
    update(ptr);
    print(ptr);

    updatePointer(ptr);
    print(ptr);

    // using double pointers
    int** p = &ptr;
    print2(p);
    update2(p);
    print2(p);

    updateDoublePointer(p);
    print2(p);

    // since arrays are always sent as pointers by default, we can send any pointer to the function, and in this way we can also send only a part of array if we want (starting from the address we want)
    int arr[] = {1,2,3,4,5};
    arrayFunc(arr+4); // updates element at index '4' to 6
    cout << 4[arr] << " " << arr[4] << " " << *(arr+4) << endl; // 6
    printArr(arr+1, 4);
    printReverseArr(arr+4, 5);

    return 0;
}