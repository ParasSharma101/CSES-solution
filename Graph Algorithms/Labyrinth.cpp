#include <bits/stdc++.h>
using namespace std;

#define int long long
int n, m;
vector<vector<char>> grid;
vector<vector<bool>> visited;
vector<vector<pair<int, int>>> parent;

string dirs = "DURL";
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

bool is_valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && grid[x][y] != '#';
}

signed main() {
    cin >> n >> m;
    grid.resize(n, vector<char>(m));
    visited.resize(n, vector<bool>(m, false));
    parent.resize(n, vector<pair<int, int>>(m, {-1, -1}));
    pair<int, int> start, end;

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            cin >> grid[i][j];
            if (grid[i][j] == 'A') start = {i, j};
            if (grid[i][j] == 'B') end = {i, j};
        }

    queue<pair<int, int>> q;
    q.push(start);
    visited[start.first][start.second] = true;

    bool found = false;
    while (!q.empty()) {
        auto front = q.front();
        int x = front.first, y = front.second;
         q.pop();
        if (make_pair(x, y) == end) {
            found = true;
            break;
        }
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (is_valid(nx, ny)) {
                visited[nx][ny] = true;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    if (!found) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
        string path;
        pair<int, int> cur = end;
        while (cur != start) {
            int px = parent[cur.first][cur.second].first;
            int py = parent[cur.first][cur.second].second;
            for (int d = 0; d < 4; ++d) {
                if (px + dx[d] == cur.first && py + dy[d] == cur.second) {
                    path += dirs[d];
                    break;
                }
            }
            cur = {px, py};
        }
        reverse(path.begin(), path.end());
        cout << path.length() << endl;
        cout << path << endl;
    }

    return 0;
}
