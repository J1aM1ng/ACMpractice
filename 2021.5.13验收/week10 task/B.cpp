#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
typedef long long ll;
ll lr = -INF, lw = INF, mid;
double tmid;
int n;
vector<double> arr;
int main()
{
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    int tmp;
    cin >> tmp;
    arr.emplace_back(tmp);
  }
  auto itr = arr.begin();
  sort(itr, itr + n);
  bool judge = n % 2 == 0 ? 1 : 0; //偶数为1，奇数为0
  lr = arr[n - 1];
  lw = arr[0];
  if (!judge) //n为奇数
  {
    mid = arr[(n - 1) / 2];
    cout << lr << " " << mid << " " << lw;
  }
  if (judge) //n为偶数
  {
    tmid = (arr[n / 2] + arr[n / 2 - 1]) / 2;
    cout << lr << " ";
    if (tmid - int(tmid) != 0) //分数
    {
      cout << fixed << setprecision(1) << tmid;
    }
    else //整数
      cout << (int)tmid;
    cout << " " << lw;
  }
  return 0;
}