#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
  cin >> n;
  vector<int> price1(n, 0), price2(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> price1[i];
  }
  for (int i = 0; i < n; i++)
  {
    if (i == 0)
    {
      price2[0] = floor((price1[0] + price1[1]) / 2);
    }
    else if (i == n - 1)
    {
      price2[n - 1] = floor((price1[n - 1] + price1[n - 2]) / 2);
    }
    else
    {
      price2[i] = floor((price1[i] + price1[i - 1] + price1[i + 1]) / 3);
    }
  }
  for (int i = 0; i < n; i++)
  {
    cout << price2[i] << " ";
  }
  return 0;
}