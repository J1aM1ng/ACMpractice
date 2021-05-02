#include <bits/stdc++.h> //单调栈
#define ll long long
using namespace std;
ll heights[100005];
ll Right[100005]; //对于第i个矩形，其右边第一个比它的高度低的元素的下标
ll Left[100005];  //对于第i个矩形，其左边第一个比它的高度低的元素的下标
stack<int> st;    //单调栈，假定左边是栈底，右边是栈顶
int n;            //n个长条状矩形
int main()
{
  ios::sync_with_stdio(false);
  while (1)
  {
    cin >> n;
    if (n == 0)
    {
      return 0;
    }
    for (int i = 1; i <= n; i++)
    {
      cin >> heights[i];
    }                                //输入
    heights[n + 1] = 0;              //最后一个元素，其右侧“矩形"的高度置为0
    st.push(0);                      //第一个元素，其左侧”矩形“的高度置为0
    for (int i = 1; i <= n + 1; i++) //维护单调栈中元素（从栈底到栈顶）单调递增
    {
      while ((!st.empty()) && (heights[i] < heights[st.top()])) //若新矩形高度低于目前单调栈中栈顶元素的高度
      {
        Right[st.top()] = i; //i对应元素为目前栈顶元素右边第一个比（栈顶元素）小的元素
        //被谁弹出来，谁就是其右边的第一个比它小的元素
        st.pop(); //弹出栈顶元素
      }
      if (!st.empty()) //走到这里了说明前面（目前元素比目前栈顶元素的高度低）这一条件不满足，则目前元素入栈也是符合栈单调递增的
      {
        Left[i] = st.top(); //入栈前的栈顶是他的左边第一个比它高度低的元素
        //栈内左边的元素，是其左边的第一个比它小的元素
      }
      st.push(i); //当前元素（i对应元素）入栈
    }
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
      res = max(res, (Right[i] - Left[i] - 1) * heights[i]);
    }
    cout << res;
    break;
  }
  return 0;
}