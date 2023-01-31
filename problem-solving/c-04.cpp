//? Q: Find the Duplicate Number : Leetcode

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
    //* O(n logn)
    // int findDuplicate(vector<int>& nums) {
    //     sort(nums.begin(), nums.end());
    //     for(size_t i=1; i<nums.size(); i++) {
    //         if(nums[i-1]==nums[i]) return nums[i];
    //     }
    //     return -1;
    // }
    //* O(n)
    // int findDuplicate(vector<int>& nums) {
    //     return -1;
    // }
    //* O(log n)
    int findDuplicate(vector<int>& nums) {
        int low = 1, high = nums.size() - 1, cnt;

        while(low <=  high)
        {
            int mid = low + (high - low) / 2;
            cnt = 0;
            // cnt number less than equal to mid
            for(int n : nums)
            {
                if(n <= mid)
                    ++cnt;
            }
            // binary search on left
            if(cnt <= mid)
                low = mid + 1;
            else
            // binary search on right
                high = mid - 1;
            
        }
        return low;
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
    cout << sol.findDuplicate(nums) << "\n";
    return 0;
}