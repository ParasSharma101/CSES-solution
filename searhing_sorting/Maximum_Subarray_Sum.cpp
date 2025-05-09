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
        for(int i = 0; i<n;i++)
        {
            cin >> nums[i];
        }

        int res = nums[0];
        int currsum = nums[0];

        for(int i = 1; i< n;i++)
        {
            currsum = max(nums[i], currsum + nums[i]);
            res = max(res, currsum);
        }

        cout << res;
        return 0;

    // }
}
