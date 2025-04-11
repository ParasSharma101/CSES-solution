#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;

int n,m;

void dfs(int i, int j, vector<vector<char>> &rooms, vector<vector<bool>> &visited)
{
    if(i < 0 || i >=n || j < 0 || j >= m || visited[i][j] || rooms[i][j] == '#') return;
    visited[i][j] = true;

    dfs(i+1,j,rooms,visited);
    dfs(i-1,j,rooms,visited);
    dfs(i,j+1,rooms,visited);
    dfs(i,j-1,rooms,visited);
}


signed main() {
    ios::sync_with_stdio(false); 
    cin.tie(NULL);
    cin >> n >> m;
    vector<vector<char>> rooms(n, vector<char>(m));
    for(int i = 0; i<n;i++)
    {
        for(int j = 0; j<m;j++)
        {
            cin >> rooms[i][j];
        }
    }

    vector<vector<bool>> visited(n,vector<bool>(m,false));
    int ans = 0;

    for(int i = 0; i<n;i++)
    {
        for(int j =0; j<m;j++)
        {
            if(!visited[i][j] && rooms[i][j] == '.')
            {
                ans++;
                dfs(i,j,rooms, visited);
            }
        }
    }

    cout << ans ;
}
