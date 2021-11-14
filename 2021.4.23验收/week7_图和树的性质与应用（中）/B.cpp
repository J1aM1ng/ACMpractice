<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
int ans = 0;
struct inteval //装车区间
{
public:
  int left;  //区间左端点
  int right; //区间右端点
  int num;   //在该区间装车的人数，为0/1/2
} load[1000010];
int main()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    int t1, t2; //ai bi 小H装车的时间段
    cin >> t1 >> t2;
    for (int j1 = t1, j2 = t1 + 1; j2 <= t2; j1++, j2++)
    {
      load[j1].left = j1;
      load[j1].right = j2;
      ++load[j1].num;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    int t1, t2;
    cin >> t1 >> t2;
    for (int j1 = t1, j2 = t1 + 1; j2 <= t2; j1++, j2++)
    {
      load[j1].left = j1;
      load[j1].right = j2;
      ++load[j1].num;
      if (load[j1].num == 2) //该区间两人均装车
      {
        ++ans;
      }
    }
  }
  cout << ans;
  return 0;
=======
#include <bits/stdc++.h>
using namespace std;
int ans = 0;
struct inteval //装车区间
{
public:
  int left;  //区间左端点
  int right; //区间右端点
  int num;   //在该区间装车的人数，为0/1/2
} load[1000010];
int main()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    int t1, t2; //ai bi 小H装车的时间段
    cin >> t1 >> t2;
    for (int j1 = t1, j2 = t1 + 1; j2 <= t2; j1++, j2++)
    {
      load[j1].left = j1;
      load[j1].right = j2;
      ++load[j1].num;
    }
  }
  for (int i = 1; i <= n; i++)
  {
    int t1, t2;
    cin >> t1 >> t2;
    for (int j1 = t1, j2 = t1 + 1; j2 <= t2; j1++, j2++)
    {
      load[j1].left = j1;
      load[j1].right = j2;
      ++load[j1].num;
      if (load[j1].num == 2) //该区间两人均装车
      {
        ++ans;
      }
    }
  }
  cout << ans;
  return 0;
>>>>>>> 094bdc4d9ccc8ffc29ad708c5b504d76fd33efcd
}