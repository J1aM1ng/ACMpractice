#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
const int MAXM = 1e6 + 10;

int lb(int x)
{
  return x & (-x);
}
struct Program
{
  int x;
  int y;
} poses[MAXN];

int n, sum[1000010], prog[MAXN];

void toSum(int pos)
{
  for (; pos <= MAXM; pos += lb(pos))
  {
    sum[pos] += 1;
  }
}

int ck(int pos)
{
  int res = 0;
  for (; pos >= 1; pos -= lb(pos))
  {
    res += sum[pos];
  }
  return res;
}

bool myCmp(const Program &a, const Program &b)
{
  if (a.x == b.x)
  {
    return a.y < b.y;
  }
  return a.x < b.x;
}

void sol()
{
  sort(poses + 1, poses + 1 + n, myCmp);
  for (int i = 1; i <= n; ++i)
  {
    int tmp = ck(poses[i].y + 1);
    prog[tmp]++;
    toSum(poses[i].y + 1);
  }
  for (int i = 0; i < n; ++i)
    printf("%d\n", prog[i]);
}

int main()
{
  cin >> n;
  int curX, curY;
  for (int i = 1; i <= n; ++i)
  {
    scanf("%d %d", &curX, &curY);
    poses[i].x = curX, poses[i].y = curY;
  }
  sol();
  return 0;
}
