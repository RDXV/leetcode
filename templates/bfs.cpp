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

vi adj[max_n], vis;

int maxval = INT_MIN, minval = INT_MAX;

void bfs(int src, int n)
{
  vis.assign(n + 1, -1);
  queue<int> q;
  vis[src] = 0;
  q.push(src);

  while (!q.empty())
  {
    auto node = q.front();
    q.pop();

    for (auto nbr : adj[node])
    {
      // only visit new nodes
      if (vis[nbr] == -1)
      {
        q.push(nbr);
        vis[nbr] = vis[node] + 1;
      }
    }
  }

  for (int v : vis)
    cout << v << " ";
}

int main()
{
  int n, m; // n is nodes, m edges
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  bfs(1, n);

  return 0;
}

/*
4 3
1 3
3 4
2 3

*/