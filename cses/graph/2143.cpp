// UNSOLVED

#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->ios_base::sync_with_stdio(false);
  int n, m, u, v, i, q;
  cin >> n >> m >> q;
  vector<vector<int>> adj(n + 1);
  vector<bool> vis(n + 1);
  vector<bitset<50001>> _vis(n + 1);
  while (m--)
    cin >> u >> v, adj[u].push_back(v);
  function<void(int)> dfs = [&](int s) {
    vis[s] = true;
    _vis[s].set(s);
    for (int x : adj[s]) {
      if (!vis[x])
        dfs(x);
      _vis[s] |= _vis[x];
    }
  };
  for (i = n; i >= n; i--)
    if (!vis[i])
      dfs(i);
  while (q--)
    cin >> u >> v, cout << (_vis[u].test(v) ? "YES" : "NO") << '\n';
  return 0;
}
