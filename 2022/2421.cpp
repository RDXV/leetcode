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

int parent[100000];
int rnk[100000];
void makeSet(int n)
{
  for (int i = 1; i <= n; i++)
  {
    parent[i] = i; // make self parents
    rnk[i] = 0;    // initialise rank as 0
  }
}

int findParent(int node)
{
  // check if self parent
  if (node == parent[node])
  {
    return node;
  }
  // otherwise find parent[node] till above condition holds true
  return parent[node] = findParent(parent[node]);
  // call recursive function for parent of current node till self parent if 7->8->4->3 then call
  // func for 3 which points to itself and returns so we make calls and make parent[7]=3 when node==parent[node] this is path compression does
}

void Union(int f, int s)
{
  // Find parent of both
  f = findParent(f);
  s = findParent(s);

  // check their ranks, if first has smaller then attach smaller to bigger rank
  // attaching smaller tree to bigger does not inc height but opposite does
  if (rnk[f] < rnk[s])
  {
    parent[f] = s; // make parent of f as s
  }
  else if (rnk[f] > rnk[s])
  {
    parent[s] = f;
  }
  else
  {
    // same ranks so attach any and increase the rnk of the new parent
    parent[s] = f; // making f as parent, can do opp too
    rnk[f]++;      // increase rank of f as height of tree inc
  }
}

int solve(vi &vals, vvi &edges)
{
  int n = vals.size();
  vvi adj(n);
  for (auto edge : edges)
  {
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);
  }

  map<int, vi> sortedValueMap; // stores same valued nodes as we need paths btw them
  for (int i = 0; i < n; i++)
  {
    int val = vals[i];                // value at ith position for later counting pairs, also i is the tree node value
    sortedValueMap[val].push_back(i); // map values with indices in increasing order(as larger values mean more distant nodes)
  }

  makeSet(n); // parent and rank array initialization
  int goodPaths = 0;

  // start with making paths from smallest nodes
  for (auto &[value, sameValueNodeArray] : sortedValueMap)
  {
    for (auto node : sameValueNodeArray)
    {
      for (int nbr : adj[node])
      {
        // check nbr value not bigger
        if (vals[node] >= vals[nbr])
        {
          Union(node, nbr);
        }
      }
    }

    // go through all the nodes, find their parents and group them together to count paths
    unordered_map<int, int> groupedNodesMap;
    for (auto node : sameValueNodeArray)
    {
      int nodeParent = findParent(node);
      groupedNodesMap[nodeParent]++; // count same parents as they form paths
    }

    // now if we have n nodes and we have to form pairs, ans is n*(n-1)/2 but as we include self paths, ans = n+(n*(n-1)/2) = n*(n+1)/2
    for (auto &[parentNodeKey, sameGroupNodesCount] : groupedNodesMap)
    {
      cout << sameGroupNodesCount << " ";
      goodPaths += sameGroupNodesCount * (sameGroupNodesCount + 1) / 2;
    }
  }
  return goodPaths;
  // do findParent(i) again for all nodes to assign correct parents like LC: 1061 => https://leetcode.com/problems/lexicographically-smallest-equivalent-string/
  // as if e->o and d->o then parent[c]=b unless we do findParent(c) again at the end as after Union(d,o) we assigned parent[]
}
int main()
{

  vi vals = {6, 7, 3, 6, 18, 9, 9, 1, 14, 17, 15, 14, 12, 10, 2, 8, 11, 18, 7, 12, 16, 13, 2, 9, 19, 5, 7, 19, 2, 4, 8};
  vvi edges = {{1, 0}, {0, 2}, {3, 0}, {0, 4}, {5, 1}, {6, 4}, {4, 7}, {4, 8}, {6, 9}, {4, 10}, {0, 11}, {12, 5}, {12, 13}, {3, 14}, {9, 15}, {15, 16}, {17, 15}, {18, 11}, {4, 19}, {19, 20}, {21, 3}, {22, 9}, {23, 22}, {16, 24}, {25, 20}, {9, 26}, {27, 12}, {14, 28}, {29, 15}, {30, 27}};
  cout << solve(vals, edges);

  return 0;
}

// As we have to not include any bigger values in path btw 2 nodes, we start with smaller value nodes and form their paths and then go
// to larger nodes with union find connected component technique