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

int parent[100000];
int rnk[100000];

void makeSet(int n)
{
  for (int i = 0; i < n; i++)
  {
    parent[i] = i; // self parent at start
  }
}

int findParent(int node)
{
  if (parent[node] == node)
    return node;

  return parent[node] = findParent(parent[node]); // path compression
}

// as parent[node] not same as node, we recursively find the parent of node till self parent and then store to compress the path

void Union(int f, int s)
{
  f = findParent(f);
  s = findParent(s);

  parent[f] = s;
}
int main()
{
  int sz = 7;
  makeSet(sz);

  while (sz)
  {
    int f, s;
    cin >> f >> s;
    Union(f, s);
    sz--;
  }
  // for checking same component of 2,3 do findParent(2) and findParent(3) and compare vals
  if (findParent(2) != findParent(3))
    cout << "parent diff";
  else
    cout << "same component";
  return 0;
}
// This is DSU without rank

// In unionfind.cpp we use rank so as to do path compression to reduce the height of the tree
// How it does it work and help? consider case where we do Union(1,2) Union(2,3) and Union(3,4)
// without path compression it would be 1->2->3->4 as big tree and to find parent[4] it will have to do whole traversal

// so in findParent() method we have to do
// if(parent[f]!=f) return parent[f]=findParent(f) to store this ancestor value, this is path compression