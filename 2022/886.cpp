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
bool bipartite(int src, vector<vector<int>> &adj, vector<int> &colors)
{
  colors[src] = 1;

  queue<int> q;
  q.push(src);

  while (!q.empty())
  {
    auto front = q.front();
    q.pop();

    for (auto nbr : adj[front])
    {
      if (colors[nbr] == 0)
      {
        colors[nbr] = -colors[front];
        q.push(nbr);
      }
      else if (colors[nbr] != 0 && colors[nbr] == colors[front])
      {
        print2(nbr, src);
        return false;
      }
    }
  }
  return true;
}

bool possibleBipartition(int n, vector<vector<int>> &dislikes)
{

  vector<vector<int>> adj(n + 1);

  for (auto dislike : dislikes)
  {
    int u = dislike[0];
    int v = dislike[1];

    adj[u].push_back(v);
    adj[v].push_back(u);
  }

  vector<int> colors(n + 1, 0);

  // graph can be disconnected
  for (int i = 1; i <= n; i++)
  {
    if (colors[i] == 0)
    {
      bool ans = bipartite(i, adj, colors);
      if (ans == false)
        return false;
    }
  }
  return true;
}

int main()
{

  int n = 4;
  vvi dislikes = {{1, 2}, {1, 3}, {2, 4}};
  cout << possibleBipartition(n, dislikes);
  return 0;
}