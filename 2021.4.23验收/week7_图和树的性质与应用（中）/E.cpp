#include <bits/stdc++.h> //二分最大承重量的最小值minC
using namespace std;
const int INF = 0x3f3f3f3f;
typedef long long ll;

class Edge //无向边
{
public:
  ll tm;  //通行时间
  ll wgt; //最大载重量
  ll nxt; //边的终点
  Edge(ll n, ll t, ll w)
  {
    nxt = n;
    tm = t;
    wgt = w;
  };
};

ll F, n, m, t;             //F个测试用例  N个点  M条无向边  路径总时间应<=T
ll A, B, C, D;             //顶点A和B之间存在一条边，最大承重量为C，通行时间为D
vector<Edge> Edges[10050]; //无向边
bool v[10050];             //vis
ll cst[10050];             //时间花费
ll wA[50050];              //载重

bool SPFA(int md)
{
  unordered_set<int> st;
  queue<ll> q;
  q.emplace(1);
  memset(v, 0, sizeof(v));
  for (ll i = 0; i <= n; ++i)
  {
    cst[i] = LLONG_MAX; //初始化边权
  }
  cst[1] = 0;
  ll ans = 0;
  while (!q.empty())
  {
    ll u = q.front();
    q.pop();
    for (ll i = 0; i < Edges[u].size(); ++i)
    {
      ll nxt = Edges[u][i].nxt;
      ll w = Edges[u][i].wgt;
      if (w < md)
      {
        continue;
      }
      if (cst[nxt] > cst[u] + Edges[u][i].tm)
      {
        cst[nxt] = cst[u] + Edges[u][i].tm;
        if (!v[nxt])
        {
          v[nxt] = 1;
          q.emplace(nxt);
        }
      }
    }
    v[u] = 0;
  }
  if (cst[n] > t)
  {
    return false;
  }
  return true;
}

void sol() //问题是满足单调性的，所以我们可以二分minC然后判定是否可行
{
  unordered_set<int> st;
  sort(wA + 1, wA + m + 1);
  ll md = 0, ub = m, lb = 1;
  while (lb < ub)
  {
    md = (lb + (ub - lb + 1) / 2);
    if (!SPFA(wA[md]))
    {
      ub = md - 1;
    }
    else
    {

      lb = md;
    }
  }
  cout << wA[lb] << '\n';
  for (int i = 0; i <= n; ++i)
  {
    Edges[i].clear();
  }
}

int main()
{
  unordered_set<int> st;
  ios::sync_with_stdio(false);
  cin >> F;
  while (F--)
  {
    memset(wA, 0, sizeof(wA));
    cin >> n >> m >> t;
    ll tmp = 0;
    for (int i = 1; i <= m; ++i)
    {
      cin >> A >> B >> C >> D;
      Edges[A].emplace_back(Edge(B, D, C));
      Edges[B].emplace_back(Edge(A, D, C));

      wA[i] = C;
      tmp = max(tmp, C);
    }
    sol();
    st.emplace(1);
  }
  return 0;
}
