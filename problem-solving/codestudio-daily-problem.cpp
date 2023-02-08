#include <bits/stdc++.h>
using namespace std;

// Lambda expression (or function) for INPUT-OUTPUT to file
auto fileIO = [](){
    #ifdef LOCAL_PROJECT // or, ONLINE_JUDGE
    (void)!freopen("INPUT.txt", "r", stdin);
    (void)!freopen("OUTPUT.txt", "w", stdout);
    #endif
};

class Solution {
    int N, K;
public:
    void setVal() {
        cin >> N >> K;
    }
    vector<int> numberWithSameConsecutiveDifference() {
        int a = (int)pow(10, N-1);
        int b = (int)(pow(10, N)) - 1;
        vector<int> ans, m(N);
        for (int i = a; i <= b; i++)
        {
            int c = i, j = 0, s = 0;
            while(c != 0) {
                m[j++] = c % 10;
                c /= 10;
            }
            int num = 0;
            bool bb = 1;
            for (int l = 0; l < N; l++)
            {
                if(l > 0) s = abs(m[l]-m[l-1]);
                if(l > 0 && s != K) {
                    bb = 0;
                    break;
                }
                num += m[l] * ((int)pow(10, l));
            }
            if(bb) {
                ans.push_back(num);
            }
        }
        return ans;
    }
};

//*/*-------- MAIN FUNCTION --------*/*//
int main() {
    fileIO();

    // !! xxxxxxxx !! START FROM HERE !! xxxxxxxx !!
    //*/*--------- implementation code ---------*/*//

    int t = 1;
    cin >> t;
    while(t--) {
        Solution sol;
        sol.setVal();
        vector<int> ans = sol.numberWithSameConsecutiveDifference();
        for (size_t i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }

    return 0;
}