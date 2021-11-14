#include <bits/stdc++.h>
using namespace std;
string s; //石块序列，长度为n的字符串
const int INF = 0x3f3f3f;
unordered_map<char, int> alp; //字母表，char为字母，int为该字母出现的次数
unordered_set<char> fih;      //finish 该段中出现过的字母，即出现次数>=1的字母
vector<pair<int, int>> check; //待检查的区间（int int分别为区间左右端点）
unordered_map<int, int> minR; //以左端点开始，满足至少含有26字母的最小右端点(从左端点x到最小右端点minR[x]为含有26字母的最小区间)
int n, m;                     //n块巨石，m条询问
int main(void)
{
  ios::sync_with_stdio(false);
  int tl = 0, tr = 0; //每个询问中的区间左右端点，表示的是序列号（索引+1）
  cin >> n >> s >> m;
  for (int i = 1; i <= m; i++)
  {
    cin >> tl >> tr;
    check.emplace_back(tl - 1, tr - 1);
  }
  int l = 0, r = 0; //尺取 双指针
  ++alp[s[0]];
  fih.insert(s[0]);
  while (true)
  {
    if (r < l) //退出循环的条件，尺取结束
    {
      break;
    }
    if (fih.size() == 26) //找到了一个含有26字母的区间
    {
      minR[l] = r; //从左端点l到最小右端点r=minR[l]为含有26字母的最小区间
    }
    if ((r < n - 1) && (fih.size() < 26)) //尺取条件不满足，右端点右移
    {
      ++r;              //右端点右移
      ++alp[s[r]];      //对应字母个数+1
      fih.insert(s[r]); //当前区间内，r对应元素存在
    }
    else //尺取条件满足fih.size() >= 26,左端点右移
    {
      if (alp[s[l]] > 0) //由于左端点右移带来的数目损失
      {
        --alp[s[l]];
      }
      if (alp[s[l]] <= 0) //若损失致使一个字母一个也没有了，则移除该键值对
      {
        fih.erase(s[l]);
      }
      ++l; //左端点右移
    }
  }
  int L = 0, R = 0;
  for (vector<pair<int, int>>::iterator it = check.begin(); it != check.end(); ++it)
  {                 //查询各区间
    L = it->first;  //区间左端点
    R = it->second; //区间右端点
    while (minR[L] == 0 && L <= R)
    {
      ++L; //该处不符合最小区间，右移左端点，直到符合最小区间或是L>R
    }
    if (L > R || minR[L] > R || minR[L] == 0) //并未涵盖所有的英文字母
    {
      cout << "NO" << '\n';
    }
    else //涵盖了所有的英文字母
    {
      cout << "YES" << '\n';
    }
  }
  return 0;
}