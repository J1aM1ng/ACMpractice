#include <bits/stdc++.h>
using namespace std;
const int maxn = 105010, inf = 0x3f3f3f3f;
struct Node //树节点
{
  int nxt;
  int num;
  Node()
  {
    nxt = -1;
    num = -1;
  }
};

int n, Start, End, sequence;
int mV1[maxn], mV2[maxn];
Node stor[3 * maxn];  //链式前向星
Node nodeArray[maxn]; //存储村庄节点

void cEdge(int v1, int v2) //建立一条v1到v2的有向边
{
  int newN = ++sequence;
  stor[newN].num = v2;
  stor[newN].nxt = nodeArray[v1].nxt;
  nodeArray[v1].nxt = newN;
}

void nEdge(int v1, int v2) //在v1v2之间建立双向边
{
  cEdge(v1, v2);
  cEdge(v2, v1);
}

int BFS(int st, bool md, bool ky) //mode：模式0：搜到最远   模式1：从v1/v2出发，求其到各个点的距离
{                                 //key：ture时从v1出发，存mV1,false时从v2出发，存mV2
  int current = nodeArray[st].nxt;
  int theEnd = st;
  queue<int> q;
  set<int> vis;
  while (stor[current].nxt != -1)
  {
    q.emplace(stor[current].num);
    current = stor[current].nxt;
  }
  while (!q.empty())
  {
    int theNum = q.front();
    q.pop();
    vis.emplace(theNum);
    theEnd = theNum;
    current = nodeArray[theNum].nxt;
    while (stor[current].nxt != -1)
    {
      if (!vis.count(stor[current].num))
      {
        q.emplace(stor[current].num);
        if (md)
        {
          if (ky)
          {
            mV1[stor[current].num] = mV1[theNum] + 1;
          }
          else
          {
            mV2[stor[current].num] = mV2[theNum] + 1;
          }
        }
      }
      current = stor[current].nxt;
    }
  }
  return theEnd;
}

void solute()
{
  int V1 = BFS(1, 0, 0);  //从第一个点出发，找v1：树的最长路（直径）的一个端点
  int V2 = BFS(V1, 0, 0); //从v1出发，找v2：树的最长路（直径）的另一个端点
  BFS(V1, 1, 1);          //从V1出发，求v1到各点的距离，存入mV1[]中
  BFS(V2, 1, 0);          //从V2出发，求v2到各点的距离，存入mV2[]中
  for (int i = 1; i <= n; i++)
  {
    cout << max(mV1[i] + 1, mV2[i] + 1) << ' ';
  }
  cout << '\n';
}

int main()
{
  ios::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    int newN = ++sequence;
    nodeArray[i].num = i;
    nodeArray[i].nxt = newN;
  }
  for (int i = 1; i <= n - 1; ++i)
  {
    cin >> Start >> End;
    nEdge(Start, End);
  }
  solute();
}