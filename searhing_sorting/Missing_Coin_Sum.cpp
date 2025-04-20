#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    // int tc; 
    // cin >> tc;    
    // while (tc--) 
    // {            

        int n;
        cin >> n;

        vector<int> coins(n);
        for(int i = 0; i<n;i++) cin >> coins[i];

        int sum = 0;
        sort(coins.begin(), coins.end());
        for(int i = 0; i< n;i++)
        {
            if(coins[i] > sum + 1) break;
            else sum += coins[i];
        }
        cout << sum + 1;
    // }
}
