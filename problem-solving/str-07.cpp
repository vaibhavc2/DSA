// ? LeetCode Q: Permutation in String:

//* OPTIMIZATIONS
#ifndef DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#endif

#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

// Lambda expression (or function) for INPUT-OUTPUT to file
auto fileIO = [](){
    #ifdef LOCAL_PROJECT // or, ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
};

class Solution {
    // vector<string> possiblePermutations(string& s1) {
        
    // }
    // bool checkSubstr(string& substr, string& str) {

    // }
    bool mapSize(map<char, int>& m1, map<char, int>& m2) {
        for (int j = 0; j < m1.size(); j++)
        {
            cout << m1[j] << endl;
        }
        return true;
    }
public:
    bool checkInclusion(string s1, string s2) {
        // vector<string> permutations_s1 = possiblePermutations(s1);

        // for (int i = 0; i < permutations_s1.size(); i++)
        // {
        //     if (checkSubstr(permutations_s1[i], s2))
        //     {
        //         return true;
        //     }
        // }

        // sort(s1.begin(), s1.end());
        // string temp;
        // for (int i = 0; i < (int)s2.length(); i++)
        // {
        //     if (binary_search(s1.begin(), s1.end(), s2[i]) && binary_search(temp.begin(), temp.end(), s2[i]) == false)
        //     {
        //         if (temp.empty() == false) {
        //             int j = i;
        //             while (j-1 >= 0 && s2[j-1] != s2[j] && binary_search(s1.begin(), s1.end(), s2[j-1])) {
        //                 j--;
        //             }
        //             if (i-j != temp.size()) continue;
        //             if (binary_search(s1.begin(), s1.end(), temp.back()))
        //                 temp.push_back(s2[i]);
        //         }
        //         else
        //             temp.push_back(s2[i]);
        //         if (temp.size() == s1.size()) {
        //             return true;
        //         }
        //         temp.shrink_to_fit();
        //         sort(temp.begin(), temp.end());
        //     }
        //     else {
        //         if (binary_search(temp.begin(), temp.end(), s2[i]) == true) {
        //             continue;
        //         }
        //         else if (binary_search(s1.begin(), s1.end(), s2[i]) == false) temp.clear();
        //     }
        // }
        // if (temp.size() == s1.size()) return true;
        
        // return false;

        // ---------------------
        // sort(s1.begin(), s1.end());
        // map<char, int> s1_map;
        // for (int i = 0; i < s1.size(); i++)
        // {
        //     s1_map[s1[i]]++;
        // }
        // // bool __cont = true;
        // map<char, int> substr_map;
        // set<char> char_set;
        // for (int i = 0; i < s2.size(); i++)
        // {
        //     if (s1_map == substr_map)
        //     {
        //         return true;
        //     }
        //     else if (binary_search(s1.begin(), s1.end(), s2[i]))
        //     {
        //         if (binary_search(char_set.begin(), char_set.end(), s2[i]) == false) {
        //             substr_map[s2[i]]++;
        //             char_set.insert(s2[i]);
        //         }
        //         // __cont = true;
        //         else {
        //             // substr_map[s2[i]]--;
        //             // int j = i-1;
        //             // char const s = s2[i];
        //             while (s2[i-1] != s2[i] && binary_search(s1.begin(), s1.end(), s2[i]))
        //             {
        //                 i--;
        //             }
        //             substr_map.clear();
        //             char_set.clear();
        //         }
        //         // sort(v_char.begin(), v_char.end());
        //     }
        //     else
        //     {
        //         substr_map.clear();
        //     }
        // }
        // if (s1_map == substr_map) return true;

        // return false;
        // ------------------


    }
};

//*/*-------- MAIN FUNCTION --------*/*//
int main() {
    fastIO();
    fileIO();

    // !! xxxxxxxx !! START FROM HERE !! xxxxxxxx !!
    //*/*--------- implementation code ---------*/*//

    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    Solution sol;
    if (sol.checkInclusion(s1, s2))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}