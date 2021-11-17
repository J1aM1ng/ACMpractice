#include <bits/stdc++.h>
using namespace std;
const int maxn = 5010;
int t1, t2, aa[maxn], bb[maxn], dp[maxn][maxn];

void sol()
{
  for (int i = 1; i <= t1; ++i)
  {
    for (int j = 1; j <= t2; ++j)
    {
      if (aa[i - 1] == bb[j - 1])
      {
        dp[i][j] = dp[i - 1][j - 1] + 1;
      }
      else
      {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      }
    }
  }
  cout << dp[t1][t2] << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin >> t1 >> t2;
  for (int i = 1; i <= t1; ++i)
  {
    cin >> aa[i - 1];
  }
  for (int i = 1; i <= t2; ++i)
  {
    cin >> bb[i - 1];
  }
  sol();
  return 0;
}
