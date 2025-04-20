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
    int n, x;
    cin >> n >> x;

    vector<int> nums(n);
    for(int i = 0; i<n;i++) cin >> nums[i];

    vector<int> prefix(n+1, 0);
    prefix[0] = nums[0];
    int ans = 0;
    map<int,int> mp;
    mp[0] = 1;

    int currsum = 0;
    for(int i = 0; i<n;i++)
    {
        currsum += nums[i];
        ans += mp[currsum - x];
        mp[currsum]++;
    }

    

    cout << ans;
}

