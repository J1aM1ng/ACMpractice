<<<<<<< HEAD
#include <bits/stdc++.h> //二分答案+贪心
using namespace std;
int w[100010];             //石头序列，w[i]为第i块石头的重量
int l = 0, r = 0, mid = 0; //左端点，右端点，中点，二分答案
int n, m;                  //n个石头分成m段
bool ck(int t)             //check，贪心
{
  int period = 0, tt = 0; //period:段数（区间数）  tt:当前段的总重量
  for (int i = 1; i <= n; ++i)
  {
    if (tt + w[i] <= t) //t=mid
    {
      tt += w[i]; //贪心：能加上就加上
    }
    else //tt>mid,不能加上
    {
      tt = w[i]; //tt重新赋值
      ++period;  //重新开一段，段数++
    }
  }
  return (period >= m); //判断段数是否不小于m，若是，说明我们要是分成m段而非period段，分段少了和大了，答案会在mid右边，
  //应使左端点右移，否则，说明我们要是分成m段而非period段，分段多了和小了，答案会在mid左边，应使右端点左移
}
int main()
{
  ios::sync_with_stdio(0);
  cin >> n >> m; //n个石头分成m段
  for (int i = 1; i <= n; i++)
  {
    cin >> w[i];
    l = max(l, w[i]); //左端点初值为重量最大值
  }
  for (int i = 1; i <= n; i++)
  {
    r += w[i]; //右端点的初值为石头序列重量的和
  }
  while (l <= r)
  {
    mid = (l + r) >> 1; //中点
    if (ck(mid))
    {
      l = mid + 1; //左端点右移
    }
    else
    {
      r = mid - 1; //右端点左移
    }
  }
  printf("%d\n", l); //最后l=r=答案
  return 0;
}
=======
#include <bits/stdc++.h> //二分答案+贪心
using namespace std;
int w[100010];             //石头序列，w[i]为第i块石头的重量
int l = 0, r = 0, mid = 0; //左端点，右端点，中点，二分答案
int n, m;                  //n个石头分成m段
bool ck(int t)             //check，贪心
{
  int period = 0, tt = 0; //period:段数（区间数）  tt:当前段的总重量
  for (int i = 1; i <= n; ++i)
  {
    if (tt + w[i] <= t) //t=mid
    {
      tt += w[i]; //贪心：能加上就加上
    }
    else //tt>mid,不能加上
    {
      tt = w[i]; //tt重新赋值
      ++period;  //重新开一段，段数++
    }
  }
  return (period >= m); //判断段数是否不小于m，若是，说明我们要是分成m段而非period段，分段少了和大了，答案会在mid右边，
  //应使左端点右移，否则，说明我们要是分成m段而非period段，分段多了和小了，答案会在mid左边，应使右端点左移
}
int main()
{
  ios::sync_with_stdio(0);
  cin >> n >> m; //n个石头分成m段
  for (int i = 1; i <= n; i++)
  {
    cin >> w[i];
    l = max(l, w[i]); //左端点初值为重量最大值
  }
  for (int i = 1; i <= n; i++)
  {
    r += w[i]; //右端点的初值为石头序列重量的和
  }
  while (l <= r)
  {
    mid = (l + r) >> 1; //中点
    if (ck(mid))
    {
      l = mid + 1; //左端点右移
    }
    else
    {
      r = mid - 1; //右端点左移
    }
  }
  printf("%d\n", l); //最后l=r=答案
  return 0;
}
>>>>>>> 094bdc4d9ccc8ffc29ad708c5b504d76fd33efcd
