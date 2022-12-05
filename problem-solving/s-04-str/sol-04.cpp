// GFG Q: return the max occurring character in the string
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    static char maxOccurrenceInString(string &s);
    static char maxOccurrenceInString2(string &s);
};

// using HashTable, time-complexity: O(n)
char Solution::maxOccurrenceInString(string &s)
{
    char ans = (char)0; // can't use NULL as it's reserved for pointers by the compiler

    // use tolower() if needed as per Q, if it demands case-insensitivity: no diff b/w uppercase, lowercase

    unordered_map<char,int> freq_map;
    for (auto &e:s) freq_map[e]++; // store freq. of all chars

    // finding max freq
    int maxi = -1;
    for (auto i:freq_map)
    {
        if(i.second > maxi) maxi = i.second;
    }

    // store all chars with max freq
    string ans_str;
    for (auto itr:freq_map) {
        if(itr.second == maxi) ans_str.push_back(itr.first); 
    }

    // return lexicographically smaller character as answer
    auto min_char_itr = min_element(ans_str.begin(), ans_str.end());
    ans = *min_char_itr;
    return ans;
}

// Another method with O(n) time complexity:
// Hashing using array-mapping
// only works if we are dealing with alphabets only!
char Solution::maxOccurrenceInString2(string &s)
{
    // to store ch frequency
    int ch_freq[52] = {0};
    // would have used the following if we had to make the program case-insensitive: no diff b/w uppercase, lowercase
    // int ch_freq[26] = {0};

    // store ch freq
    for (int i = 0; i < s.size(); i++)
    {
        //lowercase
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            ch_freq[(s[i]-'a')]++;
        }
        else // uppercase
        {
            ch_freq[25+(s[i]-'A')]++;
        }
    }

    // find max freq.
    int maxi = -1;
    int index = -1;
    for (int i = 0; i < 52; i++)
    {
        if(maxi < ch_freq[i]) {
            maxi = ch_freq[i];
            index = i;
        }
    }

    char ans = 0;
    if(index < 26){
        ans = 'a' + index;
    }
    else {
        ans = 'A' + index - 26;
    }

    return ans;
}

int main(int argc, char const *argv[])
{
    string str;
    cout << "Enter a string: ";
    getline(cin, str);
    cout << "Max occurring character in the input string: " << Solution::maxOccurrenceInString2(str) << endl;
    return 0;
}