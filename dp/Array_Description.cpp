#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
#define int long long
#define endl '\n'
const int MOD = 1e9 + 7;
bool isvalid(int x, int y)
{
    return 1 <= x && x <= y;
}
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<int> nums(n);
    for(int i = 0; i< n;i++) cin >> nums[i];    
    int res = 0;

    vector<vector<int>> dp(n+1 , vector<int>(m+1));

    for(int i = 1; i <= m;i++)
    {
        if(nums[0] ==  0 || nums[0] == i) dp[1][i] = 1;
    }

    for(int i = 2; i<= n;i++)
    {
        for(int k = 1; k<= m;k++)
        {
            if(nums[i-1] != 0 && nums[i-1] != k)
            {
                dp[i][k] = 0;
                continue;
            }

            for(int prev= k-1 ; prev<= k+1;prev++)
            {
                if(!isvalid(prev, m))
                {
                    continue;
                }

                dp[i][k] = (dp[i][k] + dp[i-1][prev]) % MOD;
            }
        }
    }
    for(int i = 1; i<= m;i++)
    {
        res = (res + dp[n][i]) % MOD;
    }
    cout << res;
    return 0;
}
