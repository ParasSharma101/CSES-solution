#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int helper(int i, vector<vector<char>> &chess)
{

}
signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    // int tc; 
    // cin >> tc;    
    // while (tc--) 
    // {            
            int n, m, k;
            cin >> n >> m >> k;
            vector<int> desapp(n);
            vector<int> avaapp(m);
            for(int i = 0; i< n;i++) cin >> desapp[i];
            for(int i = 0 ; i < m;i++) cin >> avaapp[i];

            sort(desapp.begin(),desapp.end());
            sort(avaapp.begin(), avaapp.end());

            int ans = 0;

            int i = 0,j = 0;
            while(i < n && j < m)
            {
                int low = desapp[i] - k;
                int high = desapp[i] + k;
                if(avaapp[j] >= low && avaapp[j] <= high)
                {
                    ans++;
                    i++;
                    j++;
                }
                else if(avaapp[j] < low)
                {
                    j++;
                }
                else{
                    i++;
                }
            }

            cout << ans ;
            return 0;

    // }
}
