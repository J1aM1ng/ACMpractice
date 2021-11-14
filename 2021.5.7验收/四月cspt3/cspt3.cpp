#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f, maxn = 1e5 + 10;
typedef long long ll;
struct group
{
public:
  group()
  {
    topIter = -1;
    chatWindowSize = 0;
    oc = 1;
    flag = false;
  }
  bool flag = false; //是否有置顶
  int oc = 1;        //操作数
  ll topIter = 0;
  vector<pair<ll, ll>> chatWindow;
  int chatWindowSize = 0;
  void Add(ll u)
  {
    for (int i = 0; i < chatWindowSize; ++i)
    {
      if (chatWindow[i].first == u)
      {
        printf("OpId #%d: same likeness.\n", oc++);
        return;
      }
    }
    chatWindow.emplace_back(u, 0);
    ++chatWindowSize;
    printf("OpId #%d: success.\n", oc++);
  }
  void toHead(int x)
  {
    pair<ll, ll> temp = chatWindow[x];
    chatWindow.erase(chatWindow.begin() + x);
    chatWindow.insert(chatWindow.begin(), temp);
  }
  void Close(ll u)
  {
    for (int i = 0; i < chatWindowSize; ++i)
    {
      if (chatWindow[i].first == u)
      {
        ll c = chatWindow[i].second;
        chatWindow.erase(chatWindow.begin() + i);
        --chatWindowSize;
        if (topIter == u)
        {
          flag = 0;
        }
        printf("OpId #%d: close %lld with %lld.\n", oc++, u, c);
        return;
      }
    }
    printf("OpId #%d: invalid likeness.\n", oc++);
  }
  void Chat(ll w)
  {
    if (chatWindowSize == 0)
    {
      printf("OpId #%d: empty.\n", oc++);
      return;
    }
    ll judge;
    if (flag)
    {
      judge = topIter;
    }
    else
    {
      judge = chatWindow[0].first;
    }
    for (int i = 0; i < chatWindowSize; i++)
    {
      if (judge == chatWindow[i].first)
      {
        chatWindow[i].second += w;
        break;
      }
    }
    printf("OpId #%d: success.\n", oc++);
  }
  void Rotate(ll x)
  {
    if (x < 1 || x > chatWindowSize)
    {
      printf("OpId #%d: out of range.\n", oc++);
      return;
    }
    toHead(x - 1);
    printf("OpId #%d: success.\n", oc++);
  }

  void Prior()
  {
    if (chatWindowSize == 0)
    {
      printf("OpId #%d: empty.\n", oc++);
      return;
    }
    ll judge = 0;
    for (int i = 1; i < chatWindowSize; i++)
    {
      if (chatWindow[i].first > chatWindow[judge].first)
      {
        judge = i;
      }
    }
    toHead(judge);
    printf("OpId #%d: success.\n", oc++);
  }
  void Choose(ll u)
  {
    bool tempFlag = 0;
    ll judge;
    for (int i = 0; i < chatWindowSize; i++)
    {
      if (chatWindow[i].first == u)
      {
        tempFlag = 1;
        judge = i;
        break;
      }
    }
    if (!tempFlag)
    {
      printf("OpId #%d: invalid likeness.\n", oc++);
      return;
    }
    toHead(judge);
    printf("OpId #%d: success.\n", oc++);
  }

  void Top(ll u)
  {
    bool tempFlag = 0;

    for (int i = 0; i < chatWindowSize; ++i)
    {
      if (chatWindow[i].first == u)
      {
        tempFlag = 1;
        break;
      }
    }
    if (!tempFlag)
    {
      printf("OpId #%d: invalid likeness.\n", oc++);
      return;
    }
    flag = 1;
    topIter = u;
    printf("OpId #%d: success.\n", oc++);
  }

  void Untop()
  {
    if (!flag)
    {
      printf("OpId #%d: no such person.\n", oc++);
      return;
    }
    flag = 0;
    printf("OpId #%d: success.\n", oc++);
  }
  void sayBye()
  {
    if (flag)
    {
      int judge;
      for (int i = 0; i < chatWindowSize; i++)
      {
        if (chatWindow[i].first == topIter)
        {
          judge = i;
          break;
        }
      }
      if (chatWindow[judge].second > 0)
      {
        printf("OpId #%d: Bye %lld: %lld.\n", oc++, chatWindow[judge].first, chatWindow[judge].second);
      }
      --chatWindowSize;
      chatWindow.erase(chatWindow.begin() + judge);
    }
    for (int i = 0; i < chatWindowSize; ++i)
    {
      if (chatWindow[i].second > 0)
        printf("OpId #%d: Bye %lld: %lld.\n", oc++, chatWindow[i].first, chatWindow[i].second);
    }
  }
};
int main(int argc, char *argv[])
{
  ios::sync_with_stdio(false);
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i) //O(Nn)
  {
    group tmp;
    int n; //每组数据操作数
    cin >> n;
    for (int j = 0; j < n; ++j)
    {
      string tempStr;
      ll u;
      cin >> tempStr;
      if (tempStr != "Prior" && tempStr != "Untop")
      {
        cin >> u;
      }

      if (tempStr == "Add")
      {
        tmp.Add(u);
      }
      else if (tempStr == "Close")
      {
        tmp.Close(u);
      }
      else if (tempStr == "Chat")
      {
        tmp.Chat(u);
      }
      else if (tempStr == "Rotate")
      {
        tmp.Rotate(u);
      }
      else if (tempStr == "Prior")
      {
        tmp.Prior();
      }
      else if (tempStr == "Choose")
      {
        tmp.Choose(u);
      }
      else if (tempStr == "Top")
      {
        tmp.Top(u);
      }
      else if (tempStr == "Untop")
      {
        tmp.Untop();
      }
    }
    tmp.sayBye();
  }
  return 0;
}