#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll r, y, g, cnt = 0;
int n;
int main()
{
  ios::sync_with_stdio(false);
  cin >> r >> y >> g >> n;
  int k, t;
  for (int i = 1; i <= n; i++)
  {
    cin >> k >> t;
    if (k == 0 || k == 1)
    {
      cnt += t;
      continue;
    }
    else if (k == 2)
    {
      cnt += (t + r);
      continue;
    }
  }
  cout << cnt;
  return 0;
}