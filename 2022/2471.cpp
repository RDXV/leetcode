#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <climits>

#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define nline cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)
#define pb push_back
#define F first
#define S second

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using l = long;
using vll = vector<long long>;
using pii = pair<int, int>;
using pll = pair<long, long>;
using vpii = vector<pair<int, int>>;

const int mod = 1000000007;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

int cycleSort(vector<int> &nums)
{
  int n = nums.size();
  int len = n;
  map<int, int> map;
  for (int i = 0; i < len; i++)
    map[nums[i]] = i;
  sort(nums.begin(), nums.end());
  vector<bool> visited(len);
  for (int i = 0; i < len; i++)
    visited[i] = false;
  int ans = 0;
  for (int i = 0; i < len; i++)
  {
    // already swapped and corrected or already present at correct pos
    if (visited[i] || map[nums[i]] == i)
      continue;
    int j = i, cycle_size = 0;
    while (!visited[j])
    {
      visited[j] = true;
      // move to next node
      j = map[nums[j]];
      cycle_size++;
    }
    if (cycle_size > 0)
    {
      // Update answer by adding current cycle.
      ans += (cycle_size - 1);
    }
  }
  return ans;
}

int minimumOperations(TreeNode *root)
{
  queue<TreeNode *> q;
  q.push(root);
  // nullptr to identify end of level
  q.push(nullptr);
  vector<int> v;
  int ans = 0;
  while (!q.empty())
  {
    auto temp = q.front();
    q.pop();
    if (!temp)
    {
      ans += cycleSort(v);
      // clear values of old level
      v.clear();
      // if there are more elements in queue then push null to identify end else no elements are present
      // so don't push anything
      if (!q.empty())
        q.push(nullptr);
    }
    else
    {
      v.push_back(temp->val);
      if (temp->left)
        q.push(temp->left);
      if (temp->right)
        q.push(temp->right);
    }
  }

  return ans;
}
int main()
{

  return 0;
}