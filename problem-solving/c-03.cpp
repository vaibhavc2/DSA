//? Q: Find unique character in a string : Leetcode

#include <bits/stdc++.h>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)
// Lambda expression (or function) for INPUT-OUTPUT to file
auto fileIO = [](){
    #ifdef LOCAL_PROJECT // or, ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
};
using ul = unsigned long;
class Solution {
public:
    //? O(n^2)
    // int firstUniqChar(string s) {
    //     string a;
    //     for (ul i = 0; i < s.length(); i++)
    //     {
    //         int freq = 1;
    //         size_t found = a.find(s[i]);
    //         for (ul j = i+1; j < s.length() && found == string::npos; j++)
    //         {
    //             if(s[i] == s[j]) freq++;
    //         }
    //         a.push_back(s[i]);
    //         if(freq == 1 && found == string::npos) return (int)i;
    //     }
    //     return -1;
    // }
    //? O(n): traversing 2 times, unordered_map
    // int firstUniqChar(string s) {
    //     unordered_map<char, int> freqmap;
    //     for (char& c : s) {
    //         freqmap[c]++;
    //     }
    //     for (int i = 0; i < s.size(); i++) {
    //         if (freqmap[s[i]] == 1) return i;
    //     }
    //     return -1;
    // }
    //? O(n): traversing only once, unordered_map
    int firstUniqChar(string s) {
        unordered_map<char, pair<int, int>> fmap;
        int index = s.size();
        for (int i = 0; i < s.size(); i++) {
            fmap[s[i]].first++;
            fmap[s[i]].second = i;
        }
        for (const auto& [c, p] : fmap) {
            if (p.first == 1) {
                index = min(index, p.second);
            }
        }
        return index == s.size() ? -1 : index;
    }
};

int main() {
    fastIO();
    fileIO();
    string s;
    cin >> s;
    Solution sol;
    cout << sol.firstUniqChar(s) << "\n";
    return 0;
}