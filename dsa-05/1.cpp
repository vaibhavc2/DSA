#include <iostream>
// #include <vector>
using namespace std;

class StringsWithCharArrays
{
public:
    static int length(char arr[]);
    static char* findReverse(char arr[]);
    static void reverse(char arr[]);
    static bool checkEqual(char* a, char* b);
    static bool checkPalindrome(char arr[]);
};
// arrays are always passed by reference or pointer no matter how you write, (though this is not true for vectors)

int StringsWithCharArrays::length(char arr[])
{
    int i = 0;
    // int count = 0;
    while (arr[i] != '\0')
    {
        // count++;
        i++;
    }
    return i;
    // return count;
}


void StringsWithCharArrays::reverse(char arr[]){
    int length = StringsWithCharArrays::length(arr);

    // logic of mid;
    // int mid = (length - 1) / 2;
    // if (length % 2 != 0)
    // {
    //     for (int i = 0; i < mid; i++)
    //     {
    //         swap(arr[i], arr[length - 1 - i]);
    //     }
    // }
    // else
    // {
    //     for (int i = 0; i <= mid; i++)
    //     {
    //         swap(arr[i], arr[length - 1 - i]);
    //     }
    // }

    // another logic: a little better and compact
    // 2 pointer approach
    int s = 0;
    int e = length-1;
    while (s<e)
    {
        swap(arr[s++], arr[e--]);
    }
}


// Some concepts of 'C':
// Dynamic memory allocation
// malloc() allocates a memory block of given size (in bytes) and returns a pointer to the beginning of the block. malloc() doesn’t initialize the allocated memory. If you try to read from the allocated memory without first initializing it, then you will invoke undefined behavior, which will usually mean the values you read will be garbage. But malloc is faster.
// calloc() allocates the memory in heap but in 'contiguous' manner and also initializes every byte in the allocated memory to 0. If you try to read the value of the allocated memory without initializing it, you’ll get 0 as it has already been initialized to 0 by calloc().

char* StringsWithCharArrays::findReverse(char arr[])
{
    static char* rev_arr; // we use static because it's lifetime is the lifetime of the program, whereas without static, when we pass the pointer, it's memory may be deleted as the memory allocated to this function is deleted.

    int length = StringsWithCharArrays::length(arr);

    // rev_arr = (char *)malloc((length+1) * (sizeof(char)));
    rev_arr = (char *)calloc(length+1, sizeof(char));

    for (int i = 0; i < length; i++)
    {
        rev_arr[i] = arr[i];
    }
    
    int s = 0;
    int e = length-1;
    while (s < e)
    {
        swap(rev_arr[s++], rev_arr[e--]);
    }

    rev_arr[length] = '\0';

    return rev_arr;
}

bool StringsWithCharArrays::checkEqual(char* a, char* b) {
    int len1 = StringsWithCharArrays::length(a);
    int len2 = StringsWithCharArrays::length(b);

    if (len1!=len2)
    {
        return false;
    }
    int count = 0;
    for (int i = 0; i < len1; i++)
    {
        if (a[i]==b[i])
        {
            count++;
            continue;
        }
        else {
            break;
        }
    }
    if (count==(len1))
    {
        return true;
    }
    return false;
}


// A string is a palindrome if its reverse is same as original string.

bool StringsWithCharArrays::checkPalindrome(char arr[]) {
    char* rev = StringsWithCharArrays::findReverse(arr);
    if (StringsWithCharArrays::checkEqual(arr, rev))
    {
        return true;
    }
    return false;
}

char toLowerCase(char ch)
{
    if (ch >= 'a' && ch <= 'z')
    {
        return ch;
    }
    else // uppercase
    {
        char temp = ch - 'A' + 'a';
        return temp;
    }
    return 'a';
}

int main(int argc, char const *argv[])
{
    // a character array can store a string
    char name[20];
    cout << "Enter name: ";
    // cin >> name; // input in the form of string
    cin.getline(name, 20); // Now this accepts " " i.e. empty space

    // name[2] = '\0';
    // Null character '\0' is automatically added just next to where the string in the char array ends. It has ASCII value is '0'. It is used as terminator to know where the string is ending.

    // cin stops execution when you input : 'space', 'enter' (\n) or a 'tab' (\t)

    cout << "Your name is: " << name << endl; // this prints the char array till it finds the first '\0'

    cout << "Length of given string: " << StringsWithCharArrays::length(name) << endl;
    // StringsWithCharArrays::reverse(name); // string is reversed now, this was with void function
    char *rev_name = StringsWithCharArrays::findReverse(name);
    cout << "Reverse of the given string: " << rev_name << endl;
    cout << "Length of the Reverse: " << StringsWithCharArrays::length(rev_name) << endl;

    // A string is a palindrome if its reverse is same as original string.
    if (StringsWithCharArrays::checkPalindrome(name))
    {
        cout << "The entered string is a palindrome!" << endl;
    }

    cout << toLowerCase('H') << endl;

    return 0;
}