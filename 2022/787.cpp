#include <iostream>
#include <limits.h>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <bitset>
#include <stack>
#include <string>
#include <climits>
#include "unordered_map"

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

void dfs(int src, int dest, int k, int cost, unordered_map<int, vpii> &mp, int ans, vi &vis)
{
  // base cases
  if (src == dest)
  {
    ans = cost;
    return;
  }
  if (k == 0)
    return;

  vis[src] = 1;

  for (auto e : mp[src])
  {
    if (vis[e.first] == 0)
    {
      // reduce fn calls
      if (cost + e.second > ans)
        continue;

      dfs(e.first, dest, k - 1, cost + e.second, mp, ans, vis);
    }
  }

  vis[src] = 0;
}

// correct ans
int bfs(vvi &flights, int src, int dst, int k, int n)
{
  vector<vector<pair<int, int>>> adj(n);
  for (auto &e : flights)
  {
    adj[e[0]].push_back({e[1], e[2]});
  }
  vector<int> dist(n, INT_MAX);
  queue<pair<int, int>> q;
  q.push({src, 0});
  int stops = 0;

  while (stops <= k && !q.empty())
  {
    int sz = q.size();
    // Iterate on current level.
    while (sz--)
    {
      auto [node, distance] = q.front();
      q.pop();
      // Iterate over neighbors of popped node.
      for (auto &[neighbour, price] : adj[node])
      {
        if (price + distance >= dist[neighbour])
          continue;
        dist[neighbour] = price + distance;
        q.push({neighbour, dist[neighbour]});
      }
    }
    stops++;
  }
  return dist[dst] == INT_MAX ? -1 : dist[dst];
}
// using a vector to store prev ans is important so we dont go through cycles

int solve(vvi &flights, int src, int dest, int k, int n)
{
  unordered_map<int, vpii> mp;

  for (auto f : flights)

  {
    int u = f[0];
    int v = f[1];
    int wt = f[2];

    mp[u].push_back({v, wt});
  }

  int ans = INT_MAX;
  vi vis(n, 0);
  dfs(src, dest, k + 1, 0, mp, ans, vis);
  return ans == INT_MAX ? -1 : ans;
}

int main()
{
  int n = 4;
  int src = 0, dest = 3, k = 1;
  vvi flights = {{0, 1, 100}, {1, 2, 100}, {2, 0, 100}, {1, 3, 600}, {2, 3, 200}};
  cout << bfs(flights, src, dest, k, n);
  return 0;
}

// the naive bfs and dfs runs 2^V time complexity where V is number of vertices
// this comes as we do not consider checking for cycles or storing the smallest path till a given node and check all the vertices we can possibly
// go to from each vertex(just storing the min ans). Instead, if for each node, we store the smallest distance from src to that node and then
// check if later distances are smaller

// storing the smallest cost makes sense as we have to find the smallest cost to dest, it means cost to other nodes from src have
// to be smallest as well