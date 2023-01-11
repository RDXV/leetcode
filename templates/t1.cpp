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

void solve(int n, vi &nums)
{
  sort(nums.begin(), nums.end());

  int min_diff = nums[n - 1] - nums[0];
  for (int i = 0; i < n - 1; i++)
  {
    int temp = nums[i + 1] - nums[i];
    if (temp < min_diff)
      min_diff = temp;
  }

  int max_min_diff, min_max_diff;
  // we can choose either the first or the last element and change
  // If we choose min element and change it to nums[n-1] - min_diff then max difference will be a[n-1] - a[0]
  // if we choose max element and change it to nums[0] + min_diff then max difference will be a[n-1] - a[0]

  min_max_diff = min(nums[n - 1] - min_diff, nums[0] + min_diff);

  // Similarly we can choose either the 2nd or the 2nd last element and change
  // If we choose 2nd min element and change it to nums[n-1] - min_diff then max difference will be a[n-1] - a[0]
  max_min_diff = max(nums[n - 2] - min_diff, nums[1] + min_diff);

  cout << max_min_diff << " " << min_max_diff << "\n";
}

int main()
{
  int n;
  cin >> n;
  vi nums(n);

  fo(i, n) cin >> nums[i];
  solve(n, nums);

  return 0;
}