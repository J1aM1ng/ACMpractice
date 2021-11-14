#include <bits/stdc++.h>
using namespace std;
// 思路：差分+前缀和 
int n;
int price[1200005];
int curP, maxP, ans;
int firstInARow;

void solve()
{
  for (int i = 0; i <= 1e6; i++)
  {
    curP += price[i];
    if (curP >= maxP)
      ans = i;
    maxP = max(curP, maxP);
  }
  curP = 0;
  for (int i = 0; i <= ans; i++)
    firstInARow += price[i];
  cout << ans << ' ' << firstInARow << endl;
}

int main()
{
  cin >> n;
  int li = 0, ri = 0;
  for (int i = 1; i <= n; i++)
  {
    scanf("%d %d", &li, &ri);
    price[li]++;
    price[ri + 1]--;
  }
  solve();
}
