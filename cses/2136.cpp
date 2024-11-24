#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->ios_base::sync_with_stdio(false);
  int n, k, i, j, res = INT_MAX;
  cin >> n >> k;
  vector<bitset<30>> a(n);
  for (auto &b : a)
    cin >> b;
  for (i = 0; i < n; i++)
    for (j = 0; j < i; j++)
      res = min(res, int((a[i] ^ a[j]).count()));
  cout << res;
  return 0;
}
