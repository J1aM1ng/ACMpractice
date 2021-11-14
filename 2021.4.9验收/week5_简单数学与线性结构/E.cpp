<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f, maxn = 100010;
const LL MOD = 1e9 + 7, LLF = 1e18 + 3; //LLF要开大一点，MOD为结果要取的模
const LL prime[30] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int n, m;              //n：数列长度  m:操作次数  prime：100以内所有质数
LL l, r, c, b, pw[30]; //pw[i]:组成最大公因数的第i个质数的幂次
LL chaFen[maxn][30];   //二维差分数组，对[1,100]质数均设置一维差分数组(存幂次，才能用差分数组，变乘法为加法)
//这个差分数组实际上初始化为n个数可分解成的质因数的幂次，后续通过乘进来的数c实现单点修改
LL qPow(LL base, LL pow) //快速幂
{
  LL res = 1;
  while (pow > 0)
  {
    if (pow & 1) //奇数额外乘上a
    {
      res = res * base % MOD;
    }
    pow >>= 1; //每次将pow/2，复杂度log级
    base = (base * base) % MOD;
  }
  return res % MOD;
}

void fih() //求最大公约数的质数组成
{
  LL temp = 0, res = 1;
  for (int i = 1; i <= 25; ++i) //遍历pw[]
  {
    temp = 0;
    pw[i] = LLF;
    for (int j = 1; j <= n; ++j) //遍历n个元素的数列
    {
      temp += chaFen[j][i];
      pw[i] = min(pw[i], temp); //pw[i]存储：对于该质数（第i个质数），n个元素的数列中每个元素的质数组成中该质数的幂次的最小值
    }                           //也即n个元素对于该质数的最大公因数
  }
  for (int i = 1; i <= 25; ++i)
  {
    res = res * qPow(prime[i], pw[i]) % MOD; //底数是各个质数，指数是pw[i]中存的第i个质数的最小幂次
  }
  cout << res << '\n';
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i)
  {
    cin >> l >> r >> c >> b;
    for (int i = 1; i <= 25; ++i)
    {
      if (c < prime[i]) //剪枝，如果c已经比当前质数小了，没必要继续遍历质数数组了
      {
        break;
      }
      while (!(c % prime[i])) //c能模尽一个质数
      {
        chaFen[r + 1][i] -= b; //乘进来的数可以被分解成一些100内质数，而我[l:r]区间内每个数可被分解成一些100内质数，这样
        chaFen[l][i] += b;     //我乘这些数就可以看作在[l:r]区间内每个数被分解成的质数中的一些的幂次中“加”，区间加可用差分实现单点修改
        c /= prime[i];         //除以这个质数，再看这个c是否有其他的质因数
      }
    }
  }
  fih(); //把差分数组中的质数的幂
  return 0;
}
=======
#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int INF = 0x3f3f3f, maxn = 100010;
const LL MOD = 1e9 + 7, LLF = 1e18 + 3; //LLF要开大一点，MOD为结果要取的模
const LL prime[30] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
int n, m;              //n：数列长度  m:操作次数  prime：100以内所有质数
LL l, r, c, b, pw[30]; //pw[i]:组成最大公因数的第i个质数的幂次
LL chaFen[maxn][30];   //二维差分数组，对[1,100]质数均设置一维差分数组(存幂次，才能用差分数组，变乘法为加法)
//这个差分数组实际上初始化为n个数可分解成的质因数的幂次，后续通过乘进来的数c实现单点修改
LL qPow(LL base, LL pow) //快速幂
{
  LL res = 1;
  while (pow > 0)
  {
    if (pow & 1) //奇数额外乘上a
    {
      res = res * base % MOD;
    }
    pow >>= 1; //每次将pow/2，复杂度log级
    base = (base * base) % MOD;
  }
  return res % MOD;
}

void fih() //求最大公约数的质数组成
{
  LL temp = 0, res = 1;
  for (int i = 1; i <= 25; ++i) //遍历pw[]
  {
    temp = 0;
    pw[i] = LLF;
    for (int j = 1; j <= n; ++j) //遍历n个元素的数列
    {
      temp += chaFen[j][i];
      pw[i] = min(pw[i], temp); //pw[i]存储：对于该质数（第i个质数），n个元素的数列中每个元素的质数组成中该质数的幂次的最小值
    }                           //也即n个元素对于该质数的最大公因数
  }
  for (int i = 1; i <= 25; ++i)
  {
    res = res * qPow(prime[i], pw[i]) % MOD; //底数是各个质数，指数是pw[i]中存的第i个质数的最小幂次
  }
  cout << res << '\n';
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 1; i <= m; ++i)
  {
    cin >> l >> r >> c >> b;
    for (int i = 1; i <= 25; ++i)
    {
      if (c < prime[i]) //剪枝，如果c已经比当前质数小了，没必要继续遍历质数数组了
      {
        break;
      }
      while (!(c % prime[i])) //c能模尽一个质数
      {
        chaFen[r + 1][i] -= b; //乘进来的数可以被分解成一些100内质数，而我[l:r]区间内每个数可被分解成一些100内质数，这样
        chaFen[l][i] += b;     //我乘这些数就可以看作在[l:r]区间内每个数被分解成的质数中的一些的幂次中“加”，区间加可用差分实现单点修改
        c /= prime[i];         //除以这个质数，再看这个c是否有其他的质因数
      }
    }
  }
  fih(); //把差分数组中的质数的幂
  return 0;
}
>>>>>>> 094bdc4d9ccc8ffc29ad708c5b504d76fd33efcd
