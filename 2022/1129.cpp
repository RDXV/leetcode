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

vi solve(int n, vvi &red, vvi &blue)
{
  // create a adjacency list with color as well along with node connected to u-> {v, color}
  vector<vpii> graph(n); // n vectors of vector<pair<int,int>>

  for (auto r : red)
  {
    int u = r[0];
    int v = r[1];
    graph[u].pb({v, 1});
  }

  for (auto b : blue)
  {
    int u = b[0];
    int v = b[1];
    graph[u].pb({v, -1});
  }

  // now we need to store the shortest distances using bfs
  vi dist(n, -1), vis(n, 0);
  queue<tuple<int, int, int>> q; // {node, distance, color}
  q.push({0, 0, 0});             // initial color is 0

  while (!q.empty())
  {
    auto [node, distance, color] = q.front();
    cout << node << " ";
    q.pop();

    dist[node] = dist[node] == -1 ? distance : dist[node]; // if old distance is -1, we assign distance value passed otherwise we have shortest distance

    for (auto &[nbr_node, nbr_color] : graph[node])
    {
      // if same color as nbr or if nbr_node already visited, ignore
      if (nbr_color == color || nbr_node == -1)
        continue;

      q.push({nbr_node, distance + 1, nbr_color}); // new element as nbr with +1 distance and other color
      print1(nbr_node);
      nbr_node = -1;
      print1(nbr_node);
      cout << "\n";
    }
  }
  return dist;
}

int main()
{
  int n = 5;
  vvi redEdges = {{0, 1}, {1, 2}, {2, 3}, {3, 4}};
  vvi blueEdges = {{1, 2}, {2, 3}, {3, 1}};
  auto ans = solve(n, redEdges, blueEdges);
  cout << "\n";
  for (auto a : ans)
    cout << a << " ";
  return 0;
}

// if u use vis[node] as check then it gives WA but when we change nbr_node=-1 and have check, it works
// if we have to use vis, we have to do vis[nbr][color] as we can come back to nbr with different color path to cover

// in the graph, we mark nbr_node=-1 for the pair<int,int> {nbr_node, nbr_color} and not just the nbr_node
// so in case of {1,red} and {1,blue} are the 2 pairs of nbr_node=1 and colors red and blue,
// if we have to mark nbr_node=-1 for one of them, it will change to {-1,red}, {1,blue} and not {-1,red}, {-1,blue} which we got in case
// of just vis[nbr_node]

/*
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
vector<vector<int>> adj[n];

for (int i = 0; i < red.size(); i++)
{

    int u = red[i][0];
    int v = red[i][1];

    adj[u].push_back({v, 0});
}
for (int i = 0; i < blue.size(); i++)
{

    int u = blue[i][0];
    int v = blue[i][1];

    adj[u].push_back({v, 1});
}

vector<int> distance(n, -1);
distance[0] = 0;

queue<vector<int>> pq;
vector<vector<int>> visited(n, vector<int>(2, 0));

pq.push({0, 0, -1});

visited[0][0] = 1;
visited[0][1] = 1;

while (!pq.empty())
{
    int node = pq.front()[1];
    int nodeWeight = pq.front()[0];
    int nodecolor = pq.front()[2];

    pq.pop();

    for (auto itr : adj[node])
    {
        int adjNode = itr[0];

        int color = itr[1];

        if (visited[adjNode][color] == 0 and color != nodecolor)
        {
            if (distance[adjNode] == -1)
                distance[adjNode] = nodeWeight + 1;
            pq.push({nodeWeight + 1, adjNode, color});

            visited[adjNode][color] = 1;
        }
    }
}

return distance;
    }
*/