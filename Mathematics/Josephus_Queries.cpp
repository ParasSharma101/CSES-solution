#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'

int solve(int n, int k) {
    if (n == 1) return 1;
    if( k <= (n+1)/2)
    {
        if(2*k > n) return (2*k) % n;
        else return 2*k;
    }
    int temp = solve(n/2, (k - (n+1)/2));
    if(n & 1) return 2*temp+1;
    else return 2*temp-1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int q;
    cin >> q;
    while (q--) {
        int n, k;
        cin >> n >> k;
        cout << solve(n, k) << endl;
    }
}
