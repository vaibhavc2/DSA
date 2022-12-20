// Reference Variable : Another name of a variable/ object (or alias) which is also mapped to same memory location
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int i = 5;
    int &j = i; // reference variable
    cout << i << " " << j << endl; // same value, same memory, just different name
    cout << &i << " " << &j << endl; // same memory address

    /*
    basically, in the symbol table:
    i --> 5 at address, say 796
    then, the reference variable j will be such that:
    j --> 5 at the same address 796
    so,
    'i' and 'j' both mapped to the same memory in the symbol table
    */

    return 0;
}