#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include "set"
#include <string>
#include <climits>

#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define nline cout << endl

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using l = long;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

long long solve(vector<int> &costs, int k, int candidates)
{
  priority_queue<int, vector<int>, greater<int>> left, right;
  vector<int> rem;
  int n = costs.size();

  if (candidates * 2 >= n)
  {
    sort(costs.begin(), costs.end());
    long long sum = 0;
    for (int i = 0; i < k; i++)
    {
      sum += costs[i];
    }
    return sum;
  }

  for (int i = 0; i < candidates; i++)
  {
    left.push(costs[i]);
    right.push(costs[n - i - 1]);
  }

  for (int i = candidates; i <= n - 1 - candidates; i++)
  {
    rem.push_back(costs[i]);
  }

  for (int num : rem)
    cout << num << " ";
  cout << "\n";

  int start = 0, end = rem.size() - 1;

  long long ans = 0;
  while (k--)
  {
    if (left.empty())
    {
      ans += right.top();
      right.pop();
      if (rem.size())
      {
        // cout<<rem[rem.size()-1]<<" ";
        right.push(rem[rem.size() - 1]);
        rem.pop_back();
      }
    }
    else if (right.empty())
    {
      ans += left.top();
      left.pop();
      if (rem.size())
      {
        left.push(rem[0]);
        rem.erase(rem.begin());
      }
    }
    else if (left.top() <= right.top())
    {
      // cout<<"left: "<< left.top()<<" right: "<<right.top()<<" ";
      // cout << "left: " << left.top() << " ";
      ans += left.top();

      left.pop();
      cout << left.top() << " ";
      if (rem.size())
      {
        // cout<<"rem[0]: "<<rem[0]<<" ";
        left.push(rem[0]);
        rem.erase(rem.begin());
      }
    }
    else
    {
      ans += right.top();
      right.pop();
      if (rem.size())
      {
        // cout<<rem[rem.size()-1]<<" ";
        right.push(rem[rem.size() - 1]);
        rem.pop_back();
      }
    }
  }
  return ans;
}

int main()
{
  vector<int> nums = {57, 33, 26, 76, 14, 67, 24, 90, 72, 37, 30};
  int candidates = 2;
  int k = 11;
  cout << solve(nums, k, candidates);
  return 0;
}

// [57,33,26,76,14,67,24,90,72,37,30]
// 11
// 2
