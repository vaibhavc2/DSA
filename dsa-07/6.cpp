// Macros

// '#define' is a preprocessor directive for defining Macros in C++
// macros don't take any extra memory and are best shortening a code
// Macro is a piece of code in a program that is replaced by value of macro

#include <iostream>
using namespace std;

#define PI 3.14 // an example of Macro
// macros is better than decaring a variable with name PI, doesnot use extra storage
// Also it CAN'T be modified elsewhere like PI++
// hence macros are better to be used for constants OR some long and repititive code.

template <typename T>
class Area
{
public:
    static T circle(T&); 
    static T cone(T&, T&); 
    static T cylinder(T&, T&);
};

template <typename T> T Area<T>::circle(T& r)
{
    return (T)(PI * r * r);
}

template <class T> T Area<T>::cone(T& r, T& l)
{
    return (T)(PI * r * l);
}

template <typename T>
T Area<T>::cylinder(T& r, T& h)
{
    return (T)(2 * PI * r * h);
}

template <typename C> void happy(C& var)
{
    cout << ++var << endl;
    cout << "happy" << endl;
}

int main(int argc, char const *argv[])
{
    int a = 5;
    cout << Area<int>::circle(a) << endl;
    double b = 9.697;
    cout << Area<double>::circle(b) << endl;

    int r1 = 2, l1 = 6;
    cout << Area<int>::cone(r1, l1) << endl;
    double r2 = 7.89, l2 = 4.63;
    cout << Area<double>::cone(r2, l2) << endl;

    int h1 = 8;
    cout << Area<int>::cylinder(r1, h1) << endl;
    double h2 = 3.67;
    cout << Area<double>::cylinder(r2, h2) << endl;

    happy<int>(a);

    return 0;
}