<<<<<<< HEAD
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, k;
  cin >> n >> k;
  int winner = -1;         //胜者
  int judge = 1;           //（每个人对应的）报数
  int size = n;            //队伍现长
  vector<int> kidArray(n); //小朋友的编号
  for (int i = 0; i < n; ++i)
  {
    kidArray[i] = 1; //1代表还在队中，-1表示已出队
  }
  for (int i = 0; size > 1; ++i)
  {
    if (i >= 0 && i < n)
    {
      if (kidArray[i] == 1) //在队中
      {
        if ((judge % k == 0) || (judge % 10 == k))
        {
          kidArray[i] = -1; //出队
          --size;
        }
        ++judge;
      }
    }
    else if (i >= n) //重置i
    {
      i = -1;
    }
  }
  for (int i = 0; i < n; ++i)
  {
    if (kidArray[i] == 1)
    {
      winner = i + 1;
    }
  }
  cout << winner;
  return 0;
=======
#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n, k;
  cin >> n >> k;
  int winner = -1;         //胜者
  int judge = 1;           //（每个人对应的）报数
  int size = n;            //队伍现长
  vector<int> kidArray(n); //小朋友的编号
  for (int i = 0; i < n; ++i)
  {
    kidArray[i] = 1; //1代表还在队中，-1表示已出队
  }
  for (int i = 0; size > 1; ++i)
  {
    if (i >= 0 && i < n)
    {
      if (kidArray[i] == 1) //在队中
      {
        if ((judge % k == 0) || (judge % 10 == k))
        {
          kidArray[i] = -1; //出队
          --size;
        }
        ++judge;
      }
    }
    else if (i >= n) //重置i
    {
      i = -1;
    }
  }
  for (int i = 0; i < n; ++i)
  {
    if (kidArray[i] == 1)
    {
      winner = i + 1;
    }
  }
  cout << winner;
  return 0;
>>>>>>> 094bdc4d9ccc8ffc29ad708c5b504d76fd33efcd
}