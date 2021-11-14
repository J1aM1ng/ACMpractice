#include <bits/stdc++.h> //差分约束
using namespace std;
const int maxn = 1e6 + 50;
int n, m;                   //n个同学，m条信息   第i个同学的学号为i
int in_deg[maxn];           //各个点的入度
vector<int> ans, vec[maxn]; //存储结果，即成绩排名序列
//vec[]：邻接表，存放每个节点的邻接点（与其相连的边）

bool topoSort()
{
  int u, v, len;                                    //任意节点u，u的任意邻接点v，邻接点个数len
  priority_queue<int, vector<int>, greater<int>> q; //存储入度为零的点的最小优先队列
  while (!q.empty())
    q.pop();
  for (int i = 1; i <= n; i++)
  {
    if (in_deg[i] == 0) //入度为零，入队
    {
      q.emplace(i);
    }
  }
  while (!q.empty())
  {
    u = q.top();
    q.pop();
    ans.emplace_back(u);

    len = vec[u].size(); //节点u的邻接节点的个数
    for (int i = 0; i < len; i++)
    {
      v = vec[u][i];      //v:某个邻接点（即u出发的出边的终点）
      in_deg[v]--;        //节点v的入度减1
      if (in_deg[v] == 0) //若该邻接点v入度变为0，则入队
        q.emplace(v);
    }
  }
  if (ans.size() == n)
    return true;
  else
    return false;
}
int main()
{
  ios::sync_with_stdio(false);
  int a, b;
  cin >> n >> m; //n个同学，m条信息   第i个同学的学号为i
  memset(in_deg, 0, sizeof(in_deg));
  for (int i = 0; i < m; i++)
  {
    cin >> a >> b;
    vec[a].emplace_back(b);
    in_deg[b]++;
  }
  if (topoSort()) //图中无环路
  {
    int tLen = ans.size();
    for (int i = 0; i < n; i++)
    {
      cout << ans[i] << " ";
    }
  }
  else
    cout << "error!" << '\n';
  return 0;
}