#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);


    int n;
    cin >> n;
    vector<int> nums(n);
    for(int i = 0; i<n;i++)
        cin >> nums[i];
    
    set<int> st;
    int res = 0;
    for(int i= 0, j = 0; j< n;j++)
    {
        while (st.count(nums[j])) {
            st.erase(nums[i]);
            i++;
        }
        st.insert(nums[j]);
        res = max(res, j - i + 1);
    }

    cout << res;
}

