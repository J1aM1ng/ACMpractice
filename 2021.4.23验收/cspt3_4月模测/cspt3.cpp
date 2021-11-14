#include <bits/stdc++.h> //模拟+字符串处理
using namespace std;
string s;
int solve(int *pol)
{
  cin >> s;        //程序字符串，空格和换行均忽略
  if (s[0] == 'E') //END，结束当前层的solve
  {
    return 0;
  }
  if (s[0] == 'B') //BEGIN，开始程序的solve，递归向深处，输入下一行
  {
    while (solve(pol))
      ;
  }
  else if (s[0] == 'L') //LOOP
  {
    stringstream stream;
    int t = -1, t_pol[15] = {0}; //temp pol 暂时记录最终输出的多项式每项的t_pol[i],i为每项的指数
    t = 0;
    cin >> s;        //输入LOOP内的内容
    if (s[0] != 'n') //LOOP+NUM
    {
      stream << s;
      stream >> t; //字符串转化为数字
    }
    while (solve(t_pol)) //继续递归
      ;
    if (t == -1) //如果目前为止（当前层）还没有运行时间，则
    {
      for (int i = 10; i >= 1; i--)
      {
        t_pol[i] = t_pol[i - 1]; //累加一下这些系数
      }
      t_pol[0] = 0;
    }
    else //如果目前为止（当前层）有运行时间，则累加本层循环内的运行时间，并同步到t_pol数组中
    {
      for (int i = 0; i <= 10; i++) //每层循环的运行时间同步到t_pol数组中
      {
        t_pol[i] *= t;
      }
    }
    for (int i = 0; i <= 10; i++) //更新到pol[i]
    {
      pol[i] += t_pol[i];
    }
  }
  else //该条语句为OP
  {
    cin >> s;
    stringstream stream;
    stream << s;
    int temp;
    stream >> temp;
    pol[0] += temp;
    return solve(pol); //继续递归
  }
  return 1;
}
int main()
{
  ios::sync_with_stdio(false);
  int t;             //运行时间
  int pol[15] = {0}; //最终输出的多项式每项的系数为pol[i],i为每项的指数
  t = 0;
  solve(pol);
  cout << "Runtime = ";
  for (int j = 10; j >= 0; j--)
  {
    if (pol[j]) //n的某一项系数为0则直接省略该项
    {
      ++t;
      if (t != 1)
      {
        cout << "+";
      }
      if (pol[j] != 1 || j == 0)
      {
        cout << pol[j];
      }
      if ((pol[j] != 1) && (j > 0))
      {
        cout << "*";
      }
      if (j > 1)
      {
        cout << "n^" << j;
      }
      if (j == 1)
      {
        cout << "n";
      }
    }
  }
  if (!t) //如果运行时间为0，则只需打印 “Runtime = 0”。
  {
    cout << "0";
  }
  return 0;
}