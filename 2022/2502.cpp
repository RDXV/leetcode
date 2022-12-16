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

class Allocator
{
public:
  vector<int> vec;
  int sz;
  map<int, vector<int>> um;
  Allocator(int n)
  {

    vec.assign(n, -1);
    sz = n;
  }

  int allocate(int size, int mID)
  {

    // first check if continuous block free, idx is starting point of free block
    int free = 0, idx;
    for (int i = 0; i < sz; i++)
    {
      if (free == 0)
        idx = i;
      if (vec[i] == -1)
        free++; // empty continuous block
      else
        free = 0;

      if (free >= size)
        break; // break from for inner loop not func
    }

    if (free >= size)
    {
      for (int i = idx; i < idx + size; i++)
      {
        vec[i] = mID;
        um[mID].push_back(i);
      }
    }

    return free >= size ? idx : -1; // returning starting point if free found else -1
  }

  int free(int mID)
  {

    int count = 0;
    for (auto x : um[mID])
    {
      vec[x] = -1; // deallocate to -1
      count++;
    }
    // remove mID from map
    um.erase(mID);
    return count;
  }
};

int main()
{

  return 0;
}