#include <bits/stdc++.h>
using namespace std;
bool isPossible(int n, vector<vector<int>> &arr, int candies, long long mid){
    int sum = 0;
    for(int i = 0; i<n; ++i){
        for(int j = 0; j<(int)arr[i].size(); ++j){
            if(arr[i][j]<=mid){
                sum+=arr[i][j];
            }
        }
    }
    if(sum<=candies) return true;
    return false;
}
int findMaxX(int n, vector<vector<int>> &arr, int candies)
{
    long long s = 0, e = candies;
    long long mid = (s+e)/2;
    long long ans = -1;
    while(s<=e){
        if(isPossible(n,arr,candies,mid)){
            ans = mid;
            s = mid+1;
        }
        else{
            e = mid-1;
        }
        mid = (s+e)/2;
    }
    return (int)ans;
}
int main(){
    #ifndef ONLINE_JUDGE
        freopen("INPUT.txt", "r", stdin);
        freopen("OUTPUT.txt", "w", stdout);
    #endif
    // vector<vector<int>> vec{ { 1, 2, 3 },
    //                      { 4, 2, 3 },
    //                      { 1,10,2 } };
    // long long i = findMaxX(3,vec,20);
    // cout<<i<<endl;
    long long t = 1;
    cin >> t;
    while (t--)
    {
        int n, b;
        cin >> n >> b;
        vector<vector<int>> arr(n);
        for(int i = 0; i < n; i++) {
            int s;
            cin >> s;
            vector<int> temp(s);
            for (int j = 0; j < s; j++)
            {
                cin >> temp[j];
            }
            arr[i] = temp;
        }
        long long i = findMaxX(n,arr,b);
        cout << i << "\n";
    }
    
    return 0;
}