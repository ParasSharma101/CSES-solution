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
    int a, b;
    cin >> a >> b;

    vector<vector<int>> dp(a+1, vector<int>(b+1, 1e9));

    for(int i = 1; i<= a; i++)
    {
        for(int j = 1; j <= b; j++)
        {
            if(i == j)
            {
                dp[i][j] = 0;
                continue;
            }

            // horizontal cut
            for(int h = 1; h <= i-1; h++)
            {
                dp[i][j] = min(dp[i][j], dp[h][j] + dp[i-h][j] + 1);
            }
            // vertical cut

            for(int v = 1; v <= j-1;v++)
            {
                dp[i][j] = min(dp[i][j], dp[i][v] + dp[i][j-v]+1);
            }
        }
    }
    
    cout << dp[a][b] ;
}

