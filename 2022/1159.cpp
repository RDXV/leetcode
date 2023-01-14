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
#define print3(x, y, z) cout << #x << '=' << x << ',' << #y << '=' << y << ',' << #z << '=' << z << endl
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

vector<int> countSubTrees(int src, vector<vector<int>> &adj, string &labels, vi &vis, vi &ans)
{
  vis[src] = true;
  vector<int> mapper(26);
  int src_char_index = labels[src] - 'a'; // the character whose count we have to increase
  mapper[src_char_index] = 1;
  // store 1 for current and add the sum for children instead of later doing mapper[src_char_index]++ as later
  // traversal will contain prev answers
  for (auto nbr : adj[src])
  {
    if (!vis[nbr])
    {
      auto childCounter = countSubTrees(nbr, adj, labels, vis, ans);
      for (int i = 0; i < 26; i++)
      {
        mapper[i] += childCounter[i]; // add below values
      }
    }
  }

  // src is the node index
  ans[src] = mapper[src_char_index];
  vis[src] = false; // backtracking
  return mapper;
}
int main()
{
  vvi edges = {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
  string labels = "abaedcd";
  int n = 7;
  vi vis(n);
  vvi adj(n);
  for (auto edge : edges)
  {
    adj[edge[0]].pb(edge[1]);
    adj[edge[1]].pb(edge[0]);
  }
  vi ans(n);

  countSubTrees(0, adj, labels, vis, ans);
  for (int a : ans)
    cout << a << " ";
  return 0;
}