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
vi colors;

// we use 3 colors => 0,1,-1 where 0 is for non visited and other 2 for the 2 sets to be made and no 2 elements of same set should be neighbours of each other
void bipartite(int src, int n)
{
  // ignore if node visited
  if (colors[src] != 0)
    return;

  colors[src] = 1; // base case of first node
  queue<int> q;
  q.push(src);

  while (!q.empty())
  {
    int node = q.front();
    q.pop();

    for (int nbr : adj[node])
    {
      if (colors[nbr] == colors[node])
      {
        // odd cycle found, not bipartite
        cout << "graph is not bipartite";
        exit(0);
      }

      if (colors[nbr] == 0)
      {
        colors[nbr] = -colors[node];
        q.push(nbr);
      }
    }
  }
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
  colors.assign(n + 1, 0);
  for (int i = 1; i <= n; i++)
  {
    bipartite(i, n); // graph may be disconnected
  }
  cout << "graph is bipartite";

  return 0;
}

/*
// bipartite
4 4
1 3
1 2
4 2
4 3

// non bipartite
3 3
1 3
1 2
2 3
*/

// bipartite graph is one where we can divide the graph nodes into 2 sets which are exhaustive and mutually exclusive
// non cyclic graphs are bipartite by default along with even cycle graphs, but odd cycle graphs are non bipartite

// Q. why is it that in case of odd cycles if 2 same color elements are neighbours then it is a break and why can't we check color of prev elements?
// A. We do bfs which is level-wise traversal going down levels so we have no problem going down as because we do bfs, it assures are nodes in level
// above current node will be coloured for sure. The only case that can be a problem is when graph is disconnected for which we have to run bipartite
// func of all nodes. Also in case of odd cycle(triangle), when 2 nodes are at same level neighbour with same colour, it means a cycle is there as
// it is coloured and since it is of same colour, it means it VIOLATES the condition that TWO VERTICES OF SAME SET MUST NOT BE CONNECTED which
// contradicts Bipartite definition