#include <bits/stdc++.h>
using namespace std;
#define int long long

const int MOD = 1e9 + 7;
const int PHI = MOD - 1; // Because MOD is prime

// Fast exponentiation: a^b % m
int binpow(int a, int b, int m) {
    if (a == 0 && b == 0) return 1; // 0^0 = 1
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;

        int exp = binpow(b, c, PHI); // b^c mod (MOD-1)
        int result = binpow(a, exp, MOD); // a^exp mod MOD
        cout << result << "\n";
    }
    return 0;
}
