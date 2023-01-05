//* OPTIMIZATIONS
#ifndef DEBUG
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC optimize("unroll-loops")
#endif

#include <bits/stdc++.h>
using namespace std;

#define fastIO() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr)

//*/*----------------------------------*/*//

// Lambda expression (or function) for INPUT-OUTPUT to file
auto fileIO = [](){
    #ifndef ONLINE_JUDGE
    freopen("INPUT.txt", "r", stdin);
    freopen("OUTPUT.txt", "w", stdout);
    #endif
};

//*/*-------- SOLUTIONS & CUSTOM FUNCTIONS --------*/*//

class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int s = 0;
        int e = (int)(nums.size() - 1);
        int mid = s - (s - e) / 2;
        vector<int> result(2);
        while (s <= e) {
            if (nums[mid] == target)
            {
                int i = 1, j = 1;
                while (mid-i >= 0 && nums[mid-i] == target) {
                    i++;
                }
                while (mid+j < (int)(nums.size()) && nums[mid+j] == target) {
                    j++;
                }
                result[0] = mid - i + 1;
                result[1] = mid + j - 1;
                return result;
            }
            else if (nums[mid] > target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
            mid = s - (s - e) / 2;
        }
        result[0] = -1;
        result[1] = -1;
        return result;
    }

    //* Optimised solution with a different approach:
    int first_pos(vector<int>& a, int x) {
        int n = a.size();
        int first_pos = n;
        int low = 0, high = n-1;
        while (low <= high)
        {
            int mid = low + (high - low)/2;
            if (a[mid] >= x)
            {
                first_pos = mid;
                high = mid-1;
            }
            else
            {
                low = mid + 1;
            }
        }
        return first_pos;
    }
    vector<int> searchRange2(vector<int>& a, int x) {
        int first = first_pos(a,x);
        int last = first_pos(a, x+1) - 1; // first position of any number greater than x = last position of x 
        if (first <= last)
        {
            return {first, last};
        }
        return {-1, -1};
    }

    //* solution using std::lower_bound : std::lower_bound() is implemented using binary search
    vector<int> searchRange3(vector<int>& nums, int target) {
        auto it1 = std::lower_bound(nums.begin(), nums.end(), target);
        auto it2 = std::lower_bound(nums.begin(), nums.end(), target + 1);
        if (it1 != nums.end() && *it1 == target) 
            return {(int)(it1 - nums.begin()), (int)(it2 - nums.begin() - 1)};
        return {-1, -1};
    }

    vector<int> searchRange4(vector<int>& nums, int target) {
        vector<int> ans;
        int a = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int b = upper_bound(nums.begin(),nums.end(),target)-nums.begin()-1;
        if(!binary_search(nums.begin(),nums.end(),target)){
            ans.push_back(-1);
            ans.push_back(-1);
        }else{
            ans.push_back(a);
            ans.push_back(b);
        }
        return ans;
    }


    //* One of the other ways to optimise the solution
    int searchIndex(vector<int> nums, int target, bool findStartIndex) {
        int ans = -1;
        int start = 0, end = nums.size() - 1;

        while(start <= end) {
            int mid = (start + (end - start) / 2);

            if(target < nums[mid]) end = mid - 1;
            else if (target > nums[mid]) start = mid + 1;
            else {
                ans = mid;

                if(findStartIndex) end = mid - 1;
                else start = mid + 1;
            }
        }

        return ans;
    }
    vector<int> searchRange5(vector<int>& nums, int target) {
        vector<int> ans;

        int first = searchIndex(nums, target, true);
        int last = searchIndex(nums, target, false);

        ans.push_back(first);
        ans.push_back(last);
        
        return ans;
    }
};


//*/*-------- MAIN FUNCTION --------*/*//
int main() {
    fastIO();
    fileIO();

    // !! xxxxxxxx !! START FROM HERE !! xxxxxxxx !!
    //*/*--------- implementation code ---------*/*//

    int n, target;
    cin >> n >> target;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }
    Solution sol;
    vector<int> target_indices = sol.searchRange2(nums, target);
    cout << target_indices[0] << " " << target_indices[1] << endl;

    return 0;
}

