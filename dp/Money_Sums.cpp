#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> coins(n);
    for (int i = 0; i < n; i++) cin >> coins[i];

    int sum = accumulate(coins.begin(), coins.end(), 0LL);
    vector<bool> dp(sum + 1, false);
    dp[0] = true;

    for (int coin : coins) {
        // Go backwards to avoid using the same coin multiple times
        for (int i = sum; i >= 0; i--) {
            if (dp[i]) {
                dp[i + coin] = true;
            }
        }
    }

    vector<int> ans;
    for (int i = 1; i <= sum; i++) {
        if (dp[i]) {
            ans.push_back(i);
        }
    }

    cout << ans.size() << endl;
    for (auto x : ans) {
        cout << x << " ";
    }
}


/*

                4
                4   2   5   2

                2   4   5   6   8   7   9   11  13   


                

*/