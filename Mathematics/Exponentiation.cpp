#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
const int INF = LLONG_MAX >> 1;
const int MOD = 1e9 + 7;

int exp(int a, int b)
{
    if(b == 1) return a;
    if(b == 0) return 1;
    int res = 1;
    while(b > 0)
    {
        if(b & 1)
        {
            res = (res * a) % MOD;
            b--;
        }
        a = (a * a)%MOD;
        b/= 2;
    }
    return res % MOD;
}

signed main()
{
    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    while(n--)
    {
        int a, b;
        cin >> a >> b;

        int res = exp(a, b);
        cout << res<< endl;
    }
    return 0;
}