#include <bits/stdc++.h>
using namespace std;
int Num;
string result;
class ele
{
  unordered_map<string, int> record; // 记录元素个数
  vector<int> stk;                   // 记录嵌套括号外的数字
  bool islower(char &c)
  {
    return c >= 'a' && c <= 'z';
  }
  bool isdigit(char &c)
  {
    return c >= '0' && c <= '9';
  }

public:
  ele(vector<string> words)
  {
    this->stk.emplace_back(1);
    int tms = 1, in = 0, totalNum = 0;
    for (auto word : words)
    {
      for (int i = 0; i < word.size() && isdigit(word[i]); ++i)
      { // 获取化学式的系数
        totalNum = totalNum * 10 + word[i] - '0';
      }
      if (totalNum == 0) // 没有系数则默认为1
        totalNum = 1;

      for (int i = word.size() - 1; i >= 0; --i)
      {
        char cur = word[i];
        if (isdigit(cur))
        {
          // tms = cur - '0'; // 之前的写法缺少对括号外多位数字的判断，经评论区兄弟提醒，现做订正
          tms = cur - '0';
          int tmpC = 1;
          while (i > 0 && isdigit(word[i - 1]))
          {
            tms += (word[i - 1] - '0') * pow(10, tmpC);
            tmpC++;
            --i;
          }
          if (word[i - 1] == ')')
          { // 出现的数字属于括号内的元素
            // outside = tms;

            if (in == 0)
            { // 如果还没有嵌套,目前仅出现了单层括号
              stk.pop_back();
            }
            stk.emplace_back(tms);

            tms = 1;
          }
        }
        else if (cur == ')')
        {
          in++;
        }
        else if (cur == '(')
        {
          in--;

          stk.pop_back();
          if (in == 0)
          {
            stk.emplace_back(1);
          }
        }
        else if (islower(cur))
        {
          string tmpEle;
          tmpEle.push_back(word[i - 1]);
          tmpEle.push_back(cur);

          int outside = 1;
          for (auto n : stk)
          {
            outside *= n;
          }
          record[tmpEle] += tms * outside * totalNum;
          tms = 1;
          --i;
        }
        else
        { // 单个的元素
          string tmpEle;
          tmpEle.push_back(cur);
          int outside = 1;
          for (auto n : stk)
          {
            outside *= n;
          }
          record[tmpEle] += tms * outside * totalNum;
          tms = 1;
        }
      }

      totalNum = 0; // 记得清零，对下一个化学式判断
      tms = 1;
    }
  }
  int operator[](string elem)
  {
    return record[elem];
  }
  bool operator==(ele &rightElement)
  {
    for (auto &r : record)
    {
      if (r.second != rightElement[r.first])
        return false;
    }
    return true;
  }
};

bool isBal(string inp)
{
  vector<string> leftwords;
  vector<string> rightwords;
  stringstream ss(inp);
  vector<string> line;
  string tmp;
  while (getline(ss, tmp, '='))
  { // 把整个表达式分为左右两个部分
    line.emplace_back(tmp);
  }
  ss = stringstream(line[0]);
  while (getline(ss, tmp, '+'))
  {
    leftwords.emplace_back(tmp);
  }
  ss = stringstream(line[1]);
  while (getline(ss, tmp, '+'))
  {
    rightwords.emplace_back(tmp);
  }
  ele left(leftwords);
  ele right(rightwords);
  return left == right;
}

int main()
{
  ios::sync_with_stdio(false);
  cin >> Num;
  for (int i = 0; i < Num; ++i)
  {
    string inp;
    cin >> inp;
    bool res = isBal(inp);
    result.push_back(res ? 'Y' : 'N');
  }
  for (auto c : result)
    cout << c << '\n';
  return 0;
}