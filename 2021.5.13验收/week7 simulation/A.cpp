#include <bits/stdc++.h>
using namespace std;
int n, k, color[1010], ans = 0;
vector<int> sock;
int main()
{
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
  {
    int temp;
    cin >> temp;
    sock.emplace_back(temp);
  }
  for (int i = 0; i < n; i++)
  {
    ++color[sock[i]];
  }
  for (int i = 1; i <= k; i++)
  {
    int temp = color[i] / 2;
    ans += temp;
  }
  cout << ans;
  return 0;
}