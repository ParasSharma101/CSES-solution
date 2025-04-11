#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
// #define s begin()
// #define e end()
const int MOD = 1e9 + 7;
 
const int INF = LLONG_MAX >> 1;
 
signed main() 
{
    ios::sync_with_stdio(false); 
    cin.tie(NULL);    
    // int tc; 
    // cin >> tc;    
    // while(tc--) 
    // {            
        
        int n;
        cin >> n;
        vector<int>v(n);
        for(auto & i: v) cin >> i;
        int ans = 0;
        int prev = v[0];
        for(int i = 0;i< n-1;i++)
        {
            if(v[i] > v[i + 1])
            {
                ans += v[i] - v[i+1];
                v[i+1] = v[i];
            }
        }
        cout<< ans<<endl;
 
    // }
    
}
