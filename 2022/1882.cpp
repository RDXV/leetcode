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

void assignTasks(vi servers, vi tasks)
{
  map<int, vi> m1;
  for (int i = 0; i < servers.size(); i++)
    m1[servers[i]].push_back(i); // 3 -> {0,1}

  for (auto [key, val] : m1)
  {
    cout << key << " ";
    for (int num : val)
      cout << num << " ";
    cout << "\n";
  }

  if (m1.find(3) != m1.end())
    cout << m1[3][1];
  else
    cout << "hello";
}

int main()
{
  assignTasks({3, 3, 2}, {1, 2, 3, 2, 1, 2});
  return 0;
}