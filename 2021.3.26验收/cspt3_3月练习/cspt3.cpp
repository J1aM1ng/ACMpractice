#include <bits/stdc++.h>
using namespace std;
int type[9]; //9种可能对应的方案数
class card
{
public:
  int a; //大小
  int b; //花色
  card(int a0, int b0)
  {
    a = a0;
    b = b0;
  }
  card()
  {
    a = 0;
    b = 0;
  }
};
bool isSituation4(card c1, card c2, card c3, card c4, card c5) //同花
{
  if ((c1.b == c2.b) && (c2.b == c3.b) && (c3.b == c4.b) && (c4.b == c5.b))
    return true;
  else
    return false;
}
bool isSituation5(card c1, card c2, card c3, card c4, card c5) //顺子
{
  vector<int> storeArray;
  storeArray.push_back(c1.a);
  storeArray.push_back(c2.a);
  storeArray.push_back(c3.a);
  storeArray.push_back(c4.a);
  storeArray.push_back(c5.a);
  sort(storeArray.begin(), storeArray.end());
  if ((storeArray[1] - storeArray[0] == 1) && (storeArray[2] - storeArray[1] == 1) && (storeArray[3] - storeArray[2] == 1) && (storeArray[4] - storeArray[3] == 1))
    return true;
  else
    return false;
}
bool isSituation1(card c1, card c2, card c3, card c4, card c5)
{
  if (isSituation4(c1, c2, c3, c4, c5) && isSituation5(c1, c2, c3, c4, c5))
    return true;
  else
    return false;
}
bool isSituation2(card c1, card c2, card c3, card c4, card c5)
{
  vector<int> storeArray;
  storeArray.push_back(c1.a);
  storeArray.push_back(c2.a);
  storeArray.push_back(c3.a);
  storeArray.push_back(c4.a);
  storeArray.push_back(c5.a);
  sort(storeArray.begin(), storeArray.end());
  if ((storeArray[0] == storeArray[1] && storeArray[1] == storeArray[2] && storeArray[2] == storeArray[3]) || (storeArray[1] == storeArray[2] && storeArray[2] == storeArray[3] && storeArray[3] == storeArray[4]))
    return true;
  else
    return false;
}
bool isSituation3(card c1, card c2, card c3, card c4, card c5)
{
  vector<int> storeArray;
  storeArray.push_back(c1.a);
  storeArray.push_back(c2.a);
  storeArray.push_back(c3.a);
  storeArray.push_back(c4.a);
  storeArray.push_back(c5.a);
  sort(storeArray.begin(), storeArray.end());
  if ((storeArray[0] == storeArray[1] && storeArray[2] == storeArray[3] && storeArray[3] == storeArray[4]) || (storeArray[0] == storeArray[1] && storeArray[1] == storeArray[2] && storeArray[3] == storeArray[4]))
    return true;
  else
    return false;
}
bool isSituation6(card c1, card c2, card c3, card c4, card c5)
{
  vector<int> storeArray;
  storeArray.push_back(c1.a);
  storeArray.push_back(c2.a);
  storeArray.push_back(c3.a);
  storeArray.push_back(c4.a);
  storeArray.push_back(c5.a);
  sort(storeArray.begin(), storeArray.end());
  if ((storeArray[0] == storeArray[1] && storeArray[1] == storeArray[2]) || (storeArray[1] == storeArray[2] && storeArray[2] == storeArray[3]) || (storeArray[2] == storeArray[3] && storeArray[3] == storeArray[4]))
    return true;
  else
    return false;
}
bool isSituation7(card c1, card c2, card c3, card c4, card c5)
{
  vector<int> storeArray;
  storeArray.push_back(c1.a);
  storeArray.push_back(c2.a);
  storeArray.push_back(c3.a);
  storeArray.push_back(c4.a);
  storeArray.push_back(c5.a);
  sort(storeArray.begin(), storeArray.end()); //todo(下面)
  if ((storeArray[0] == storeArray[1] && storeArray[2] == storeArray[3]) || (storeArray[0] == storeArray[1] && storeArray[3] == storeArray[4]) || (storeArray[1] == storeArray[2] && storeArray[3] == storeArray[4]))
    return true;
  else
    return false;
}
bool isSituation8(card c1, card c2, card c3, card c4, card c5)
{
  vector<int> storeArray;
  storeArray.push_back(c1.a);
  storeArray.push_back(c2.a);
  storeArray.push_back(c3.a);
  storeArray.push_back(c4.a);
  storeArray.push_back(c5.a);
  sort(storeArray.begin(), storeArray.end());
  if ((storeArray[0] == storeArray[1]) || (storeArray[1] == storeArray[2]) || (storeArray[2] == storeArray[3]) || (storeArray[3] == storeArray[4]))
    return true;
  else
    return false;
}
void combine(vector<card> cardArray, card tempArray[], int n, int m, card c1, card c2) //组合，C(N,M) tempArray:组合出的三张牌 cardArray:卡池
{
  if (m > 0) //dfs
  {
    for (int i = n; i >= m; i--)
    {
      tempArray[m - 1] = cardArray[i - 1];
      combine(cardArray, tempArray, i - 1, m - 1, c1, c2); //从卡池中选一张放入tempArray，再递归组合剩下的
    }
  }
  else //m==0
  {
    if (isSituation1(tempArray[0], tempArray[1], tempArray[2], c1, c2))
      ++type[0];
    else if (isSituation2(tempArray[0], tempArray[1], tempArray[2], c1, c2))
      ++type[1];
    else if (isSituation3(tempArray[0], tempArray[1], tempArray[2], c1, c2))
      ++type[2];
    else if (isSituation4(tempArray[0], tempArray[1], tempArray[2], c1, c2))
      ++type[3];
    else if (isSituation5(tempArray[0], tempArray[1], tempArray[2], c1, c2))
      ++type[4];
    else if (isSituation6(tempArray[0], tempArray[1], tempArray[2], c1, c2))
      ++type[5];
    else if (isSituation7(tempArray[0], tempArray[1], tempArray[2], c1, c2))
      ++type[6];
    else if (isSituation8(tempArray[0], tempArray[1], tempArray[2], c1, c2))
      ++type[7];
    else
      ++type[8];
  }
}
int main()
{
  int A, B;
  cin >> A >> B;
  int a1, b1, a2, b2;
  cin >> a1 >> b1 >> a2 >> b2;
  card c1(a1, b1), c2(a2, b2);
  vector<card> cardArray;
  for (int i = 0; i < A; ++i)
  {
    for (int j = 0; j < B; ++j)
    {
      if (!((i == a1 && j == b1) || (i == a2 && j == b2)))
      {
        cardArray.push_back(card(i, j));
      }
    }
  }
  card tempArray[3];
  combine(cardArray, tempArray, A * B - 2, 3, c1, c2);

  for (int i = 0; i < 9; ++i)
  {
    cout << type[i] << " ";
  }
  return 0;
}