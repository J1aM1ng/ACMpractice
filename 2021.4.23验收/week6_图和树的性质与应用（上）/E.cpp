#include <bits/stdc++.h>
using namespace std;
const int inf = 0x3f3f3f, maxn = 100010;
class treeEdge //树边
{
public:
  int v1;  //起点
  int v2;  //终点
  int val; //权值
  treeEdge(int v1, int v2, int val)
  {
    this->v1 = v1;
    this->v2 = v2;
    this->val = val;
  };
  ~treeEdge(){};
  bool operator<(const treeEdge &edge) const //定义边权的比较规则，变成小根堆
  {
    return this->val > edge.val;
  };
};
int n, m, a, b, c, tmp; //n块田地，m个引水渠，从a田地到b田地的引水渠花费c元   tmp：要用的抽水机的台数
long long p;            //抽水机一个p元
int Pre[maxn];          //树的每个节点的父节点
priority_queue<treeEdge> Edge;
int pre(int x) //返回该元素在的树的根节点
{
  if (Pre[x] == x) //根节点
  {
    return x;
  }
  else
  {
    return pre(Pre[x] = Pre[Pre[x]]);
  }
}

void combine(int x, int y) //使两块田连通，即挖引水渠
{
  int t1 = pre(x); //元素x所在树的根
  int t2 = pre(y); //元素y所在树的根
  if (t1 != t2)    //根不同
  {
    Pre[t1] = t2; //合并的一棵树上
    --tmp;        //抽水机台数-1
  }
  return;
}

void Kruskal()
{
  long long ans = 0; //花费
  while (!Edge.empty())
  {
    treeEdge tE = Edge.top(); //存储队首元素（最小的非树边）
    Edge.pop();               //出队
    int p1 = pre(tE.v1), p2 = pre(tE.v2);
    if ((p1 != p2) && (tE.val < p)) //该引水渠是值得挖的
    {
      combine(tE.v1, tE.v2); //将该引水渠两端连通
      ans += tE.val;         //花费增加
    }
  }
  ans += tmp * p; //花费加上抽水机
  cout << ans << '\n';
  return;
}

int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> m >> p;
  while (m--)
  {
    cin >> a >> b >> c;
    Edge.emplace(a, b, c);
  }
  for (int i = 1; i <= n; ++i)
  {
    Pre[i] = i;
  }
  tmp = n; //初态，每块田都需要抽水机
  Kruskal();
  return 0;
}