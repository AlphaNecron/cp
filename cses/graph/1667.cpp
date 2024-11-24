#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->ios_base::sync_with_stdio(false);
  int n, m, u, v;
  cin >> n >> m;
  vector<vector<int>> adj(n + 1);
  vector<int> par(n + 1);
  while (m--)
    cin >> u >> v, adj[u].push_back(v), adj[v].push_back(u);
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    u = q.front();
    q.pop();
    for (int v : adj[u])
      if (!par[v])
        q.push(v), par[v] = u, cerr << v;
  }
  if (!par[n])
    return cout << "IMPOSSIBLE", 0;
  u = n;
  stack<int> res;
  while (u != 1)
    res.push(u), u = par[u];
  res.push(1);
  cout << res.size() << '\n';
  while (!res.empty())
    cout << res.top() << ' ', res.pop();
  return 0;
}
