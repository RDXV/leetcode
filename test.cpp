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

int pivotInteger(int n)
{
  if (n == 1)
    return 1;

  vector<int> left(n + 1, 0), right(n + 1, 0);

  for (int i = 1; i <= n; i++)
  {
    left[i] = left[i - 1] + i;
  }

  right[n] = n;
  for (int i = n - 1; i >= 1; i--)
  {
    right[i] = right[i + 1] + i;
  }

  for (int i = 1; i <= n; i++)
  {
    if (left[i] == right[i])
      return i;
  }
  return -1;
}
int main()
{
  cout << pivotInteger(10);
  return 0;
}