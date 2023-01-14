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
int parent[100000];

void makeSet()
{
  for (int i = 0; i < 26; i++)
  {
    parent[i] = i; // make self parents
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
}

// If we call recursive func we are not compressing the path. By doing parent[node] = findParent(parent[node]) we recursively call finding self parent and
// then assign the current node parent as that element compressing the path

void Union(int f, int s)
{
  // Find parent of both
  f = findParent(f);
  s = findParent(s);

  if (f == s)
    return;
  if (f < s)
  {
    parent[s] = f;
  }
  else
    parent[f] = s;
}
string smallestEquivalentString(string s1, string s2, string baseStr)
{

  int n = s1.length();
  makeSet();
  for (int i = 0; i < n; i++)
  {
    int v1 = s1[i] - 97;
    int v2 = s2[i] - 97;
    Union(v1, v2);
  }

  for (int i = 0; i < 26; i++)
  {
    cout << parent[i] << " ";
  }
  cout << "\n";
  // for (int i = 0; i < 26; i++)
  // {
  //   cout << findParent(i) << " ";
  // }
  // cout << "\n";

  // as ('e', 'd') and ('d', 'o') are from same component, we have to do findParent(i) to make common parent of o,e,d as d
  // printing parent[i] shows different result as printing findParent(i) at position of 'o'
  for (char &ch : baseStr)
  {
    int val = ch - 'a';
    char newch = parent[val] + 'a';
    cout << newch << " ";
    ch = newch;
  }
  cout << "\n";

  return baseStr;
}
int main()
{
  cout << smallestEquivalentString("hello", "world", "hold");
  return 0;
}