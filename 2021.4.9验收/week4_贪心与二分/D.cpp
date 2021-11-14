<<<<<<< HEAD
#include <bits/stdc++.h> //二分答案，找最大平均数
using namespace std;
double v[100010], fro[100010], b[100010]; //v[i]:第i个贝壳的体积  fro[i]：贝壳体积与目前平均数之差的 前缀和（前面元素之和加上第i个元素）
int main()                                //b[i]:第i个贝壳的体积减去目前的“极大平均值”mid
{
  int n, L;                                   //共n个贝壳，贝克序列长度不小于L
  double l = -1e6, r = 1e6, precision = 1e-6; //二分左端点 二分右端点  精度
  cin >> n >> L;
  for (int i = 1; i <= n; i++)
  {
    cin >> v[i]; //输入
  }
  while (r - l > precision) //<=时退出循环，二分结束，l和r很接近，答案已被二分出来了
  {
    double mid = (r + l) / 2; //假定最大平均数是mid
    for (int i = 1; i <= n; i++)
    {
      b[i] = v[i] - mid;
      fro[i] = fro[i - 1] + b[i]; //贝壳体积与目前平均数之差的 前缀和（除去假设的最大平均数mid）
    }
    double maxx = -1e10, minn = 1e10; //minn:最小的前缀和   maxx：连续的最大和
    for (int i = L; i <= n; i++)
    {
      minn = min(minn, fro[i - L]);    //最小的前缀和
      maxx = max(maxx, fro[i] - minn); //前缀和（大于L）减去最小的前缀 ,得到连续（大于L）的最大和
      //减去前面比较小（尽可能取最小）的值，可以使maxx尽可能大
      //连续的和最大，表明平均值比较大
    }
    if (maxx >= 0) //maxx>0代表假设的mid可以得到，l初始<0，l右移
    {
      l = mid; //左端点右移
    }
    else //假设的mid不可以得到，r初始>0，r左移
    {
      r = mid; //右端点左移
    }
  }
  cout << int(r * 1000); //最后l=r=答案
  return 0;
=======
#include <bits/stdc++.h> //二分答案，找最大平均数
using namespace std;
double v[100010], fro[100010], b[100010]; //v[i]:第i个贝壳的体积  fro[i]：贝壳体积与目前平均数之差的 前缀和（前面元素之和加上第i个元素）
int main()                                //b[i]:第i个贝壳的体积减去目前的“极大平均值”mid
{
  int n, L;                                   //共n个贝壳，贝克序列长度不小于L
  double l = -1e6, r = 1e6, precision = 1e-6; //二分左端点 二分右端点  精度
  cin >> n >> L;
  for (int i = 1; i <= n; i++)
  {
    cin >> v[i]; //输入
  }
  while (r - l > precision) //<=时退出循环，二分结束，l和r很接近，答案已被二分出来了
  {
    double mid = (r + l) / 2; //假定最大平均数是mid
    for (int i = 1; i <= n; i++)
    {
      b[i] = v[i] - mid;
      fro[i] = fro[i - 1] + b[i]; //贝壳体积与目前平均数之差的 前缀和（除去假设的最大平均数mid）
    }
    double maxx = -1e10, minn = 1e10; //minn:最小的前缀和   maxx：连续的最大和
    for (int i = L; i <= n; i++)
    {
      minn = min(minn, fro[i - L]);    //最小的前缀和
      maxx = max(maxx, fro[i] - minn); //前缀和（大于L）减去最小的前缀 ,得到连续（大于L）的最大和
      //减去前面比较小（尽可能取最小）的值，可以使maxx尽可能大
      //连续的和最大，表明平均值比较大
    }
    if (maxx >= 0) //maxx>0代表假设的mid可以得到，l初始<0，l右移
    {
      l = mid; //左端点右移
    }
    else //假设的mid不可以得到，r初始>0，r左移
    {
      r = mid; //右端点左移
    }
  }
  cout << int(r * 1000); //最后l=r=答案
  return 0;
>>>>>>> 094bdc4d9ccc8ffc29ad708c5b504d76fd33efcd
}