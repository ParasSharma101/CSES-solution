#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9 + 7;
int n, x;
// vector<vector<int>> dp;

// int helper(int ind, int cash, vector<int>& prices, vector<int>& books) {
//     if (ind == n) return 0;

//     if (dp[ind][cash] != -1) return dp[ind][cash];

//     int notpick = helper(ind + 1, cash, prices, books);
//     int pick = 0;
//     if (prices[ind] <= cash) {
//         pick = books[ind] + helper(ind + 1, cash - prices[ind], prices, books);
//     }

//     return dp[ind][cash] = max(pick, notpick);
// }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> x;
    vector<int> prices(n), books(n);
    for (int i = 0; i < n; i++) cin >> prices[i];
    for (int i = 0; i < n; i++) cin >> books[i];

    vector<int> dp(x + 1, 0);

    for (int i = 0; i < n; i++) {
        for (int j = x; j >= prices[i]; j--) {
            dp[j] = max(dp[j], books[i] + dp[j - prices[i]]);
        }
    }

    cout << dp[x];

    return 0;
}
