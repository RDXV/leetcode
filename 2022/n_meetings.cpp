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

void sol(vi &start, vi &end)
{
}

int main()
{
  int N;
  cin >> N;
  vi start(N), end(N);
  for (int i = 0; i < N; i++)
  {
    cin >> start[i] >> end[i]; // input the start and end time
  }
  return 0;
}
