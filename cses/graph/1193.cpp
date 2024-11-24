#include <bits/stdc++.h>
using namespace std;

using pii = pair<int, int>;
using tp = tuple<int, int, char>;

const tp biases[4] = {{-1, 0, 'U'}, {1, 0, 'D'}, {0, -1, 'L'}, {0, 1, 'R'}};

int main() {
  cin.tie(nullptr)->ios_base::sync_with_stdio(false);
  int n, m, i, j;
  cin >> n >> m;
  vector<vector<char>> a(n + 2, vector<char>(m + 2, '#'));
  vector<vector<tp>> par(n + 2, vector<tp>(m + 2, {-1, -1, '\0'}));
  vector<vector<bool>> vis(n + 2, vector<bool>(m + 2));
  queue<pii> q;
  pii end;
  for (i = 1; i <= n; i++)
    for (j = 1; j <= m; j++) {
      cin >> a[i][j];
      if (a[i][j] == 'A')
        q.emplace(i, j);
      if (a[i][j] == 'B')
        end = {i, j};
    }
  while (!q.empty()) {
    pii u = q.front();
    q.pop();
    vis[u.first][u.second] = true;
    for (const tp &b : biases) {
      int x = u.first + get<0>(b), y = u.second + get<1>(b);
      if (a[x][y] != '#' && !vis[x][y])
        q.emplace(x, y), par[x][y] = {u.first, u.second, get<2>(b)},
                         vis[x][y] = true;
    }
  }
  string res;
  if (vis[end.first][end.second]) {
    while (end.first != -1)
      res += get<2>(par[end.first][end.second]),
          end = {get<0>(par[end.first][end.second]),
                 get<1>(par[end.first][end.second])};
    res.pop_back();
    reverse(res.begin(), res.end());
    cout << "YES\n" << res.length() << '\n' << res;
    return 0;
  }
  cout << "NO";
  return 0;
}
