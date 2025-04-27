#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9+7;

int main() {
    int n;
    cin >> n;
    int sum = n*(n+1)/2;
    
    // If total sum is odd, not possible
    if (sum % 2 != 0) {
        cout << 0 << endl;
        return 0;
    }
    
    sum /= 2;
    vector<int> dp(sum+1, 0);
    dp[0] = 1;
    
    for (int num = 1; num <= n; num++) {
        for (int s = sum; s >= num; s--) {
            dp[s] = (dp[s] + dp[s-num]) % MOD;
        }
    }
    
    // Since we counted each partition twice
    cout << (1LL * dp[sum] * ((MOD + 1) / 2) % MOD) << endl;
    return 0;
}
