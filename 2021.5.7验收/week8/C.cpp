#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f, maxn = 1e6 + 50;
int n, m;
bool vis[maxn]; //判断该点是否在队列中（在队列中表示已经被松弛过，且可被取出来遍历）
int dis[maxn];  //单源最短路中的距离数组
int cnt[maxn];
queue<int> q;
struct Edge //图中每个节点的出边
{
  Edge *nxt = nullptr;
  int to = -1;  //终点
  int val = -1; //边权
  Edge(){};
  Edge(int to, int val, Edge *nxt)
  {
    this->to = to;
    this->val = val;
    this->nxt = nxt;
  };
};
Edge head[maxn]; //链式前向星存图

void addEdge(int x, int y, int val) //建立一条单向边
{
  head[x].nxt = new Edge(y, val, head[x].nxt);
}

bool SPFA()
{
  q.emplace(0);
  vis[0] = true;
  for (int i = 0; i <= n; ++i)
  {
    dis[i] = INF; //初始化dis数组
  }
  dis[0] = 0; //源点
  while (!q.empty())
  {
    int tmp = q.front();
    q.pop();
    vis[tmp] = false;
    Edge *last = &head[tmp];
    Edge *now = head[tmp].nxt;

    while ((now != nullptr) && (now->to != -1))
    {
      if (dis[tmp] + now->val < dis[now->to])
      {
        dis[now->to] = dis[tmp] + now->val;
        cnt[now->to] = cnt[tmp] + 1;
        if (cnt[now->to] > n + 1)
        {
          return false; //无解，矛盾
        }
        if (!vis[now->to])
        {
          q.emplace(now->to);
          vis[now->to] = true;
        }
      }
      last = now;
      now = now->nxt;
    }
  }
  return true; //有解
}

int main()
{
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i <= n; ++i)
  {
    head[i].nxt = new Edge(-1, 0, nullptr); //初始化链式前向星
  }
  for (int i = 1; i <= n; ++i)
  {
    addEdge(i - 1, i, 1);
    addEdge(i, i - 1, 0);
  }
  for (int i = 1; i <= m; ++i)
  {
    int k, a, b, c;
    cin >> k >> a >> b >> c;
    switch (k) //根据k值的不同，转化为<=（即经典差分约束）来存
    {
    case 1:
      addEdge(a - 1, b, c);
      break;
    case 2:
      addEdge(b, a - 1, -c);
      break;
    case 3:
      addEdge(a - 1, b, c - 1);
      break;
    case 4:
      addEdge(b, a - 1, -1 - c);
      break;
    case 5:
      addEdge(b, a - 1, -c);
      addEdge(a - 1, b, c);
      break;
    default:
      break;
    }
  }
  bool judge = SPFA();
  if (judge) //有解
  {
    cout << dis[n] << '\n';
  }
  else //无解
  {
    cout << "impossible" << '\n';
  }
  return 0;
}