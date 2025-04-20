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

    int n,x;
    cin >> n >> x;

    vector<int> nums(n);
    for(int i = 0; i<n;i++) cin >> nums[i];

    int i =0 , j=0;
    int ans = 0;
    int sum = 0;
    while(j < n)
    {
        sum += nums[j];
        if(sum == x)
        {
            ans++;
            sum -= nums[i];
            i++;
        }
        else if(sum >  x)
        {
            while(sum > x)
            {
                sum-= nums[i];
                if(sum == x) ans++;
                i++;
            }
        }
        j++;
    }

    cout << ans ;

}

