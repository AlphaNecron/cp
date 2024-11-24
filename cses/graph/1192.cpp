#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;

const pii biases[4] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int main() {
  cin.tie(nullptr)->ios_base::sync_with_stdio(false);
  int n, m, i, j, cnt = 0;
  cin >> n >> m;
  vector<vector<char>> a(n + 2, vector<char>(m + 2, '#'));
  vector<vector<bool>> vis(n + 2, vector<bool>(m + 2));
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      cin >> a[i][j];
  auto bfs = [&](const pii &p) {
    queue<pii> q;
    q.push(p);
    while (!q.empty()) {
      pii u = q.front();
      q.pop();
      vis[u.first][u.second] = true;
      for (const pii &b : biases) {
        int x = u.first + b.first, y = u.second + b.second;
        if (a[x][y] == '.' && !vis[x][y])
          vis[x][y] = true, q.emplace(x, y);
      }
    }
  };
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++)
      if (!vis[i][j] && a[i][j] == '.')
        bfs({i, j}), cnt++;
  cout << cnt;
  return 0;
}
