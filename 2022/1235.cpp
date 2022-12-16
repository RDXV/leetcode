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
int maxval = INT_MIN, minval = INT_MAX;

bool compare(vi &a, vi &b)
{
  return a[1] < b[1];
}

int solve(vi &startTime, vi &endTime, vi &profit)
{
  int n = startTime.size();
  vvi vec(n, vi(3)); // data structure to store all 3

  for (int i = 0; i < n; i++)
  {
    vec[i][0] = startTime[i];
    vec[i][1] = endTime[i];
    vec[i][2] = profit[i];
  }

  sort(vec.begin(), vec.end(), compare);

  // for (auto v : vec)
  //   cout << v[0] << " " << v[1] << " " << v[2] << "\n";

  // to maximize the profit apply DP. Create 1d dp on indices as profit, starting and endtime can repeat and are not unique constraints

  vi dp(n);          // max profit till ith index stored in dp[i]
  dp[0] = vec[0][2]; // base case profit of 1st case

  for (int i = 1; i < n; i++)
  {
    // store max of current, prev profit
    dp[i] = max(vec[i][2], dp[i - 1]);

    for (int j = i - 1; j >= 0; j--)
    {
      // check if starting time of ith job >= ending time of jth job
      if (vec[i][0] >= vec[j][1])
      {
        dp[i] = max(dp[i], dp[j] + vec[i][2]);
        break; // as dp[j] is best solution till jth element, going back doesnt make sense
      }
    }
  }

  return dp[n - 1];
}

int main()
{
  vi startTime = {1, 2, 3, 3}, endTime = {3, 4, 5, 6}, profit = {50, 10, 40, 70};
  solve(startTime, endTime, profit);
  return 0;
}