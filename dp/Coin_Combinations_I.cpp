#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e9 + 7;
int n, x;
vector<int> dp;
int helper(int sum, int x, vector<int> &coins)
{
    if(sum == x) return 1;
    if(sum > x) return 0;

    if(dp[sum] != -1) return dp[sum] % INF;

    int ways = 0;

    for(int i = 0; i < n; i++)
    {
        ways = (ways + helper(sum + coins[i] , x, coins))% INF;
    }

    return dp[sum] = ways % INF;
}

void solve(int n, int x, vector<int> &coins)
{   
    int sum = 0;
    dp = vector<int>(x+1,-1);
    int ways = helper(sum, x, coins);
    cout << ways ;
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> x;
    vector<int> coins(n);
    for(int i =0; i< n;i++)
    {
        cin >> coins[i];
    }
    solve(n,x,coins);
    return 0;
}
