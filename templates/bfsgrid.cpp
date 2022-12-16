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

void bfsgrid(int x, int y, vvi &dist)
{
  vvi dirs = {{0, -1}, {-1, 0}, {0, 1}, {1, 0}}; // 4 directions
  dist[x][y] = 0;                                // src is 0

  queue<pii> q;
  q.push({x, y});

  while (!q.empty())
  {
    auto [r, c] = q.front();
    q.pop();

    for (auto dir : dirs)
    {
      int row = dir[0] + r;
      int col = dir[1] + c;

      if (row < 0 || col < 0 || row >= dist.size() || col >= dist[0].size() || dist[row][col] != -1)
        continue;

      dist[row][col] = dist[r][c] + 1;
      q.push({row, col});
    }
  }

  for (int i = 0; i < dist.size(); i++)
  {
    for (int j = 0; j < dist[0].size(); j++)
    {
      cout << dist[i][j] << " ";
    }
    cout << "\n";
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

  bfsgrid(start_x, start_y, dist); // bfs from this point
  return 0;
}

/*
3 3
1 1
1 2 3
4 5 6
7 8 9

*/