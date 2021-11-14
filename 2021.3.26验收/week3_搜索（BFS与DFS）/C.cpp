#include <bits/stdc++.h>
using namespace std;
int dp[205]; //dp[i]：到第i层楼最少要花的时间（子问题）
int a[205];  //a[i]：第i层的数字
int main()
{
  while (1)
  {
    int N, A, B; //N层  从A到B
    cin >> N;
    if (N == 0)
      break;
    cin >> A >> B;
    for (int i = 1; i <= N; ++i)
      scanf("%d", a + i);
    dp[A] = 1;
    bool t = true; //dp循环结束标志
    while (t)
    {
      t = false; //结束条件：若dp[1：n]中每个数的值都无法更新时，保持false，结束循环
      for (int i = 1; i <= N; i++)
        if (dp[i] > 0)
        {
          if (i - a[i] > 0)                                    //可以向下
            if (dp[i - a[i]] == 0 || dp[i - a[i]] > dp[i] + 1) //未访问||目前步数大于目前更优解
            {
              t = true;
              dp[i - a[i]] = dp[i] + 1;
            }
          if (i + a[i] <= N)                                   //可以向上
            if (dp[i + a[i]] == 0 || dp[i + a[i]] > dp[i] + 1) //未访问||目前步数大于目前更优解
            {
              t = true;
              dp[i + a[i]] = dp[i] + 1; //选择更优解
            }
        }
    }
    cout << dp[B] - 1 << endl; //无法到达时输出为-1    dp[B]-dp[A]
    memset(dp, 0, sizeof(dp)); //重置dp，a数组
    memset(a, 0, sizeof(a));
  }
  return 0;
}
