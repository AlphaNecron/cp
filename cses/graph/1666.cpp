#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->ios_base::sync_with_stdio(false);
  int n, m, u, v, i;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<bool> vis(n + 1);
  while (m--)
    cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
  auto bfs = [&](int s) {
    queue<int> q;
    q.push(s);
    vis[s] = true;
    while (!q.empty()) {
      u = q.front();
      q.pop();
      for (int v : adj[u])
        if (!vis[v])
          vis[v] = true, q.push(v);
    }
  };
  bfs(1);
  vector<int> res;
  for (i = 2; i <= n; i++)
    if (!vis[i])
      bfs(i), res.push_back(i);
  cout << res.size() << '\n';
  for (int z : res)
    cout << 1 << ' ' << z << '\n';
  return 0;
}
