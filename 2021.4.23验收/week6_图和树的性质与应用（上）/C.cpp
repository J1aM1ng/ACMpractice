#include <bits/stdc++.h>
using namespace std;               //并查集通过树形结构存储
int n, m, pr[100010], vis[100010]; //pr[i]：第i个元素的父元素
int todo, Start, End, r1, r2;      //todo:还要修的路   r1:root1,区间起点的根  Start/End:每条路的起点和终点
int find(int root)                 //对参数（任意一个元素），查找根节点并进行路径压缩
{
  int son = root;
  while (root != pr[root]) //寻找根节点，退出循环时root即为根节点
  {
    root = pr[root];
  }
  while (son != root) //路径压缩，使son节点到根节点路径上的每个节点的父节点均为根节点
  {
    int temp = pr[son];
    pr[son] = root;
    son = temp;
  }
  return root;
}

void join(int r1, int r2) //判断root1所在并查集与root2所在并查集是否连通，若不连通，则执行合并操作
{
  int t1 = find(r1), t2 = find(r2);
  if (t1 != t2) //如果不连通，就把其所在连通分支合并
  {
    pr[t1] = t2;
    --todo; //r1和r2联通了，要修的路减1
  }
}

int main()
{
  cin >> n >> m;
  todo = n - 1;                //还要修的路有n-1条
  for (int i = 1; i <= n; ++i) //初态，每个数都是一个并查集，根是他自己
  {
    pr[i] = i; //双亲是他自己
  }
  while (m--)
  {
    cin >> Start >> End;
    join(Start, End); //连通Start和End所在的并查集
    cout << todo << '\n';
  }
  return 0;
}