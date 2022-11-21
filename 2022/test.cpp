#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include "set"
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

int main()
{
  set<int> s;
  s.insert(1);
  s.insert(2);

  for (int num : s)
    cout << num << " ";
  return 0;
}