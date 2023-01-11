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
int solve(vi &A, int B)
{
  vector<int> positives, negatives;
  int count = 0;
  for (int num : A)
  {
    if (num < 0)
    {
      count++;
      negatives.push_back(num);
    }
    else
      positives.push_back(num);
  }

  priority_queue<int> pq; // min heap
  int n = A.size();
  if (count >= 2)
  {
    sort(negatives.begin(), negatives.end());
    sort(positives.begin(), positives.end());
    for (int i = 0; i < negatives.size() - 1; i++)
    {
      pq.push(abs(negatives[i] - negatives[i + 1]));
      if (pq.size() > n - B)
        pq.pop();
    }

    for (int i = 0; i < positives.size() - 1; i++)
    {
      pq.push(abs(positives[i] - positives[i + 1]));
      if (pq.size() > n - B)
        pq.pop();
    }
  }
  else
  {
    cout << "hey\n";
    sort(A.begin(), A.end());
    for (int i = 0; i < A.size() - 1; i++)
    {
      cout << abs(A[i] - A[i + 1]) << "\n";
      pq.push(abs(A[i] - A[i + 1]));
      if (pq.size() > n - B)
      {
        auto top = pq.top();
        cout << "top: " << top << "\n";
        pq.pop();
      }
    }
  }

  long long res = 0;
  while (!pq.empty())
  {
    auto top = pq.top();
    // cout << top << " ";
    pq.pop();
    res += top;
  }
  return res;
}

int main()
{
  vi A = {4, 3, 4, 3, 2, 5};
  int B = 3;
  cout << solve(A, B);
  return 0;
}