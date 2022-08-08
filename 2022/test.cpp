#include <iostream>
#include "map"
#include "vector"

using namespace std;

int main()
{
  map<int, int> m1;
  map<int, vector<int>> m2;
  vector<int> g = {3, 3, 3, 3, 3, 1, 3};
  int len = g.size();
  for (int i = 0; i < g.size(); i++)
  {
    m1[g[i]]++;
    m2[g[i]].push_back(i); //  push index in second
  }

  for (auto i : m1)
  {
    cout << i.first << " " << i.second << "\n";
    for (auto j : m2[i.first])
    {
      cout << j << " ";
    }
    cout << "\n";
  }

  vector<vector<int>> v1;
  v1.push_back({1});
  return 0;
}