#include <bits/stdc++.h> //中点扩散算法，枚举中点，O（n2）
using namespace std;
bool isVowel(char x)
{
  return x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u';
}
bool judge(char x, char y)
{
  if (isVowel(x) && isVowel(y) || x == y)
    return true;
  else
    return false;
}
int main()
{
  ios::sync_with_stdio(false);
  int n; //字符串长度
  string s;
  cin >> n >> s;
  int ans = 0;                         //最长回文子串的长度
  for (int i = 0; i < s.length(); i++) //枚举回文子串中点，奇数长度回文子串的一个中点和偶数长度回文子串的两个中点
  {
    int l = i - 1, r = i + 1;
    while (l >= 0 && r < s.length() && judge(s[l], s[r])) //判断奇数长度的回文子串
    {
      l--;
      r++;
    }
    ans = max(ans, r - l - 1);
    l = i;
    r = i + 1;
    while (l >= 0 && r < s.length() && judge(s[l], s[r])) //判断偶数长度的回文子串
    {
      l--;
      r++;
    }
    ans = max(ans, r - l - 1);
  }
  cout << ans;
  return 0;
}