#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    // int tc; 
    // cin >> tc;    
    // while (tc--) 
    // {            
        int n;
        cin >> n;
        vector<int> nums(n);

        for(int i = 0; i < n;i++)
        {
            cin >> nums[i];
        }

        sort(nums.begin(), nums.end());

        int mid = nums[n/2];

        int res = 0;
        for(int i = 0; i< n;i++)
        {
            res += abs(nums[i] - mid);
        }
        cout << res;

    // }
}




