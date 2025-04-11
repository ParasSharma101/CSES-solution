#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int INF = LLONG_MAX >> 1;

signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n + 1);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<int> parent(n + 1, -1);
    vector<bool> visited(n + 1, false);

    int start = 1, end = n;
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front(); q.pop();
        for (int child : graph[node]) {
            if (!visited[child]) {
                visited[child] = true;
                parent[child] = node;
                q.push(child);
            }
        }
    }

    if (!visited[end]) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        vector<int> path;
        for (int cur = end; cur != -1; cur = parent[cur]) {
            path.push_back(cur);
        }
        reverse(path.begin(), path.end());
        cout << path.size() << endl;
        for (int v : path) cout << v << " ";
        cout << endl;
    }

    return 0;
}
