// Patterns

#include <iostream>
using namespace std;

class Patterns
{
public:
    static void pattern1(int n);
    static void pattern2(int n);
    static void pattern3(int n);
    static void pattern4(int n);
    static void pattern5(int n);
    static void pattern6(int n);
    static void pattern7(int n);
    static void pattern8(int n);
    static void pattern9(int n);
    static void pattern10(int n);
    static void pattern11(int n);
    static void pattern12(int n);
    static void pattern13(int n);
    static void pattern14(int n);
    static void pattern15(int n);
    static void pattern16(int n);
    static void pattern17(int n);
    static void pattern18(int n);
    static void pattern19(int n);
    static void pattern20(int n);
    static void pattern21(int n);
    static void pattern22(int n);
    static void pattern23(int n);
    static void pattern24(int n);
    static void pattern25(int n);
    static void pattern26(int n);
    static void pattern27(int n);
    static void pattern28(int n);
    static void pattern29(int n);
    static void pattern30(int n);
    static void pattern31(int n);
    static void pattern32(int n);
    static void pattern33(int n);
    static void pattern34(int n);
    static void pattern35(int n);
};

void Patterns::pattern1(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void Patterns::pattern2(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}

void Patterns::pattern3(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i;
        }
        cout << endl;
    }
}

void Patterns::pattern4(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << i;
        }
        cout << endl;
    }
}

void Patterns::pattern5(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << i;
        }
        cout << endl;
    }
}

void Patterns::pattern6(int n)
{
    int c = 1;
    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << c;
        }
        c += 1;
        cout << endl;
    }
}

void Patterns::pattern7(int n)
{
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= n)
        {
            cout << j;
            j += 1;
        }
        cout << endl;
        i += 1;
    }
}

void Patterns::pattern8(int n)
{
    int i = 1;
    while (i <= n)
    {
        int j = 1;
        while (j <= i)
        {
            cout << j;
            j += 1;
        }
        cout << endl;
        i += 1;
    }
}

void Patterns::pattern9(int n)
{
    int i = 1;
    while (i <= n)
    {
        int j = n - i + 1;
        while (j >= 1)
        {
            cout << j;
            j -= 1;
        }
        cout << endl;
        i += 1;
    }
}

void Patterns::pattern10(int n)
{
    int i = n;
    while (i >= 1)
    {
        int j = n;
        while (j >= 1)
        {
            cout << i;
            j -= 1;
        }
        cout << endl;
        i -= 1;
    }
}

void Patterns::pattern11(int n)
{
    int i = n;
    while (i >= 1)
    {
        int j = n;
        while (j >= 1)
        {
            cout << j;
            j -= 1;
        }
        cout << endl;
        i -= 1;
    }
}

void Patterns::pattern12(int n)
{
    int i = n;
    while (i >= 1)
    {
        int j = i;
        while (j >= 1)
        {
            cout << j;
            j -= 1;
        }
        cout << endl;
        i -= 1;
    }
}

void Patterns::pattern13(int n)
{
    int i = n, count = 1;
    while (i >= 1)
    {
        int j = n;
        while (j >= 1)
        {
            cout << count << " ";
            j -= 1;
            count++;
        }
        cout << endl;
        i -= 1;
    }
}

void Patterns::pattern14(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void Patterns::pattern15(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void Patterns::pattern16(int n)
{
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << count << " ";
            count++;
        }
        cout << endl;
    }
}

void Patterns::pattern17(int n)
{
    for (int i = n; i >= 1; i--)
    {
        for (int j = i; j >= 1; j--)
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

void Patterns::pattern18(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int count = i;
        for (int j = 1; j <= i; j++)
        {
            cout << count << " ";
            count--;
        }
        cout << endl;
    }
}

void Patterns::pattern19(int n)
{
    char ch = 'A';
    // int ch_num = (int)ch; //explicit type conversion in c++
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << ch << " ";
        }
        ch++; // implicit type conversion in c++
        cout << endl;
    }
}

