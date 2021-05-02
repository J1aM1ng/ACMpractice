#include <bits/stdc++.h>
using namespace std;
char board[10][10];
int column[10]; //记录一列是否有棋子，0无1有
long long res;  //方案数
int n, k, depth;
void dfs(int temp) //temp：
{
  if (depth == k) //深度==k，表明已经放好了k个棋子
  {
    ++res;
    return;
  }
  if (temp > n)
    return;
  for (int i = 1; i <= n; ++i) //遍历一行
  {
    if ((!column[i]) && (board[temp][i] == '#'))
    {
      column[i] = 1;
      ++depth;       //放好一个棋子
      dfs(temp + 1); //继续放下个棋子
      column[i] = 0; //取消标记该位置
      --depth;
    }
  }
  dfs(temp + 1); //跳转到下一层
}

int main()
{
  while (true)
  {
    scanf("%d%d", &n, &k);
    if ((n == -1) && (k == -1))
    {
      break;
    }                                  //n*n棋盘，k个棋子
    memset(column, 0, sizeof(column)); //重置column数组
    for (int i = 1; i <= n; ++i)
    {
      for (int j = 1; j <= n; ++j)
      {
        cin >> board[i][j];
      }
    } //输入棋盘
    depth = res = 0;
    dfs(1);
    printf("%d\n", res);
  }
  return 0;
}