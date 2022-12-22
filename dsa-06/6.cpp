// Pointers review revision continued....
// Char arrays with pointers and 
#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    // both the following are C style strings: char arrays and mean the same thing
    char name[] = "Vaibhav Chopra"; // adds a '\0' at the end
    char ch_arr[20] = "Vaibhav Chopra"; // adds a '\0' at the index '14' and from '15' to '19' remain uninitialised...

    // Dont generally use the following way of creating strings (or char arrays). (using char pointer) Because it always creates a const char[] and hence we can never change any value of the characters in it.

    // 'const' keyword usage:
    // char       *      mutable_pointer_to_mutable_char;
    // char const *      mutable_pointer_to_constant_char;
    // char       *const constant_pointer_to_mutable_char;
    // char const *const constant_pointer_to_constant_char;
    // here, constant pointer means ki address jisko point kr re ho, usko change nhi kr skte & constant char means ki jis value ko point kr re ho usko change ni kr skte

    // Both the following mean same thing : that it is a pointer to a constant char, but not a constant pointer!!!! (BAD PRACTICE)
    // const char *c_arr = "abcde"; // adds a '\0' at the end
    // const char *c_arr = "abcde"; // adds a '\0' at the end

    // But as a good practice, we make a constant pointer: i.e. it must always point to the same address
    char const* const c_arr = "abcde"; // adds a '\0' at the end
    // char* const c_arr = "abcde"; // gives WARNING because "abcde" is by default interpreted as const char[]
    // So, char const* const OR const char* const: both are valid!!!

    // C strings using char arrays can be made using 'char *const'
    // 'const' is used because there should be no provision to change the address which the char * stores (it must always store address of the first element of the char array)
    // char *c_array = "hello"; // is a very bad practice!! NEVER DO IT!!!!

    // can't do similar thing for other arrays like:
    // ERROR :: // const int *arr = [1,2,3,4,5];

    // VERY IMPORTANT:
    // std::cout has different implementation for char arrays.

    // The following prints the char array: (as opposed to printing the address of the char pointer)
    cout << name << endl;
    cout << ch_arr << endl;
    cout << c_arr << endl;
    cout << endl;
    // The following prints the address just like it should
    cout << &name << endl;
    cout << &ch_arr << endl;
    cout << &c_arr << endl;
    cout << endl;
    // The following prints the char array as opposed to print the address of the first element
    cout << &name[0] << endl;
    cout << &ch_arr[0] << endl;
    cout << &c_arr[0] << endl;
    cout << endl;
    // The following prints the value the char pointer is pointing to
    cout << *name << endl;
    cout << *ch_arr << endl;
    cout << *c_arr << endl;

    // The following also works fine hence:
    // char ch = 'a';
    int i = 0;
    // while(ch != '\0')
    // {
    //     ch = *(name + i);
    //     cout << ch;
    //     i++;
    // }
    // cout << endl;

    i = 0;
    char *q = &name[0]; // this works perfectly fine
    // But can't do this:
    // char *q = &c_arr;
    // char *q = c_arr;
    // char *q = name;
    while(*q != '\0')
    {
        *q = *(&name[0] + i);
        cout << *q;
        i++;
    }
    cout << endl;

    // The following also prints the full char array
    char *cht = &ch_arr[0];
    cout << cht << endl;

    // This basically works for any char pointer. It will try to print till it doesn't find a '\0'
    char temp = 'x';
    char *t = &temp;
    cout << t << endl;

    char const* xyz = &temp;
    
    char* str1 = new char[5]; // this just allocates a block with 5 chars in heap memory and uninitialised. It doesn't automatically add a '\0' as it is not a string.
    // So,
    // It is Better to initialise a dynamically allocated char array with '\0' i.e. null terminator
    char* str2 = new char[5]();
    cout << str1 << endl; // prints random things (garbage values)
    cout << str2 << endl; // prints nothing since it is initialised by '\0'

    // c_arr[2] = 'v';
    return 0;
}