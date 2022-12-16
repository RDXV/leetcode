// https://youtu.be/3gbO7FDYNFQ
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

using namespace std;

using vi = vector<int>;
using vvi = vector<vector<int>>;
using ll = long long;
using l = long;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

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

// If we call recursive func we are not compressing the path. By doing parent[node] = findParent(parent[node]) we recursively call finding self parent and
// then assign the current node parent as that element compressing the path

void Union(int f, int s)
{
  // Find parent of both
  f = findParent(f);
  s = findParent(s);

  // check their ranks, if first has smaller then attach smaller to bigger rank
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

int main()
{
  int num = 7;
  makeSet(num);
  while (num--)
  {
    int f, s;
    cin >> f >> s;
    Union(f, s);
  }

  // for checking same component of 2,3 do findParent(2) and findParent(3) and compare vals
  if (findParent(2) != findParent(3))
    cout << "parent diff";
  else
    cout << "same component";
  return 0;
}
