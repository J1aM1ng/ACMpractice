#include <bits/stdc++.h>
using namespace std;
long long n, maxC = 0, cont = 0;
string s;
int main()
{
  cin >> n >> s;
  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
      {
        cont = 1;
      }
      continue;
    }
    //else
    if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
    {
      cont++;
    }
    else
    {
      maxC = max(maxC, cont);
      cont = 0;
    }
  }
  cout << maxC;
  return 0;
}