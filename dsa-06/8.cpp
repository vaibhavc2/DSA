#include <iostream>
using namespace std;
// More details about Pointers and char const* arr[]
int main(int argc, char const *argv[])
{
    // Read types right to left:
    // const always binds to the left (unless it is on the very left)

    // char *const arr[]

    //                ^^  Array of
    //       ^^^^^        const
    //      ^             pointer to
    // ^^^^               char
    // An array of "const pointer" to char

    // So the pointers in the array can not be modified.
    // But what they point at can be modified.

    // Command line arguments passed:
    // NOTE: can change the name of argc and *argv
    // in int main(int argc, char const *argv[])
    // char const *argv[] ==> is array of pointers to 'const char' or 'char const' i.e. char values which can't be changed

    const char *a = "a";
    const char *b = "b";
    const char *c = "c";
    char const *abc[] = {a, b, c};
    cout << *a << *b << *c << endl;
    // (*a)++; // not possible
    // but
    a = b; // this is fine
    cout << *a << *b << *c << endl;
    // printing the number of command line arguments given:
    cout << argc << endl; // by default 1 argument is always given (file name)

    return 0;
}