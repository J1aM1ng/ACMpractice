#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 2e5 + 50;
ll t[MAX << 2];
ll m, p, n, x, t1, t2, op;
char s[3];
void uudd(ll Current, ll l, ll r, ll p, ll x);

ll ck(ll Current, ll l, ll r, ll qLeft, ll qRight)
{
  if (qLeft <= l && r <= qRight)
  {
    return t[Current];
  }
  ll mid = (l + r) >> 1;
  ll ans = 0;
  if (qLeft <= mid)
  {
    ans = ck(Current << 1, l, mid, qLeft, qRight);
  }
  if (mid < qRight)
  {
    ans = max(ans, ck(Current << 1 | 1, mid + 1, r, qLeft, qRight));
  }
  return ans;
}

void sol()
{

  while (op--)
  {
    scanf("%s%lld", s, &x);
    if (s[0] == 'A')
    {
      ++n;
      uudd(1, 1, m, n, (t1 + x) % p);
    }
    else
    {
      t1 = ck(1, 1, m, n - x + 1, n);
      printf("%lld\n", t1);
    }
  }
}

void uudd(ll Current, ll l, ll r, ll p, ll x)
{
  if (l == r)
  {
    t[Current] = x;
    return;
  }
  ll mid = (l + r) / 2;
  if (p <= mid)
  {
    uudd(Current << 1, l, mid, p, x);
  }
  else if (p > mid)
  {
    uudd(Current << 1 | 1, mid + 1, r, p, x);
  }
  t[Current] = max(t[Current << 1], t[Current << 1 | 1]);
}

int main()
{
  ios::sync_with_stdio(false);
  scanf("%lld%lld", &m, &p);
  op = m;
  sol();
  return 0;
}
