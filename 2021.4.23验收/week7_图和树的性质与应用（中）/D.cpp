#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;

class Edge //单向边
{
public:
  int from = -1;  //边起点
  int to = -1;    //边终点
  int value = -1; //边权
};

class station //车站
{
public:
  int value = -1; //权值
  int to = -1;    //目的地
};
bool operator<(const station &x, const station &y)
{
  return x.value > y.value;
}

int T, n, m;         //T个测试用例，n个点，m条单向边
int nE;              //newEdge
int cst[1000100];    //cost[]
vector<Edge> ea[2];  //图中的边，两行分别为去和回
vector<int> head[2]; //链式前向星，两行分别为去和回

void addEdge(int i, int from, int to, int cst) //在图中添加单向边
{
  Edge ed;
  ed.value = cst;
  ed.from = head[i][from];
  ed.to = to;
  ea[i].emplace_back(ed); //边进入边集
  head[i][from] = nE;
}

void SPFA(int tt, int bbgg)
{
  priority_queue<station> hp; //队列存储被成功松弛过的点
  station begin, end;
  begin.to = bbgg;
  cst[bbgg] = 0;
  begin.value = 0;
  hp.emplace(begin);  //源点入队，队列初始化
  while (!hp.empty()) //队列不为空
  {
    begin = hp.top();
    hp.pop();                                                     //从队首取点
    for (int i = head[tt][begin.to]; i != -1; i = ea[tt][i].from) //松弛队首的邻接点
    {
      end.to = ea[tt][i].to;
      if (cst[end.to] > cst[begin.to] + ea[tt][i].value) //如果被成功松弛，该点入队
      {
        cst[end.to] = cst[begin.to] + ea[tt][i].value;
        end.value = cst[end.to];
        hp.emplace(end);
      }
    }
  }
}

void sol()
{
  int ans = 0;
  for (int j = 1; j <= n; ++j)
  {
    cst[j] = INF; //初始化边权
  }
  SPFA(0, 1); //正图跑SPFA，去的花费
  unordered_set<int> se;
  se.emplace(1);
  for (int j = 1; j <= n; ++j)
  {
    ans += cst[j];
  }
  for (int j = 1; j <= n; j++)
  {
    cst[j] = INF;
  }
  se.emplace(1);
  SPFA(1, 1); //反图跑SPFA，回来的花费
  for (int j = 1; j <= n; j++)
  {
    ans += cst[j];
  }
  cout << ans << '\n';
}

int main()
{
  ios::sync_with_stdio(false);
  cin >> T;
  while (T--)
  {
    int s, e, c;
    cin >> n >> m; //n:车站数量  m:车站之间的单项路径数
    for (int i = 0; i <= 1; ++i)
    {
      ea[i].clear();
      head[i].clear();
    }
    for (int j = 1; j <= n + 1; ++j)
    {
      cst[j] = INF;
      head[1].emplace_back(-1);
      head[0].emplace_back(-1);
    }
    for (int i = 1; i <= m; i++)
    {
      cin >> s >> e >> c;
      addEdge(0, s, e, c);
      addEdge(1, e, s, c);
      nE++;
    }
    sol();
    nE = 0;
  }
  return 0;
}
