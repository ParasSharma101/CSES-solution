#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e9 + 7;

vector<int> dp;
int n, x;
int helper(int sum, int x, vector<int> &coins)
{
    if(x == sum) return 0;
    if(sum > x) return INF;
    if(dp[sum] != -1) return dp[sum];
    int ans = INF;

    for(int i = 0; i< n;i++)
    {
        ans = min(ans, 1 + helper(sum + coins[i], x, coins));
    }

    return dp[sum] = ans;
}

void solve(int n, int x, vector<int> &coins)
{   
    int sum = 0;
    dp = vector<int>(x+1,-1);
    int res = helper(sum, x, coins);
    if(res == INF) cout << -1;
    else cout << res;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    
    cin >> n >> x;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];
    solve(n,x,coins);
    return 0;
}
