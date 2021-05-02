#include <bits/stdc++.h>
using namespace std;
int n, k;
int result = 0; //合法的组合数
vector<int> numArray;
bool isPrime(int n)
{
  if (n == 1)
    return false;
  if (n == 2)
    return true;
  for (int i = 2; i * i <= n; i++)
    if (n % i == 0)
      return false;
  return true;
}

void dfs(int depth, int sum, int lastIndex) //lastIndex:已经选择的数中最后一个数的数组下标
{                                           //depth:搜索深度 已经选择的数个数
  if (depth == k)                           //深度与要组合的数字个数相同，表示找出了n个数中的一个k组合
  {
    if (isPrime(sum))
      ++result; //n中选k个，检查和是否是素数
  }
  else
  {
    for (int i = lastIndex; i < n; ++i) //没到k个 从已经选择的数中的最后一个数开始，递归寻找下一个数
    {
      dfs(depth + 1, sum + numArray[i], i + 1);
    }
  }
}
int main()
{
  cin >> n >> k;
  for (int i = 0; i < n; ++i)
  {
    int temp;
    cin >> temp;
    numArray.push_back(temp);
  }
  dfs(0, 0, 0);
  cout << result;
  return 0;
}