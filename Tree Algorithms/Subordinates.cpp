#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
vector<int> ans;
int solve(int node, int p, vector<vector<int>> &adj) {
   for(auto i : adj[node])
   {
        if(i == p) continue;
        ans[node] += solve(i, node, adj);
   }
   return ans[node] + 1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> arr(n);
    for(int i = 0; i< n-1;i++) cin >> arr[i];
    vector<vector<int>> adj(n+1);
    for(int i = 0; i< n-1;i++)
    {
        adj[arr[i]].push_back(i+2);
        adj[i+2].push_back(arr[i]);
    }
    ans.resize(n+1);
    solve(1, 0, adj);
    for(int i = 1; i<= n;i++) cout << ans[i] << " ";
    return 0;
}
