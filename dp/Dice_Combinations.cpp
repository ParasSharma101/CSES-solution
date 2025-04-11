#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e9 + 7;
vector<int> dp;
int helper(int sum, int n)
{
    if(sum == n) return 1;
    if(sum > n) return 0;

    if(dp[sum] != -1) return dp[sum] % INF;

    int ans = 0;
    for(int i = 1; i<= 6;i++)
    {
        ans = (ans + helper(sum + i, n)) % INF;
    }
    return dp[sum] = ans%INF;
}


void solve(int n){
    int sum = 0;
    dp = vector<int>(n+1,-1);
    int res = helper(sum, n);
    cout << res;
}


signed main()
{
    int n;
    cin >> n;
    solve(n);
    return 0;
}