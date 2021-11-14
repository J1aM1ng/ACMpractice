#include <bits/stdc++.h>
using namespace std;
vector<string> resultArray;
map<string, int> wordArray;       //单词本
void operate(int op, string temp) //操作op==1 op==2
{
  if (op == 1)
  {
    if (wordArray.size() == 0)
    {
      resultArray.push_back("write");
      wordArray.insert(pair<string, int>(temp, 1)); //插入单词
    }
    else
    {
      map<string, int>::iterator iter; //有序，省去排序时间，仅first有用
      iter = wordArray.find(temp);
      if (iter != wordArray.end())
      {
        resultArray.push_back("found");
      }
      else
      {
        resultArray.push_back("write");
        wordArray.insert(pair<string, int>(temp, 1));
      }
    }
  }
  else //op==2
  {
    if (wordArray.size() == 0)
    {
      resultArray.push_back("not found");
    }
    else
    {
      map<string, int>::iterator iter;
      iter = wordArray.find(temp);
      if (iter != wordArray.end())
      {
        resultArray.push_back("erased");
        wordArray.erase(temp); //删除单词
      }
      else
      {
        resultArray.push_back("not found");
      }
    }
  }
}
void operate() //操作op==3
{
  string temp = "";
  if (wordArray.size())
  {
    map<string, int>::iterator iter;
    for (iter = wordArray.begin(); iter != wordArray.end(); ++iter)
    {
      if (iter == (--wordArray.end()))
        temp += iter->first;
      else
        temp = temp + iter->first + " "; //拼接字符串，通读为一个完整字符串（包括空格），推进输出流
    }
    resultArray.push_back(temp);
  }
}
int main()
{
  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i)
  {
    int op;
    scanf("%d", &op);
    if ((op == 1) || (op == 2))
    {
      string temp;
      cin >> temp;
      operate(op, temp);
    }
    else //op==3
    {
      operate();
    }
  }

  for (int i = 0; i < resultArray.size(); ++i)
  {
    if (i != resultArray.size() - 1)
      cout << resultArray[i] << '\n';
    else
      cout << resultArray[i];
  } //输出

  return 0;
}