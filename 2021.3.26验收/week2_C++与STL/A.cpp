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
  int count = 0;
  for (int i = 0; i < n; ++i) //O(n^2)，暴力遍历
  {
    for (int j = i; j < n; ++j)
    {
      if (abs(inputArray[i] - inputArray[j]) == 1)
        ++count;
    }
  }
  cout << count;
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
  int count = 0;
  for (int i = 0; i < n; ++i) //O(n^2)，暴力遍历
  {
    for (int j = i; j < n; ++j)
    {
      if (abs(inputArray[i] - inputArray[j]) == 1)
        ++count;
    }
  }
  cout << count;
  return 0;
>>>>>>> 094bdc4d9ccc8ffc29ad708c5b504d76fd33efcd
}