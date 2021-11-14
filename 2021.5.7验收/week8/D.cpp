#include <bits/stdc++.h>
using namespace std;
int n, m, ans = 0; //n个人，m个消息
const int maxn = 1e6 + 50;
bool vis[maxn];
vector<int> dfn; //逆后序序列
struct Edge      //出边
{
  Edge *nxt = nullptr; //邻接点链表的下一个邻接点
  int to = -1;         //边的终点
  Edge(){};
  Edge(int to, Edge *nxt)
  {
    this->to = to;
    this->nxt = nxt;
  };
};
Edge head[maxn]; //链式前向星

void addEdge(int x, int y)
{
  head[x].nxt = new Edge(y, head[x].nxt);
}

void dfs1(int x)
{
  vis[x] = true;
  Edge *now = head[x].nxt;
  Edge *last = &head[x];
  while (now != nullptr && now->to != -1)
  {
    if (!vis[now->to])
    {
      dfs1(now->to);
    }
    last = now;
    now = now->nxt;
  }
  dfn.emplace_back(x);
}

void dfs2(int x) //遍历正图，通过bfs逆后序
{
  vis[x] = true;
  Edge *now = head[x].nxt;
  Edge *last = &head[x];
  while (now != nullptr && now->to != -1)
  {
    if (!vis[now->to])
    {
      dfs2(now->to);
    }
    last = now;
    now = now->nxt;
  }
}

void kosaraju()
{
  for (int i = 1; i <= n; i++)
  {
    if (!vis[i])
    {
      dfs1(i);
    }
  }
  memset(vis, false, sizeof(vis));
  for (int i = n - 1; i >= 0; i--) //"逆"后序
  {
    if (!vis[dfn[i]])
    {
      dfs2(dfn[i]);
      ans++;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
  {
    head[i].nxt = new Edge(-1, nullptr);
  }
  for (int i = 1; i <= m; i++)
  {
    int t1, t2;
    cin >> t1 >> t2;
    addEdge(t1, t2);
  }
  kosaraju();
  cout << ans;
  return 0;
}