void Patterns::pattern20(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char ch = 'A';
        for (int j = 1; j <= n; j++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
}

void Patterns::pattern21(int n)
{
    char ch = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
}

void Patterns::pattern22(int n)
{
    char ch = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << ch << " ";
        }
        ch++;
        cout << endl;
    }
}

void Patterns::pattern23(int n)
{
    char ch = 'A';
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << ch << " ";
        }
        ch++;
        cout << endl;
    }
}

void Patterns::pattern24(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char ch = 'A' + i - 1;
        for (int j = 1; j <= n; j++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
}

void Patterns::pattern25(int n)
{
    for (int i = 1; i <= n; i++)
    {
        char ch = 'A' + i - 1;
        for (int j = 1; j <= i; j++)
        {
            cout << ch << " ";
            ch++;
        }
        cout << endl;
    }
}

void Patterns::pattern26(int n)
{
    char ch_1 = 'A' + n - 1;
    for (int i = 1; i <= n; i++)
    {
        char ch_2 = ch_1;
        for (int j = 1; j <= i; j++)
        {
            cout << ch_2 << " ";
            ch_2++;
        }
        ch_1--;
        cout << endl;
    }
}

void Patterns::pattern27(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int k = 0; k < i; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void Patterns::pattern28(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= n - i + 1; k++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void Patterns::pattern29(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i - 1; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= n - i + 1; k++)
        {
            cout << i;
        }
        cout << endl;
    }
}

void Patterns::pattern30(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= i; k++)
        {
            cout << i;
        }
        cout << endl;
    }
}

void Patterns::pattern31(int n)
{
    int count = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= i; k++)
        {
            cout << count;
            count++;
        }
        cout << endl;
    }
}

void Patterns::pattern32(int n)
{
    for (int i = 1; i <= n; i++)
    {
        int num = i;
        for (int k = 1; k <= i - 1; k++)
        {
            cout << " ";
        }
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << num;
            num++;
        }
        cout << endl;
    }
}

void Patterns::pattern33(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= i; k++)
        {
            cout << k;
        }
        for (int l = i - 1; l >= 1; l--)
        {
            cout << l;
        }
        cout << endl;
    }
}

void Patterns::pattern34(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }
        for (int k = 1; k <= i; k++)
        {
            cout << "*";
        }
        for (int l = i - 1; l >= 1; l--)
        {
            cout << "*";
        }
        cout << endl;
    }
}

void Patterns::pattern35(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i + 1; j++)
        {
            cout << j;
        }
        for (int l = 0; l < i - 1; l++)
        {
            cout << "*";
        }
        for (int m = 0; m < i - 1; m++)
        {
            cout << "*";
        }
        for (int k = n - i + 1; k >= 1; k--)
        {
            cout << k;
        }
        cout << endl;
    }
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    // Patterns::pattern1(n);
    // Patterns::pattern2(n);
    // Patterns::pattern3(n);
    // Patterns::pattern4(n);
    // Patterns::pattern5(n);
    // Patterns::pattern6(n);
    // Patterns::pattern7(n);
    // Patterns::pattern8(n);
    // Patterns::pattern9(n);
    // Patterns::pattern10(n);
    // Patterns::pattern11(n);
    // Patterns::pattern12(n);
    // Patterns::pattern13(n);
    // Patterns::pattern14(n);
    // Patterns::pattern15(n);
    // Patterns::pattern16(n);
    // Patterns::pattern17(n);
    // Patterns::pattern18(n);
    // Patterns::pattern19(n);
    // Patterns::pattern20(n);
    // Patterns::pattern21(n);
    // Patterns::pattern22(n);
    // Patterns::pattern23(n);
    // Patterns::pattern24(n);
    // Patterns::pattern25(n);
    // Patterns::pattern26(n);
    // Patterns::pattern27(n);
    // Patterns::pattern28(n);
    // Patterns::pattern29(n);
    // Patterns::pattern30(n);
    // Patterns::pattern31(n);
    // Patterns::pattern32(n);
    // Patterns::pattern33(n);
    // Patterns::pattern34(n);
    Patterns::pattern35(n);
    return 0;
}
