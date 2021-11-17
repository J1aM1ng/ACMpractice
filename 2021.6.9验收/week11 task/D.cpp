#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
int n, sto[maxn], tp[maxn];

int lbt(int x)
{
  return x & (-x);
}

void upd(int ps, int dit)
{
  for (; ps < maxn; ps += lbt(ps))
  {
    tp[ps] = max(tp[ps], dit);
  }
}

int ask(int ps)
{
  int tmp = 0;
  for (; ps > 0; ps -= lbt(ps))
  {
    tmp = max(tmp, tp[ps]);
  }
  return tmp;
}

void sol()
{
  upd(sto[0], 1);
  int ans = -1, leftMax = -1;
  for (int i = 1; i < n; ++i)
  {
    leftMax = ask(sto[i] - 1);
    upd(sto[i], leftMax + 1);
    ans = max(ans, leftMax + 1);
  }
  cout << ans << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; ++i)
  {
    cin >> sto[i - 1];
  }
  sol();
  return 0;
}
