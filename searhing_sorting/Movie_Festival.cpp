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
            for(int i = 0; i< n;i++)
            {
                int start,end;
                cin >> start >> end;

                nums[i] = {end, start};
            }
            sort(nums.begin(), nums.end());
            int last = -1;

            int ans = 0;

            for(int i = 0; i< n;i++)
            {
                if(nums[i].second >= last)
                {
                    last = nums[i].first;
                    ans++;
                }
            }
            cout << ans;

    // }
}
