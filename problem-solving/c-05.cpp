//? Q: First Missing Positive: Leetcode

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
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(nums.back()<=0) return 1;
        if(nums[0]>1) return 1;
        for(size_t i=1; i<nums.size(); i++) {
            int diff = abs(nums[i-1]-nums[i]);
            if(diff>1) {
                if(nums[i]<0) continue;
                if(nums[i-1]<0 && nums[i]>=2) return 1;
                if(nums[i-1]>=0) return (nums[i-1]+1);
            }
        }
        return nums.back()+1;
    }
};

int main() {
    fastIO();
    fileIO();
    int n;
    cin >> n;
    vector<int> nums;
    for (size_t i = 0; i < (ul)n; i++)
    {
        int tp = 0;
        cin >> tp;
        nums.push_back(tp);
    }
    Solution sol;
    cout << sol.firstMissingPositive(nums) << "\n";
    return 0;
}