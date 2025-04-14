#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'

const int INF = LLONG_MAX >> 1;
vector<int> dp;

int helper(int n) {
    int steps = 0;
    while(n > 0) {
        string s = to_string(n);
        int max_digit = 0;
        for(char c : s) max_digit = max(max_digit, (c - '0')*1LL);
        n -= max_digit;
        steps++;
    }
    return steps;
}



void solve(int n)
{
    dp = vector<int>(n+1, -1);
    int ans = helper(n);
    cout << ans;
}

signed main()
{
    ios :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;


    solve(n);
    return 0;
}