#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e9 + 7;
int n, x;
vector<int> dp;
// int helper(int sum, int x, vector<int> &coins, int last)
// {
//     if(sum == x) return 1;
//     if(sum > x ) return 0;

//     int ways =0;
//     if(dp[sum] != -1) return dp[sum] % INF;

//     for(int i = last ; i < n ; i++)
//     {
//         ways = (ways + helper(sum + coins[i], x, coins, i)) % INF;
//     }
//     return dp[sum] = ways % INF;
// }

void solve(int n, int x, vector<int> &coins)
{   
    
    dp = vector<int>(x+1,0);
    dp[0] = 1;

    for(int i = 0; i< n; i++)
    {
        for(int sum = 0; sum <= x; sum++)
        {
            if(sum + coins[i] <= x)
            {
                dp[sum + coins[i]] = (dp[sum + coins[i]] + dp[sum]) % INF;
            }
        }
    }
    cout << dp[x] ;
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
