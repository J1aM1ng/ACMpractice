#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, sum[1000010], q;

int lbit(int x)
{
  return x & (-x);
}

void update(int x, ll val)
{
  for (int i = x; i <= n; i += lbit(i))
    sum[i] += val;
}

ll gtsum(int x)
{
  ll ans = 0;
  for (int i = x; i > 0; i -= lbit(i))
  {
    ans += sum[i];
  }
  return ans;
}

void sol()
{
  int ope, v1, v2;
  for (int i = 1; i <= q; i++)
  {
    cin >> ope >> v1 >> v2;
    if (ope == 1)
    {
      update(v1, v2);
      continue;
    }
    cout << gtsum(v2) - gtsum(v1 - 1) << '\n';
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> q;
  int tmp;
  for (int i = 1; i <= n; i++)
  {
    cin >> tmp;
    update(i, tmp);
  }
  sol();
  return 0;
}
