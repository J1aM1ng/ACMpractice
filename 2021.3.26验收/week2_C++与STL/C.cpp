#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> storeArray;
  for (int i = 0; i < m; ++i)
  {
    pair<int, int> temp;
    cin >> temp.first >> temp.second; //first:数字 second:所在的桶
    storeArray.push_back(make_pair(temp.first, temp.second));
  }
  vector<vector<int>> binArray(n); //桶
  for (int i = 0; i < m; ++i)
  {
    binArray[storeArray[i].second - 1].push_back(storeArray[i].first);
  } //推入
  for (int i = 0; i < n; ++i)
  {
    sort(binArray[i].begin(), binArray[i].end());
  } //排序（每个桶 升序）
  for (int i = 0; i < n; ++i)
  {
    for (int j = 0; j < binArray[i].size(); ++j)
    {
      if (j == binArray[i].size() - 1)
        cout << binArray[i][j];
      else
        cout << binArray[i][j] << " ";
    }
    cout << endl;
  } //输出
  return 0;
}