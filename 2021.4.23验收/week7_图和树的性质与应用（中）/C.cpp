#include <bits/stdc++.h> //找图中是否存在负环
using namespace std;
const int INF = 0x3f3f3f3f;
int F, n, m, w;     //F：测试用例数量  n个点，m条双向边，w条单向边
int cost[510][510]; //邻接矩阵存图
bool floyd()        //弗洛伊德判负环
{
  for (int k = 1; k <= n; k++)
  {
    for (int i = 1; i <= n; i++)
    {
      for (int j = 1; j <= n; j++)
      {
        if (cost[i][k] != -1 && cost[k][j] != -1) //j到i，i到k的单向边都存在
        {
          if (cost[i][j] == -1) //j到k的单向边不存在
          {
            cost[i][j] = cost[i][k] + cost[k][j];
          }
          else //i到j的单向边存在
          {
            cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]); //松弛
          }
          if (cost[i][j] <= -1 && (i == j)) //有负环
          {
            return true;
          }
        }
      }
    }
  }
  return false;
}
int main()
{
  ios::sync_with_stdio(false);
  cin >> F;
  for (int i = 1; i <= F; i++)
  {
    int s = 0, e = 0, t = 0;
    memset(cost, -1, sizeof(cost)); //边权均初始化为-1
    cin >> n >> m >> w;
    for (int j = 1; j <= n; j++)
    {
      cost[j][j] = 0; //初始化自己到自己
    }
    for (int j = 1; j <= m; j++) //初始化双向边
    {
      cin >> s >> e >> t;
      cost[s][e] = t;
      cost[e][s] = t;
    }
    for (int j = 1; j <= w; j++) //初始化单向边（并可能覆盖对应双向边的一个方向）
    {
      cin >> s >> e >> t;
      cost[s][e] = -t;
    }
    bool judge = floyd();
    if (judge) //该图有负环
    {
      cout << "YES\n";
    }
    else //无负环
    {
      cout << "NO\n";
    }
  }
  return 0;
}