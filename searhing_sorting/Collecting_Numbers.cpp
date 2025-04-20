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
    vector<int> pos(n+1);
    int rounds = 1;
    for(int i = 0; i<n;i++) 
    {
        cin >> nums[i];
        pos[nums[i]] = i;
    }

    for(int i = 2; i<= n;i++)
    {
        if(pos[i] < pos[i-1]) rounds++;
    }
    cout << rounds;
}

