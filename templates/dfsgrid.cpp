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

vvi dirs = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void dfsgrid(int x, int y, vvi &dist, int pos = 0)
{

  dist[x][y] = pos++;

  for (auto dir : dirs)
  {
    int row = dir[0] + x;
    int col = dir[1] + y;

    if (row < 0 || col < 0 || row >= dist.size() || col >= dist[0].size() || dist[row][col] != -1)
      continue;

    dfsgrid(row, col, dist, pos);
  }
}

int main()
{
  int n, m;
  cin >> n >> m;
  int start_x, start_y;
  cin >> start_x >> start_y;

  vvi grid(n, vi(m));

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> grid[i][j];
    }
  }

  vvi dist(n, vi(m, -1));
  dfsgrid(start_x, start_y, dist); // use this as visited

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cout << dist[i][j] << " ";
    }
    cout << "\n";
  }

  return 0;
}