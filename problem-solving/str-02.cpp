#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
    static string reverseWords(string);
};

void reverseString(string &s)
{
    int st = 0;
    int e = s.length() - 1;
    while (st < e)
    {
        swap(s[st++], s[e--]);
    }
}

string Solution::reverseWords(string s)
{
    vector<string> ans;
    string str, string_ans;

    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
        {
            str.push_back(s[i]);
        }
        else
        {
            // we need to reduce the multiple spaces if any (contiguous, trailing)
            // since there are words with min 2 chars
            if (str.empty())
            {
                // str.push_back(' ');
                continue;
            }
            reverseString(str);

            // store this string in the vector now
            ans.push_back(str);
            // clear the string
            str.clear();
        }
    }
    if (!(str.empty()))
    {
        reverseString(str);
        ans.push_back(str);
    }
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            string_ans.push_back(ans[i][j]);
        }
        if (i != ans.size() - 1)
            string_ans.push_back(' ');
    }

    return string_ans;
}

int main(int argc, char const *argv[])
{
    string s = "the sky is blue";
    // string s = "  hello   world  ";
    for(auto e:s) cout << e;
    cout << endl;
    string str = Solution::reverseWords(s);
    for(auto e:str) cout << e;
    cout << "[" << endl;
    return 0;
}

// void Solution::reverseWords(vector<char> &s)
// {
//     vector<string> ans;
//     string str;

//     for (int i = s.size()-1; i >= 0; i--)
//     {
//         if (s[i] != ' ')
//         {
//             str.push_back(s[i]);
//         }
//         else {
//             // we need to reduce the multiple spaces if any (contiguous, trailing)
//             // since there are words with min 2 chars
//             if (str.empty())
//             {
//                 // str.push_back(' ');
//                 continue;
//             }
//             reverseString(str);

//             // store this string in the vector now
//             ans.push_back(str);
//             // clear the string
//             str.clear();
//         }
//     }
//     if (!(str.empty())) {
//         reverseString(str);
//         ans.push_back(str);
//     }
//     s.clear();
//     for (int i = 0; i < ans.size(); i++)
//     {
//         for (int j = 0; j < ans[i].size(); j++)
//         {
//             s.push_back(ans[i][j]);
//         }
//         if(i != ans.size()-1) s.push_back(' ');
//     }
// }