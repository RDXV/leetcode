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
int bfs(vector<vector<int>> &adj, vector<bool> &vis, int curr)
{
  queue<int> q;
  q.push(curr);
  int count = 1;
  vis[curr] = true;

  while (!q.empty())
  {
    int node = q.front();
    q.pop();

    for (int nbr : adj[node])
    {
      if (vis[nbr] == false)
      {
        count++;
        vis[nbr] = true;
        q.push(nbr);
      }
    }
  }
  cout << count << "\n";

  return count;
}

long long countPairs(int n, vector<vector<int>> &edges)
{
  vector<vector<int>> adj(n);
  for (auto edge : edges)
  {
    int u = edge[0];
    int v = edge[1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> vec;

  vector<bool> vis(n, false);
  for (int i = 0; i < n; i++)
  {
    if (vis[i] == false)
    {
      int val = bfs(adj, vis, i);
      vec.push_back(val);
    }
  }

  // cout << vec.size();

  if (vec.size() == 1)
    return 0;

  long long ans = 0;
  for (int i = 0; i < vec.size(); i++)
  {
    for (int j = i + 1; j < vec.size(); j++)
    {
      ans += vec[i] * vec[j];
    }
  }
  return ans;

  // return 0;
}

const int mod = 1000000007;
int main()
{

  int n = 7;
  vvi edges = {{0, 2}, {0, 5}, {2, 4}, {1, 6}, {5, 4}};
  cout << countPairs(n, edges);
  return 0;
}