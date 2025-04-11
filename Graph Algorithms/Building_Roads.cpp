#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

void dfs(int node, vector<bool> &visited, vector<vector<int>> &adj)
{
    visited[node] = true;
    for(auto child : adj[node])
    {
        if(!visited[child])
        {
            dfs(child, visited, adj);
        }
    }
}

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;

    vector<vector<int>> edges;
    for(int i = 0; i < m; i++)
    {
        int u,v;
        cin >> u >> v;
        edges.push_back({u,v});
    }
    vector<vector<int>> adj(n);
    for(auto e : edges)
    {
        int u = e[0]-1;
        int v = e[1]-1;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> nodes;
    vector<bool> visited(n, false);
    for(int i = 0; i < n;i++)
    {
        if(!visited[i])
        {
            dfs(i, visited, adj);
            nodes.push_back(i);
        }
    }
    vector<pair<int,int>> ans;
    for(int i = 0; i < nodes.size()-1; i++)
    {
        ans.push_back({nodes[i]+1, nodes[i+1]+1});
    }
    cout << ans.size() << endl;
    for(auto p : ans)
    {
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
