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

// 0 to 1 edge is not adding giving ans as 6 and not 8, still WA
bool helper(int node, vector<bool> &hasApple, int &ans, vector<vector<int>> &adj, vector<int> &vis)
{
  vis[node] = true;

  int childTime = 0;
  for (auto nbr : adj[node])
  {
    // ans+=helper(nbr, hasApple, ans);
    if (!vis[nbr])
    {
      childTime = helper(nbr, hasApple, ans, adj, vis);

      if (childTime || hasApple[nbr])
        ans += childTime + 1;
      print3(node, nbr, ans); // nbr=1 gives diff ans where node is 0
    }
  }
  if (childTime || hasApple[node])
  {
    hasApple[node] = false;
    return true;
  }

  vis[node] = false;
  return false;
}
int minTime(int n, vector<vector<int>> &edges, vector<bool> &hasApple)
{
  vector<vector<int>> adj(n);
  vector<int> vis(n);

  for (auto edge : edges)
  {
    int u = edge[0];
    int v = edge[1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  int ans = 0;
  helper(0, hasApple, ans, adj, vis);
  return ans;
}
int main()
{
  int n = 7;
  vvi edges = {{0, 1}, {0, 2}, {1, 4}, {1, 5}, {2, 3}, {2, 6}};
  vector<bool> hasApples = {false, false, true, false, true, true, false};
  cout << minTime(n, edges, hasApples);
  return 0;
}

// using ans as reference and bool return is not a good idea, refer to 1443.cpp for correct implementation