<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
string s;
const int INF = 0x3f3f3f;
unordered_map<char, int> alp; //字母表，char为字母，int为该字母出现的次数
unordered_set<char> fih;      //finish 该段中出现过的字母，即出现次数>=1的字母
vector<pair<int, int>> check;
unordered_map<int, int> minR; //以左端点开始，满足至少含有26字母的最小右端点(从左端点x到最小右端点minR[x]为含有26字母的最小区间)
int n, minL = INF;            //n：字符串长度   minL:区间长度最小值
int main(void)
{
  ios::sync_with_stdio(false);
  cin >> n >> s;
  int l = 0, r = 0; //*******尺取********
  ++alp[s[0]];      //第0个元素对应的字母的数目+1
  fih.insert(s[0]); //塞进已完成的字母中
  while (true)
  {
    if (r < l) //退出循环的条件，尺取结束
    {
      break;
    }
    if (fih.size() == 26) //找到了一个含有26字母的区间
    {
      minR[l] = r;                 //从左端点l到最小右端点r=minR[l]为含有26字母的最小区间
      minL = min(minL, r - l + 1); //更新区间长度最小值
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
  cout << minL; //尺取得到的最优区间长度（最短）
  return 0;
=======
#include <bits/stdc++.h>
using namespace std;
string s;
const int INF = 0x3f3f3f;
unordered_map<char, int> alp; //字母表，char为字母，int为该字母出现的次数
unordered_set<char> fih;      //finish 该段中出现过的字母，即出现次数>=1的字母
vector<pair<int, int>> check;
unordered_map<int, int> minR; //以左端点开始，满足至少含有26字母的最小右端点(从左端点x到最小右端点minR[x]为含有26字母的最小区间)
int n, minL = INF;            //n：字符串长度   minL:区间长度最小值
int main(void)
{
  ios::sync_with_stdio(false);
  cin >> n >> s;
  int l = 0, r = 0; //*******尺取********
  ++alp[s[0]];      //第0个元素对应的字母的数目+1
  fih.insert(s[0]); //塞进已完成的字母中
  while (true)
  {
    if (r < l) //退出循环的条件，尺取结束
    {
      break;
    }
    if (fih.size() == 26) //找到了一个含有26字母的区间
    {
      minR[l] = r;                 //从左端点l到最小右端点r=minR[l]为含有26字母的最小区间
      minL = min(minL, r - l + 1); //更新区间长度最小值
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
  cout << minL; //尺取得到的最优区间长度（最短）
  return 0;
>>>>>>> 094bdc4d9ccc8ffc29ad708c5b504d76fd33efcd
}