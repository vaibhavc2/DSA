// // C++ program to convert a decimal
// // number to binary number

// #include <iostream>
// using namespace std;

// // function to convert decimal to binary
// void decToBinary(int n)
// {
//     // array to store binary number
//     int binaryNum[32];

//     // counter for binary array
//     int i = 0;
//     while (n > 0)
//     {

//         // storing remainder in binary array
//         binaryNum[i] = n % 2;
//         n = n / 2;
//         i++;
//     }

//     // printing binary array in reverse order
//     for (int j = i - 1; j >= 0; j--)
//         cout << binaryNum[j];
// }

// // Driver program to test above function
// int main()
// {
//     int n = 174578978;
//     decToBinary(n);
//     return 0;
// }
// ------------------------------------------------------------------------
// CPP program to Decimal to binary conversion
// using bitwise operator
// Size of an integer is assumed to be 32 bits
// #include <iostream>
// using namespace std;

// // Function that convert Decimal to binary
// void decToBinary(int n)
// {
//     // Size of an integer is assumed to be 32 bits
//     for (int i = 31; i >= 0; i--)
//     {
//         int k = n >> i;
//         if (k & 1)
//             cout << "1";
//         else
//             cout << "0";
//     }
// }

// // driver code
// int main()
// {
//     int n = 5;
//     decToBinary(n);
// }
// ------------------------------------------------------------------------
// #include <bits/stdc++.h>
// using namespace std;

// string DecimalToBinary(int num)
// {
//     string str;
//     while (num)
//     {
//         if (num & 1) // 1
//             str += '1';
//         else // 0
//             str += '0';
//         num >>= 1; // Right Shift by 1, (num >> = 1;)
//     }
//     return str;
// }

// void reverse(string str)
// {
//     for (int i = str.size() - 1; i >= 0; i--)
//         cout << str[i];
// }

// int main()
// {
//     int num = 174893; // only accepts >0
//     reverse(DecimalToBinary(num));
//     return 0;
// }
// ------------------------------------------------------------------------
// C++ implementation of the approach
// #include <cmath>
// #include <iostream>
// using namespace std;

// #define ull unsigned long long int

// // Function to return the binary
// // equivalent of decimal value N
// int decimalToBinary(int N)
// {
//     // To store the binary number
//     ull B_Number = 0;
//     int cnt = 0;
//     while (N != 0)
//     {
//         int rem = N % 2;
//         ull c = pow(10, cnt);
//         B_Number += rem * c;
//         N /= 2;
//         // Count used to store exponent value
//         cnt++;
//     }
//     return B_Number;
// }

// // Driver code
// int main()
// {
//     int N = 345; // accepts >=0
//     cout << decimalToBinary(N);
//     return 0;
// }

// This code is contributed by Sania Kumari Gupta (kriSania804)
// ------------------------------------------------------------------------
// C++ program to convert a decimal number
// to its binary form.

// including header file
// #include <bits/stdc++.h>
// using namespace std;

// // Function to convert a decimal number
// // to its binary form
// string decimalToBinary(int n)
// {
//     // finding the binary form of the number and
//     // converting it to string.
//     string s = bitset<64>(n).to_string();

//     // Finding the first occurrence of "1"
//     // to strip off the leading zeroes.
//     const auto loc1 = s.find('1');

//     if (loc1 != string::npos)
//         return s.substr(loc1);

//     return "0";
// }

// // Driver Code
// int main()
// {
//     int n = -11;

//     // Function call
//     cout << decimalToBinary(n);

//     return 0;
// }

// ------------------------------------------------------------------------

// C++ program to convert Decimal to Binary Number
#include <iostream>
#include <math.h>
#include <bitset>
using namespace std;

int main()
{

    // input number
    int number = 867; // number > 0
    int n = (int)(log2(number));

    // binary output
    // using the inbuilt function
    cout << "the binary number is : "
         << bitset<64>(number).to_string().substr(64 - n - 1);
}
