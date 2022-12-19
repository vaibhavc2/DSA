#include <iostream>
using namespace std;

// std::string
// memory is allocated dynamically and in contiguous manner
// but remember: it is not derived from vectors and the implementation is quite similar
// std::string stores its data internally in the form of a null-terminated C-string, but in normal usage does not allow you to access the null terminator, so normally there is no '\0' in std::string to use in the code 

string reverseString(string rev)
{
    // no need of the following if we pass string by value and not by reference
    // -------------------------------------------------------
    // copying s into rev
    // string rev;
    // string::iterator start = s.begin();
    // for (int i = 0; i < s.length(); i++)
    // {
    //     rev.push_back(*start);
    //     advance(start, 1);
    // }
    // -------------------------------------------------------

    string::iterator st = rev.begin();
    
    // string::iterator end = rev.begin() + (rev.length() - 1);
    string::reverse_iterator end = rev.rbegin(); // reverse_iterator moves reverse!
    // auto end = rev.rbegin();

    for (int i = 0; i < rev.length() / 2; i++)
    {
        swap(*st, *end);
        advance(st, 1); // st++;
        advance(end, 1); // end++;
        // end = rev.begin() + (rev.length() - (i + 1) - 1);
    }
    
    return rev;
}

bool checkEqual(string &s1, string &s2)
{
    // s1.compare(s2); ==> is used to compare lengths of strings
    if (s1.compare(s2) != 0)
    {
        return false;
    }
    auto itr_s1 = s1.begin();
    auto itr_s2 = s2.begin();
    int count = 0;
    for (int i = 0; i < s1.length(); i++)
    {
        if (*itr_s1 == *itr_s2)
        {
            count++;
        }        
        itr_s1++;
        itr_s2++;
    }

    if (count == s1.length())
    {
        return true;
    }
    
    return false;
}


bool checkPalindrome(string s)
{
    string rev = reverseString(s);
    if (checkEqual(s, rev))
    {
        return true;
    }
    return false;
}

int main(int argc, char const *argv[])
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str); // this accepts " " i.e. empty space as well

    cout << "Reverse of the string: " << reverseString(str) << endl;

    if (checkPalindrome(str))
    {
        cout << "This string is a palindrome!" << endl;
    }
    
    return 0;
}