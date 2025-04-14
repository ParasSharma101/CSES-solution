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
            
            int n, m;
            cin >> n >> m;
            multiset<int> mst;
            vector<int> customer(m);

            for(int  i =0; i<n;i++){
                int val;
                cin >> val;
                mst.insert(val);
            }
            for(int i = 0; i< m;i++) cin >> customer[i];

            for(int i = 0; i< m;i++)
            {
                auto it = mst.upper_bound(customer[i]);
                if(it == mst.begin())
                {
                    cout << -1 << endl;
                }
                else
                {
                    it--;
                    cout << *it << endl;
                    mst.erase(it);
                }
            }

    // }
}
