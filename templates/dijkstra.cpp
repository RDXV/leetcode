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
using iPair = pair<int, int>;

const int N = 1e5 + 5;

vpii adj[N];
vi dist;
// src is starting pos and n is max nodes
void dijkstra(int src, int n)
{
  priority_queue<pii, vector<pii>, greater<pii>> pq; // min heap of ipair
  dist.assign(n, INT_MAX);                           // initialize max dist for all to find min later with src dist as 0
  // if we do from node 1 to n then we do dist(n+1)
  dist[src] = 0;     // 0 dist for the src node
  pq.push({0, src}); // distance first as priority queue sorts on basis of first value and we want the smallest distance

  while (!pq.empty())
  {
    auto [d, u] = pq.top();
    pq.pop();

    for (auto [v, w] : adj[u])
    {
      // check if dist of v more than w then change
      if (dist[v] > dist[u] + w)
      {
        dist[v] = dist[u] + w;
        pq.push({dist[v], v}); // new vertex and it's distance
      }
    }
  }
}

int main()
{
  int n, m;
  cin >> n >> m;

  for (int i = 0; i < m; i++)
  {
    int u, v, w;
    cin >> u >> v >> w;
    adj[u].push_back({v, w}); // directed graph
    adj[v].push_back({u, w});
  }
  dijkstra(0, n); // 0 is starting point

  cout << "the distance for each node is :\n";
  for (int i = 0; i < n; i++)
  {
    cout << dist[i] << " ";
  }
  return 0;
}

/*
dijkstra works for acyclic graphs with no negative edge weights
min cost path finding algo with positive edges and no cycles

create a min heap storing the min weight/distance. We use pair<int,int> for storing the nbr and weight

7 8
0 1 10
0 3 40
1 2 10
2 3 10
3 4 2
4 5 3
5 6 3
4 6 8

4 4
0 2 2
0 3 8
2 3 3
1 2 1
*/