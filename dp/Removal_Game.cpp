#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    cin >> n;
    vector<int> nums(n);
    int sum = 0;
    for(int i = 0; i<n;i++)
    {
        cin >> nums[i];
        sum += nums[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for(int left = n-1; left >= 0; left--)
    {
        for(int right = left; right < n; right++)
        {
            if(left == right) 
            {
                dp[left][right] = nums[left];
            }
            else
            {
                dp[left][right] = max(nums[left] - dp[left+1][right], nums[right] - dp[left][right-1]);
            }
        }
    }

    int res = (sum + dp[0][n-1])/2;
    cout << res ;

}