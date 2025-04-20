#include<bits/stdc++.h>
using namespace std;

#define int long long
#define endl '\n'
const int INF = LLONG_MAX >> 1;
const int MOD = 1e9 + 7;

void helper(vector<int> &nums, int l, int r, int sum, unordered_map<int, int> & mp, int x)
{
    if(sum > x)
    {
        return;
    }

    if(l > r || sum == x)
    {
        mp[sum]++;
        return;
    }
    helper(nums, l+1, r, sum, mp, x);
    if(sum + nums[l] <= x)
        helper(nums, l+1, r, sum+ nums[l], mp, x);
}

signed main()
{
    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    int x;
    cin >> x;

    vector<int> nums(n);
    for(int i =0; i<n;i++) cin >> nums[i];
    unordered_map<int,int> mp1, mp2;
    mp1.reserve(1 << 20);
    mp2.reserve(1 << 20);
    helper(nums, 0, nums.size()/2 - 1,0, mp1, x);
    helper(nums, nums.size()/2, nums.size()-1,0 , mp2, x);
    int res = 0;
    for(auto m: mp1)
    {
        int a = m.first;
        if(mp2.find(x-a) != mp2.end())
        {
            res += mp2[x-a] * m.second*1LL;
        }
    }
    cout << res ;
    return 0;
}