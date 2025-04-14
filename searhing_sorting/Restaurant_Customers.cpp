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
        vector<pair<int,int>> nums(n);
        map<int, int> mp;
        for(int i = 0; i< n;i++)
        {
            int start,end;
            cin >> start >> end;
            mp[start] = 1;
            mp[end] = -1;
            nums[i] = {start, end};
        }
        int count = 0;
        int res = 0;
        for(auto m : mp)
        {
            count += m.second;
            res = max(res, count);
        }

        cout << res;
        




            

    // }
}
