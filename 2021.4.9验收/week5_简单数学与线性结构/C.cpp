#include <bits/stdc++.h> //滑动窗口问题 单调队列实现
using namespace std;
vector<int> inputArray;
int n, k; //n个数  k为滑动的窗口大小

vector<int> maxWindow(vector<int> &nums, int k) //返回 每次的局部最大值 的数组max
{
  int n = nums.size(); //nums:所有的n个数
  if (n == 0)
  {
    return {};
  }
  deque<int> index; //双向队列（逻辑结构为单调队列）存储窗口中元素下标，队首到队尾从大到小排序，每次队首元素为局部最大值
  vector<int> max;  //返回 每次的局部最大值 的数组max
  for (int i = 0; i < n; ++i)
  {
    if (!index.empty() && index.front() == i - k) //队首元素下一时刻不属于K区间，pop队首
    {
      index.pop_front();
    }
    while (!index.empty() && nums[i] > nums[index.back()])
    {
      index.pop_back(); //维护单调递减的队列，维持队首的值为最大值，若下一个值比队尾元素大，则使队尾出队
    }
    index.push_back(i); //直到下一个值不比队尾元素大，使该元素（的下标）入队
    if (i + 1 >= k)
    {
      max.push_back(nums[index.front()]); //如果窗口长度大于k，则往最大值数组中添加队首元素（局部最大值）
    }                                     //相当于在滑动窗口满时，将队首元素从窗口中剔除，而塞进最大值数组max中
  }
  return max;
}
vector<int> minWindow(vector<int> &nums, int k) //返回 每次的局部最小值 的数组min 同理
{
  int n = nums.size();
  if (n == 0)
  {
    return {};
  }
  deque<int> index; //存储窗口中元素下标，从大到小排序
  vector<int> min;
  for (int i = 0; i < n; ++i)
  {
    if (!index.empty() && index.front() == i - k)
    {
      index.pop_front(); //队首元素下一时刻不属于K区间，pop队首
    }
    while (!index.empty() && nums[i] < nums[index.back()])
    {
      index.pop_back(); //维护单调递增的队列，维持队首的值为最小值，若下一个值比队尾元素小，则使队尾出队
    }
    index.push_back(i); //直到下一个值不比队尾元素小，使该元素（的下标）入队
    if (i + 1 >= k)
    {
      min.push_back(nums[index.front()]); //如果窗口长度大于k，则往最大值数组中添加队首元素（局部最小值）
    }
  }
  return min;
}
int main(void)
{
  ios::sync_with_stdio(false);
  cin >> n >> k;
  for (int i = 1; i <= n; i++)
  {
    int temp;
    cin >> temp;
    inputArray.emplace_back(temp);
  }
  vector<int> max = maxWindow(inputArray, k);
  vector<int> min = minWindow(inputArray, k);
  for (int i = 0; i < min.size(); i++)
  {
    cout << min[i] << " ";
  }
  cout << '\n';
  for (int i = 0; i < max.size(); i++)
  {
    cout << max[i] << " ";
  }
  return 0;
}