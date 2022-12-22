#include <iostream>
using namespace std;

// Pass by reference in functions
// already used as such:
// reference of the variable is passed to the function, hence function gets alias of the original variable passed and it is infact mapped to the same memory block pointing to the original one.
// Vo function memory to vahi use krlega, par usko naam alg de dega bs
// Same memory, different name!!

// (data-type)& ==> reference variable of a data-type


// GLOBAL Variables: is a BAD practice generally, as they can be modified anywhere!
// We can omit this danger using const:
int const b = 7;

// but for this example we use global variable for a particular use case:
int arr[] = {1,2,3,4,5};
void updatePointer(int*& x)
{
    x = arr + 4;
    // b++; // can't be modified, global variable with const!
}

void updateValue(int& x)
{
    x++;
}

// The following is very Dangerous practice. Never do it. Never return a reference to a local variable of the function because the memory with which the reference variable is mapped has local scope, so can't access that stack memory after function is over.
// It also returns a Warning from CPP compiler
// int& func(int a)
// {
//     int num = a;
//     int& ans = num;
//     return ans;
// }
// Similar case when returning a pointer: Be extra careful when returning a pointer. It should not be pointing to a memory location local only to that function itself.
// int* func(int a)
// {
//     int num = a;
//     int* ans = &num;
//     return ans;
// }

int main(int argc, char const *argv[])
{
    int *ptr = arr;
    updatePointer(ptr);
    cout << *ptr << endl;
    updateValue(*ptr);
    cout << *ptr << endl;
    return 0;
}