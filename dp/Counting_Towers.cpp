#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

vector<vector<int>>dp(1e6, vector<int>(2));


signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    dp[0][0] = 1;
    dp[0][1] = 1;

    for(int i = 1; i < 1e6; i++)
    {
        dp[i][0] = ((2 * dp[i-1][0]) + dp[i-1][1]) % MOD;
        dp[i][1] = ((4 * dp[i-1][1]) + dp[i-1][0])% MOD;
    }
    
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << (dp[n-1][1] + dp[n-1][0])% MOD<< endl;
    }
    return 0;
}

