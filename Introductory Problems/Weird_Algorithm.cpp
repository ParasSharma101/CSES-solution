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
        cout<< n << " ";
        while(n != 1)
        {
            if(n %2 == 0)
            {
                n = n/2;
                cout<< n<<" ";
            }
            else
            {    
                n = n*3 +1;
                cout<< n << " ";
            }
        }
 
    // }
    
