#include <iostream>
#include "vector"
#include "queue"

using namespace std;

const int N = 1e5 + 5;

// creating N vectors
vector<int> adj[N];
bool vis[N] = {false};

void dfs(int v, vector<int> &vis)
{
  // preorder
  vis[v] = 1;
  // cout << v << " ";

  // inorder
  for (int i : adj[v])
  {
    if (vis[i] == 0)
    {
      dfs(i, vis);
    }
  }

  // postorder
  cout << v << " ";
}

// Given the above function, if you change the positin of print statement after the preorder, postorder and inorder comments
// you will see the output of the graph in their order. Use alt+up/down arrow key to move current line

int main()
{
  // n is number of vertices and m is number of edges
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < m; i++)
  {
    int u, v;
    cin >> u >> v;
    adj[u].push_back(v);
    // adj[v].push_back(u);
  }
  // calling dfs for each vertex
  vector<int> vis(n, 0);
  for (int i = 0; i < n; i++)
  {
    if (vis[i] == 0)
      dfs(i, vis);
  }
  // calling dfs function
  return 0;
}