#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int binexpo(int a, int b)
{
    if(b == 0) return 0;
    if(b == 1) return 2;

    int res = 1;
    while( b > 0)
    {
        if(b & 1)
        {
            res = (res * a) % MOD;
            b--;
        }
        a = (a* a) % MOD;
        b/= 2;
    }
    return res % MOD;
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    int res = binexpo(2, n);
    cout << res;
}

