// Calculate GCD or HCF in an optimised way other than normal brute force
// using Euclid's Algo
#include <iostream>
using namespace std;

// template<class T>
class GCD_HCF
{
public:
    int gcdRecursion(int, int);
    int gcdIterative(int*, int*);
};

int GCD_HCF::gcdIterative(int* a, int* b)
{
    if(*a==0) return *b;
    if(*b==0) return *a;

    while(*a != *b) {
        if(*a > *b)
            *a = *a - *b;
        else
            *b = *b - *a;
    }

    return *a;
}

// instead of subtraction, if we divide the smaller number, the algorithm stops when we find the remainder 0.
int GCD_HCF::gcdRecursion(int a, int b)
{
    if(a==0) return b;
    return gcdRecursion(b % a, a);
}

int main()
{
    int a, b;
    cin >> a;
    cin >> b;

    GCD_HCF obj;

    cout << obj.gcdIterative(&a, &b) << endl;
    cout << obj.gcdRecursion(a, b) << endl;
    
    return 0;
}