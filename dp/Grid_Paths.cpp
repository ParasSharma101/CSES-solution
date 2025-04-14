#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

const int INF = LLONG_MAX >> 1;
int n;
vector<vector<int>> dp;
int MOD = 1e9 +7;

int helper(int i, int j, vector<vector<char>> &grid)
{
    if(i >= n || j >= n || grid[i][j] == '*') return 0;
    if(i == n-1 && j == n-1) return 1;
    

    if(dp[i][j] != -1) return dp[i][j] % MOD;

    int right = 0, down = 0;
    right += helper(i,j+1,grid);
    down += helper(i+1,j,grid);

    return dp[i][j] = (right + down)% MOD;
    
}
signed main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<vector<char>> grid(n, vector<char>(n));

    for(int i = 0; i< n;i++)
    {
        for(int j = 0; j<n;j++)
        {
            cin >> grid[i][j];
        }
    }
    dp = vector<vector<int>>(n, vector<int>(n,-1));
    int ans = helper(0,0, grid);
    cout << ans;
}