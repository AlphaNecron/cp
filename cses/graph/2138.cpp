#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->ios_base::sync_with_stdio(false);
  int n, m, u, v, i;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<bitset<50001>> vis(n + 1);
  while (m--)
    cin >> u >> v, adj[u].push_back(v);
  function<void(int)> dfs = [&](int s) {
    vis[s].set(s);
    for (int x : adj[s]) {
      if (!vis[s].test(x))
        dfs(x);
      vis[s] |= vis[x];
    }
  };
  for (i = 1; i <= n; i++)
    if (!vis[i].test(i))
      dfs(i);
  for (i = 1; i <= n; i++)
    cout << vis[i].count() << ' ';
  return 0;
}
