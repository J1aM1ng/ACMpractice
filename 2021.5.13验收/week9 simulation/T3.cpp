#include <bits/stdc++.h>
using namespace std;

int INF = 100000000;
int MIN = -32768;
int MF = -99999999;
int MAX = 32767;
int df[65546];
const int abstract = 32769;
set<int> singleV;

struct rg
{
  int f;
  int t;
  rg(int f, int t) : f(f), t(t) {}
};
vector<rg> rv;

void Print()
{
  int cntr = 0;
  for (rg rg : rv)
  {
    ++cntr;
    if (rg.f == MIN && rg.t == MAX)
    {
      cout << "true" << '\n';
      return;
    }
    if (rg.f == MF && rg.t == MF)
    {
      cout << "false" << '\n';
      return;
    }
    if (rg.f == MIN && rg.t != MIN)
    {
      cout << "x <= ";
      cout << rg.t;
    }
    else if (rg.t == MAX && rg.f != MAX)
    {
      cout << "x >= ";
      cout << rg.f;
    }
    else
    {
      cout << "x >= ";
      cout << rg.f;
      cout << " && ";
      cout << "x <= ";
      cout << rg.t;
    }
    if (cntr < rv.size())
      cout << " ||" << '\n';
    else
      cout << '\n';
  }
}

void Get()
{
  int l = 0, r = 0;
  int curVal = 0;
  bool inrg = false;
  bool used = false;
  for (int i = 0; i <= 65538; i++)
  {
    curVal += df[i];
    if (curVal > 0)
    {
      if (!inrg)
        l = i;
      inrg = true;
      used = true;
    }
    else
    {
      if (inrg)
      {
        r = i;
        if (i <= 65537)
          rv.emplace_back(rg(l - abstract, r - abstract - 1));
      }
      else
      {
        if (singleV.count(i) && i <= 65537 && i >= 1)
        {
          rv.emplace_back(rg(i - abstract, i - abstract));
        }
      }
      inrg = false;
    }
  }
  if (!used)
  {
    rv.emplace_back(rg(MF, MF));
  }
}

void dfer(const rg &rg)
{
  int l = rg.f + abstract;
  int r = rg.t + abstract;
  if (l < 1)
  {
    l = 1;
  }
  if (r > 65536)
  {
    r = 65536;
  }
  if (l == r)
  {
    singleV.emplace(l);
  }
  df[l] += 1;
  df[r + 1] -= 1;
}

int str2_int(string str)
{
  int pow = 1;
  int res = 0;
  for (auto itr = str.rbegin(); itr != str.rend(); itr++)
  {
    if (*itr >= '0' && *itr <= '9')
    {
      res += (*itr - '0') * pow;
      pow *= 10;
    }
    if (*itr == '-')
    {
      res = -res;
    }
  }
  return res;
}

pair<bool, int> str2_rg(string str)
{
  pair<bool, int> res;
  for (int i = 1; i < str.size(); i++)
  {
    if (str[i] == '>')
      res.first = false;
    if (str[i] == '<')
      res.first = true;
    if (str[i] >= '0' && str[i] <= '9' || str[i] == '-')
    {
      res.second = str2_int(str.substr(i));
      break;
    }
  }
  return res;
}

void Input()
{
  string curInput;
  while (true)
  {
    bool last = true;
    getline(cin, curInput);
    if (*curInput.rbegin() == '|')
      last = false;
    int lastVal = INF;
    for (int i = 0; i < curInput.size(); i++)
    {
      if (curInput[i] == 'x')
      {
        for (int j = i + 5; j < curInput.size(); j++)
        {
          if ((j == curInput.size() - 3 && !last) || (last && j == curInput.size() - 1))
          {
            pair<bool, int> p = str2_rg(curInput.substr(i, j - i + 1));
            if (lastVal != INF)
            {
              dfer(rg(lastVal, p.second));
            }
            else
              p.first ? dfer(rg(MIN, p.second)) : dfer(rg(p.second, MAX));
            break;
          }
          else if (curInput[j] == '&')
          {
            pair<bool, int> p = str2_rg(curInput.substr(i, j - i));
            lastVal = p.second;
            i = j;
            break;
          }
        }
      }
    }
    if (last)
    {
      break;
    }
  }
}

int main()
{
  ios::sync_with_stdio(false);
  Input();
  Get();
  Print();
  return 0;
}