#include <bits/stdc++.h>
using namespace std;

void b(int p, int r, long long s, vector<long long> &res, const vector<int> &a,
       long long x) {
  if (s > x)
    return;
  if (p == r)
    return res.push_back(s);
  b(p + 1, r, s, res, a, x);
  b(p + 1, r, s + a[p], res, a, x);
}

int main() {
  cin.tie(nullptr)->ios_base::sync_with_stdio(false);
  int n;
  long long x, cnt = 0;
  cin >> n >> x;
  vector<int> a(n);
  for (int &z : a)
    cin >> z;
  vector<long long> rl, rr;
  b(0, n / 2, 0, rl, a, x);
  b(n / 2, n, 0, rr, a, x);
  sort(rl.begin(), rl.end());
  sort(rr.begin(), rr.end());
  for (int z : rl) {
    auto er = equal_range(rr.begin(), rr.end(), x - z);
    cnt += er.second - er.first;
  }
  cout << cnt;
  return 0;
}
