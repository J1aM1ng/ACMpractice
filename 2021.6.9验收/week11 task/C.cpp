#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn = 1000010;
int n;
ll matx[3][maxn], dp[maxn][3];
int main()
{
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < 3; ++i)
  {
    for (int j = 0; j < n; ++j)
    {
      cin >> matx[i][j];
    }
  }
  for (int i = 1; i <= n - 1; ++i)
  {
    for (int j = 0; j < 3; ++j)
    {
      dp[i][j] = min(dp[i - 1][0] + abs(matx[j][i] - matx[0][i - 1]),
                     min(dp[i - 1][1] + abs(matx[j][i] - matx[1][i - 1]), dp[i - 1][2] + abs(matx[j][i] - matx[2][i - 1])));
    }
  }
  cout << min(dp[n - 1][0], min(dp[n - 1][1], dp[n - 1][2])) << '\n';
  return 0;
}
