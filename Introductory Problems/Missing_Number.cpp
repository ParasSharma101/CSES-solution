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
        vector<int> nums(n-1);
        for(auto &i: nums) cin >> i;
 
        int sum=0;
        int actualsum = (n*(n+1))/2;
        for(int  element : nums)
        {
            sum =sum + element ;
        }
 
        cout<< (int)(actualsum-sum) << endl;
    // }
    
}
 