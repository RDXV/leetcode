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
  if (f == 14)
    cout << char('a' + s) << " " << s << "\n";
  int prev = f;
  // Find parent of both
  f = findParent(f);
  s = findParent(s);

  if (prev == 14)
    print2(f, s);

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

/*
https://www.hackerearth.com/practice/notes/abhinav92003/disjoint-set-union/

Notice that we used the function call findParent( i ) to find the parent of the ith node, instead of directly looking at parent[ i ]. The reason for this is:
The parent of a node is not changed as soon as its affiliation to a connected component is changed. We postpone this to when we actually need to find the
parent of the node. Doing this avoids many useless operations. So, parent[ i ] may not contain the updated value of the connected component that i belongs
to. That's why it's important that we use findParent( i ) instead of being lazy and taking the value directly from parent[ i ].
*/

/*
When we do Union('o','d'), we store f=parent[f] and s=parent[s]
where parent['o']='e' and parent['d']='d', Now as 'd'<'e', parent['e']='d' is set
This is done as the last step where right now, parent['o']='e' but parent['e']='d'

Unless we do findParent('o') as last step, we wont get the correct parent of 'o'
*/