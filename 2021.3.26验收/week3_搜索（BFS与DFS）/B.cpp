#include <bits/stdc++.h>
using namespace std;
int main()
{
  vector<int> operaArray;
  int tempNum;
  while (1)
  {
    cin >> tempNum;
    if (tempNum == 0)
      break;
    operaArray.push_back(tempNum); //输入
  }
  int score = 0, add = 2; //score:总分  add:跳到中心的递增分数
  for (int i = 0; i < operaArray.size(); ++i)
  {
    if (operaArray[i] == 1)
    {
      ++score;
      add = 2; //重置add
    }
    else if (operaArray[i] == 0) //游戏结束
    {
      break;
    }
    else if (operaArray[i] == 2)
    {
      if (i == 0)
        score = 2;
      else if (operaArray[i - 1] == 1) //+2
        score += 2;
      else if (operaArray[i - 1] == 2) //开始递增
      {
        add += 2;
        score += add;
      }
    }
  }
  cout << score;
  return 0;
}