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
        
        string s;
        cin >> s;
        int len = 0;
        int ans = 0;
        for(int i = 0,j = 0;j < s.size();j++)
        {
            if(s[i] == s[j])
            {
                ans =max(ans, j - i +1);
            }
            else
            {
                i = j;
            }
        }
        cout<< ans << endl;
    // }
    
}
