#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <string>
#include <climits>

#define print1(x) cout << #x << '=' << x << endl
#define print2(x, y) cout << #x << '=' << x << ',' << #y << '=' << y << endl
#define nline cout << endl
#define fo(i, n) for (int i = 0; i < n; i++)
#define Fo(i, k, n) for (int i = k; i < n; i++)
#define pb push_back
#define sz(x) ((long long)(x).size())
#define ppb pop_back
#define ff first
#define ss second

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
const int max_n = 1000000;

int maxval = INT_MIN, minval = INT_MAX;

class TreeNode
{
public:
  TreeNode *left, *right;
  int val;
  TreeNode(int val)
  {
    this->val = val;
    left = nullptr;
    right = nullptr;
  }
};

TreeNode *solve(string s)
{
  map<int, TreeNode *> mp; // represent the key=level, value=node_val

  int i = 0;
  while (i < s.length())
  {
    int currlevel = 0, val = 0;
    while (i < s.length() && s[i] == '-')
    {
      i++;
      currlevel++;
    }
    cout << "i: " << i << " ";
    while (i < s.length() && s[i] >= '0' && s[i] <= '9')
    {

      cout << "i: " << i << " "
           << "s[i]: " << s[i] << "\n";
      val = val * 10 + (s[i] - '0');
      i++;
    }
    TreeNode *node = new TreeNode(val); // create a node
    mp[currlevel] = node;               // IMP as we assign the node and then mark with the parent, also takes care of base case
    if (currlevel > 0)
    {
      TreeNode *parent = mp[currlevel - 1];
      if (parent->left)
        parent->right = node;
      else
        parent->left = node; // not mp[currlevel] as it's value changes but this memory location is constantly stored
    }
  }
  return mp[0];
}

int main()
{
  string inp = "1-2--3--4-5--6--7";
  solve(inp);
  return 0;
}