#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

// std::transform() function in <algorithm> is useful to perform a function on an array or a string

int main(int argc, char const *argv[])
{
    string s1 = "abcde";
 
    // using transform() function and ::toupper in STL
    transform(s1.begin(), s1.end(), s1.begin(), ::toupper);
    cout<<s1<<endl;
 
    // s2 is the string which is converted to lowercase
    string s2 = "WXYZ";
 
    // using transform() function and ::tolower in STL
    transform(s2.begin(), s2.end(), s2.begin(), ::tolower);
    cout<<s2<<endl;
    return 0;
}