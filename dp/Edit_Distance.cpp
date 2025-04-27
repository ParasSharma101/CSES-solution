#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

// m    o   v   i   e --> s1
// l    o   v   e --> s2
vector<vector<int>> dp;

int helper(int i, int j, string &s1, string &s2)
{

    if(i == s1.size() && j == s2.size()) return 0;
    if (i == s1.size()) return s2.size() - j;
    if (j == s2.size()) return s1.size() - i;

    if(dp[i][j] != -1) return dp[i][j];
    int res = 0;

    if(s1[i] == s2[j])
    {
        res = helper(i+1, j+1, s1, s2);
    }
    else
    {
        int add = 1 + helper(i+1, j, s1, s2);
        int rem = 1 + helper(i , j+1, s1, s2);
        int rep = 1 + helper( i+1, j+1, s1, s2);

        res = min({add, rem, rep});
    }

    return dp[i][j] = res;
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    
    string s, t;
    cin >> s >> t;
    dp = vector<vector<int>>(s.size()+1, vector<int>(t.size()+1, -1));
    int res = helper(0, 0,  s, t);
    cout << res;
}

