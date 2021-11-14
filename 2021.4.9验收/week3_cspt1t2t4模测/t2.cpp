#include <bits/stdc++.h>
using namespace std;
int main()
{
  string psw;
  int pow = 0; //密码强度
  cin >> psw;
  int judge = -1; //judge取值123分别代表数字，小写字母和大写字母
  if (psw.length() < 6)
    pow = 0; //如果一个密码的长度小于 6，则这个密码的强度为 0
  else
  {
    for (int i = 0; i < psw.length(); ++i)
    {
      if (isdigit(psw[i]))
      {
        if (judge != 1)
        {
          ++pow; //上个字符不是数字
        }
        judge = 1;
      }
      if (islower(psw[i]))
      {
        if (judge != 2)
        {
          ++pow; //上个字符不是小写字母
        }
        judge = 2;
      }
      if (isupper(psw[i]))
      {
        if (judge != 3)
        {
          ++pow; //上个字符不是大写字母
        }
        judge = 3;
      }
    }
  }
  cout << pow; //n个字段有n-1个空隙，密码强度为n，而第一个字符时其judge=-1，必定使pow++，故pow最终等于n
  return 0;
}