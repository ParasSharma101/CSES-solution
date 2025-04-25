#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int countRounds(int n, vector<int> &pos)
{
    int rounds = 1;
    for(int i = 2; i<= n;i++)
    {
        if(pos[i] < pos[i-1]) rounds++;
    }
    return rounds;
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cout.tie(NULL);


    int n, m;
    cin >> n >> m;
    vector<int> nums(n), pos(n+1);
    for(int i = 0; i<n;i++)
    {
        cin >> nums[i];
        pos[nums[i]] = i;
    }
    vector<pair<int,int>> query(m);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--; // Convert to 0-based indexing

        // Swap elements in nums
        swap(nums[a], nums[b]);

        // Update positions in pos[]
        pos[nums[a]] = a;
        pos[nums[b]] = b;

        // Count and print rounds
        int res = countRounds(n, pos);
        cout << res << '\n';
    }

}


