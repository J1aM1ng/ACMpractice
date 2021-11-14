#include <bits/stdc++.h>
using namespace std;
class movie //每个人的观影（先A影院后B影院）
{
public:
  int a, b;                //AB影院
  bool operator<(movie &x) //安排观影顺序
  /* 贪心策略：johnson算法：
  a1<b1，a2<b2时，按a1<a2排序
  a1>b1，a2>b2时，按b1>b2排序
  a1=b1，a2=b2时，怎么排都可以
  把a比b小的先处理，b比a小的后处理 */
  {
    if (this->a <= this->b)
    {
      return this->a < x.a; //a<b按a升序
    }
    if (this->a > this->b)
    {
      return b > x.b; //a>b按b降序
    }
  }
} mArray[1010];                              //每个人的观影（先A影院后B影院）
movie aMovie[1010], bMovie[1010], res[2020]; //aMovie:满足a<=b的情况的人的观影  bMovie:满足a>b的情况的人的观影
int aCount = 0, bCount = 0;                  //aCount:aMovie中人的多少  bCount：bMovie中人的多少  res:最后aMovie和bMovie拼接成的人的观影
int main()
{
  ios::sync_with_stdio(0);
  int n; //观影人数
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    int aa; //第i个人在A影院的观影时间ai
    cin >> aa;
    mArray[i].a = aa;
  }
  for (int i = 1; i <= n; i++)
  {
    int bb; //第i个人在B影院的观影时间bi
    cin >> bb;
    mArray[i].b = bb;
  }
  for (int i = 1; i <= n; ++i)
  {
    if (mArray[i].a <= mArray[i].b)
    {
      ++aCount;
      aMovie[aCount] = mArray[i]; //a<=b的情况，按a升序决定观影次序
    }
  }
  sort(aMovie + 1, aMovie + 1 + aCount); //内含operator<的比较规则
  for (int i = 1; i <= n; ++i)
  {
    if (mArray[i].a > mArray[i].b)
    {
      ++bCount;
      bMovie[bCount] = mArray[i]; //a>b的情况，按b降序决定观影次序
    }
  }
  sort(bMovie + 1, bMovie + 1 + bCount); //内含operator<的比较规则
  for (int i = 1; i <= n; ++i)
  {
    if (i <= aCount)
    {
      res[i] = aMovie[i];
    }
    else
    {
      res[i] = bMovie[i - aCount];
    }
  } //连接aMovie和bMovie，先aMovie后bMovie，把a比b小的先处理，b比a小的后处理
  int t1 = 0, t2 = 0, t;
  for (int i = 1; i <= n; ++i)
  {
    if (i != n)
    {
      t2 += res[i].b; //除最后一个人外其余人在B影院的观影时间之和
    }
    if (i != 1)
    {
      t1 += res[i].a; //除第一个人外其余人在A影院的观影时间之和
    }
  }                                      //统计时间
  t = max(t1, t2) + res[1].a + res[n].b; //头+中间+尾
  cout << t;
  return 0;
}
