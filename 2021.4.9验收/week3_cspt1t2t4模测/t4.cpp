#include <bits/stdc++.h>
using namespace std;
const int inf = 200010;
set<int> st[8];     //2^3=8，该集合容纳符合一个顾客需求的所有的面（最多8种）
int t[inf], s[inf]; //t[i]:每碗面制作完成的时间点
int main()
{
  int n, m, k; //n:制作的面的数量 m:顾客的数量 k:配料的种类数
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++)
  {
    cin >> t[i];
  }
  for (int i = 1; i <= n; i++)
  {
    int kk, v = 0; //kk:该碗面中含有的配料的种类数
    cin >> kk;
    for (int j = 1; j <= kk; j++)
    {
      int x; //该碗面含有的配料编号
      cin >> x;
      v |= (1 << (x - 1)); //v为一个三位二进制数，每一位表示一种调料，1为有，0为无。V的值代表当前面有哪几种配料
    }
    for (int j = 1; j < 8; j++)
    {
      if ((v & j) == j) //true时表明j是v的一个子集，找出v的所有子集，v：这碗面含有的调料
      {
        st[j].emplace(t[i]); //所有v的子集中均insert入v对应的面的制作时间，便于后续比较
      }
    }
  }
  for (int i = 1; i <= m; i++)
  {
    cin >> s[i]; //客人到达的时间
  }
  for (int i = 1; i <= m; i++)
  {
    int cc, v = 0; //cc:客人喜爱配料的种类数
    cin >> cc;
    for (int j = 1; j <= cc; j++)
    {
      int x;
      cin >> x;
      v |= (1 << (x - 1)); //v为一个三位二进制数，每一位表示一种调料，1为有，0为无。V的值代表当前面有哪几种配料
    }                      //v代表该客人喜欢吃的配料
    if (st[v].empty())     //该客人喜欢吃的配料没有对应的面
    {
      cout << "Angry\n";
    }
    else
    {
      int vv = *st[v].rbegin();    //做好时间最晚的面即是最靠近客人进店时间的
      cout << (s[i] - vv) << '\n'; //输出不满意度（时间差）
      for (int j = 1; j < 8; j++)
      {
        st[j].erase(vv); //清空集合st，为下个客人的喜爱的配料腾出空
      }
    }
  }
  return 0;
}