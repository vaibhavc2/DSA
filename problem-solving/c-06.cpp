#include <bits/stdc++.h>
using namespace std;

// ? Leetcode : MERGE SORTED ARRAYS

// Lambda expression (or function) for INPUT-OUTPUT to file
auto fileIO = [](){
    #ifdef LOCAL_PROJECT // or, ONLINE_JUDGE
    (void)!freopen("INPUT.txt", "r", stdin);
    (void)!freopen("OUTPUT.txt", "w", stdout);
    #endif
};

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while(k >= 0 && i < 0) {
            if(i < 0 && j>=0)
                nums1[k--] = nums2[j--];
            else break;
        }
        while(i <= k && j <= k && i >= 0 && j >= 0 && k >= 0) {
            if(nums1[i] >= nums2[j]) {
                nums1[k--] = nums1[i--];
            }
            else {
                nums1[k--] = nums2[j--];
            }
        }
        while(k >= 0) {
            if(i >= 0 && j < 0) {
                nums1[k--] = nums1[i--];
            }
            else if(i < 0 && j >= 0) {
                nums1[k--] = nums2[j--];
            }
        }
    }
};

int main() {
    fileIO();
    int t = 1;
    cin >> t;
    while(t--) {
        int m, n;
        cin >> m >> n;
        vector<int> nums1(m+n), nums2(n);
        for(int i = 0; i < m; i++) cin >> nums1[i];
        for(int i = 0; i < n; i++) cin >> nums2[i];
        Solution sol;
        sol.merge(nums1, m, nums2, n);
        for (auto &&i : nums1)
        {
            cout << i << " ";
        }
        cout << "\n" << std::flush;
    }
    return 0;
}