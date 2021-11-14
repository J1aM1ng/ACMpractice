#include <bits/stdc++.h>
using namespace std;
const int maxn = 5010, maxm = 30010;
class inteval
{
public:
  int l, r, k;                   //路段l到r之间至少有k个垃圾桶
} itlArray[maxn];                //要求对应的区间
bool myCmp(inteval x, inteval y) //按结束位置排序，排序为贪心做准备
{
  return x.r < y.r;
}
bool judge[maxm] = {0}; //判断区间是否已有桶，默认均为false
int main()
{
  ios::sync_with_stdio(0);
  int n, m, ans = 0; //ans:最少需要放的垃圾桶数
  cin >> n >> m;     //n为路段数，m为要求数
  for (int i = 1; i <= m; i++)
  {
    cin >> itlArray[i].l >> itlArray[i].r >> itlArray[i].k;
  }
  sort(itlArray + 1, itlArray + m + 1, myCmp); //对m个区间根据结束位置排序
  for (int i = 1; i <= m; i++)                 //对每个区间做一次处理
  {
    int k = 0; //当前区间中已有的桶数
    for (int j = itlArray[i].l; j <= itlArray[i].r; j++)
    {
      if (judge[j])
      {
        ++k; //该区间已有桶
      }
    }
    if (k >= itlArray[i].k) //满足要求的桶数，直接处理下个区间
    {
      continue;
    }
    else                                                   //否则，不满足要求的桶数，从后往前，添加缺少的覆盖点
    {                                                      //贪心策略：
      for (int j = itlArray[i].r; j >= itlArray[i].l; j--) //从后向前遍历路段（从结束位置到开始位置），目的让各个要求
      {                                                    //对应的区间的桶尽可能重合，而重合的位置一定是每个区间的后段
        if (!judge[j])
        {
          ++k;
          ++ans;
          judge[j] = 1;
          if (k == itlArray[i].k) //如果在当前路段上放上了一个桶，恰好满足要求的桶数，直接退出该“补桶”循环
          {
            break;
          }
        }
      }
    }
  }
  cout << ans;
  return 0;
}
