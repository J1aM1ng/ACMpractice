#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  string colorStr;
  cin >> colorStr;
  int colorArray[3];
  for (int i = 0; i < 3; ++i)
  {
    colorArray[i] = 0;
  }
  for (int i = 0; i < colorStr.length(); ++i)
  {
    if (colorStr[i] == 'R')
      ++colorArray[0];
    if (colorStr[i] == 'G')
      ++colorArray[1];
    if (colorStr[i] == 'B')
      ++colorArray[2];
  }
  int minNum = min(min(colorArray[0], colorArray[1]), colorArray[2]); //木桶原理，能拼成多少像素取决于RGB中最少的小灯
  cout << minNum;
  return 0;
}