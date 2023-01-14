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

pair<char, int> dfs(int src, vvi &adj, vi &vis, string &s, int &ans)
{
  vis[src] = true;

  priority_queue<int> pq;
  int maxlen = 0;
  for (auto nbr : adj[src])
  {
    if (!vis[nbr])
    {
      auto pci = dfs(nbr, adj, vis, s, ans); // get result from children
      if (pci.first != s[src])
      {
        pq.push(-pci.second); // longest len on top
        if (pq.size() > 2)
          pq.pop();
        // remove the smaller elements till largest 2 on top as 2 children each recursion cycle gives 2 branches whose sum
        // adds to node to make the longest path
      }
    }
  }
  int maxval = 0, currmax = 0;
  if (pq.size())
  {
    int f = -pq.top();
    pq.pop();
    currmax += f;

    maxval = max(maxval, f);
  }
  currmax++; // add current node to left and right branches to make longest substring
  ans = max(ans, currmax);
  vis[src] = false; // backtracking

  return {s[src], maxval + 1}; // return character and longest length we can return from src where +1 is for src and maxval for
  // longest children length
}

int main()
{
  vi parent = {-1, 0, 0, 1, 1, 2};
  string s = "abacbe";
  int n = parent.size();
  vvi adj(n);

  for (int i = 1; i < n; i++)
  {
    adj[i].push_back(parent[i]);
    adj[parent[i]].push_back(i);
  }

  vector<int> vis(n, 0);

  int ans = 0;
  dfs(0, adj, vis, s, ans);
  cout << ans;
  return 0;
}