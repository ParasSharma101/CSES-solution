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
            int n;
            cin >> n;
            vector<int> nums(n);
            for(int i = 0; i<n;i++) cin >> nums[i];
            set<int> st;
            for(int i = 0; i< n;i++)
            {
                st.insert(nums[i]);
            }

            cout << st.size();

            return 0;

    // }
}
