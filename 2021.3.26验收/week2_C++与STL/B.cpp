<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> inputArray;
  for (int i = 0; i < n; ++i)
  {
    int temp;
    cin >> temp;
    inputArray.push_back(temp);
  }
  vector<pair<int, int>> tempArray; //first:读者编号 second:已出现次数
  vector<int> resultArray(n);
  for (int i = 0; i < n; ++i)
  {
    if (i == 0)
      tempArray.push_back(make_pair(inputArray[0], 0));
    else
    {
      for (int j = 0; j < tempArray.size(); ++j)
      {
        if (inputArray[i] == tempArray[j].first)
          break;
        if ((j == tempArray.size() - 1) && (inputArray[i] != tempArray[j].first))
        {
          tempArray.push_back(make_pair(inputArray[i], 0));
        }
      }
    }
  }                                           //将记录中有的（特异的）读者编号存入tempArray
  for (int i = 0; i < inputArray.size(); ++i) //遍历，使得tempArray.second增加，且每次值在resultArray中反映
  {
    for (int j = 0; j < tempArray.size(); ++j)
    {
      if (inputArray[i] == tempArray[j].first)
      {
        ++tempArray[j].second;
        resultArray[i] = tempArray[j].second;
        break;
      }
    }
  }
  for (int i = 0; i < n; ++i)
  {
    if (i != n - 1)
      cout << resultArray[i] << " ";
    else
      cout << resultArray[i];
  }
  return 0;
=======
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int> inputArray;
  for (int i = 0; i < n; ++i)
  {
    int temp;
    cin >> temp;
    inputArray.push_back(temp);
  }
  vector<pair<int, int>> tempArray; //first:读者编号 second:已出现次数
  vector<int> resultArray(n);
  for (int i = 0; i < n; ++i)
  {
    if (i == 0)
      tempArray.push_back(make_pair(inputArray[0], 0));
    else
    {
      for (int j = 0; j < tempArray.size(); ++j)
      {
        if (inputArray[i] == tempArray[j].first)
          break;
        if ((j == tempArray.size() - 1) && (inputArray[i] != tempArray[j].first))
        {
          tempArray.push_back(make_pair(inputArray[i], 0));
        }
      }
    }
  }                                           //将记录中有的（特异的）读者编号存入tempArray
  for (int i = 0; i < inputArray.size(); ++i) //遍历，使得tempArray.second增加，且每次值在resultArray中反映
  {
    for (int j = 0; j < tempArray.size(); ++j)
    {
      if (inputArray[i] == tempArray[j].first)
      {
        ++tempArray[j].second;
        resultArray[i] = tempArray[j].second;
        break;
      }
    }
  }
  for (int i = 0; i < n; ++i)
  {
    if (i != n - 1)
      cout << resultArray[i] << " ";
    else
      cout << resultArray[i];
  }
  return 0;
>>>>>>> 094bdc4d9ccc8ffc29ad708c5b504d76fd33efcd
}