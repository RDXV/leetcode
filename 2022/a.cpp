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
int maxval = INT_MIN, minval = INT_MAX;

int solve(string s)
{
  int n = s.length();
  if (n == 1)
  {
    return s[0] == 'Y';
  }

  vector<int> rcount(n + 1);

  rcount[n - 1] = s[n - 1] == 'Y';

  for (int i = n - 2; i >= 0; i--)
  {
    rcount[i] = rcount[i + 1] + (s[i] == 'Y');
  }

  for (int num : rcount)
    cout << num << " ";
  cout << "\n";

  int curr = 0;
  int smaller = INT_MAX, idx = 0;
  int y = 0, no = 0;
  for (int i = 0; i <= n; i++)
  {
    cout << no + rcount[i] << " ";

    if (no + rcount[i] < smaller)
    {
      smaller = no + rcount[i];
      idx = i;
    }
    if (i != n && s[i] == 'N')
      no++;
  }
  return idx;
}
int main()
{
  cout << solve("YYYNY");
  return 0;
}
