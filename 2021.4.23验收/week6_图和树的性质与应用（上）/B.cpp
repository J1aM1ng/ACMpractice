#include <bits/stdc++.h>
using namespace std;
long long n, maxC = 0, cont = 0;
string s, ans;
bool isVowel(char c)
{
  if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
  {
    return true;
  }
  return false;
}
int main()
{
  cin >> n >> s;
  for (int i = 0; i < n; i++)
  {
    if (i == 0 || (!isVowel(s[i - 1])) || (!isVowel(s[i])))
    {
      ans += s[i];
    }
  }
  cout << ans;
  return 0;
}