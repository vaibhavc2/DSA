// Inline Functions
#include <iostream>
using namespace std;

template<typename T> 
inline T getMax(T& a, T& b)
{
    return (a > b)? a : b;
}

// inline functions act just like macros!
// they are expanded in line by the compiler (not preprocessor)
// It is not necessary that the compiler respects the inline 'keyword', it depends on the compiler

// Generally
// if inline function is of:
// 1 line: the compiler acts on inline & makes the function inline
// 2-3 lines: the compiler may or may not make the function inline! (no guarantee)
// >3 lines: compiler will never make the function inline!

int main(int argc, char const *argv[])
{
    int a = 5, b = 7;
    double x = 19.87, y = 23.65;

    // int maxi = (a > b)? a : b;
    int maxi = getMax<int>(a, b);
    double maxd = getMax<double>(x, y);

    cout << maxi << " " << maxd << endl;

    return 0;
}