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

vi adj[max_n];

void toposort(int n)
{
  vi sorted, indegree(n);

  for (int i = 0; i < n; i++)
  {
    for (int nbr : adj[i])
    {
      indegree[nbr]++;
    }
  }

  queue<int> q;

  for (int i = 0; i < n; i++)
  {
    if (indegree[i] == 0)
      q.push(i);
  }

  while (!q.empty())
  {
    int val = q.front();
    cout << val << " ";
    q.pop();
    sorted.push_back(val);

    for (int node : adj[val])
    {
      indegree[node]--; // as we arrive at this node, reduce the indegree
      if (indegree[node] == 0)
        q.push(node);
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (indegree[i])
    {
      cout << " NOT POSSIBLE as cycle detected";
      return;
    }
  }
  cout << "\n";
  for (int val : sorted)
    cout << val << " ";
}

int main()
{
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  toposort(n);
  return 0;
}

// using bfs(kahn's algorithm) and not dfs