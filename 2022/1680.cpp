#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <stack>
#include <string>
#include <climits>
#include "cmath"

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

int bitsNum(int num)
{
  return log2(num) + 1; // 2 has 2 bits and 1 has 1
  // log2 8 must be 3 as 2^3 is 8 but at same time 7 < 2^3 so we get 2^2 or 2 as the ans so
  // it returns 2+1=3 for 7
}

int main()
{
  long ans = 0, mod = 1e9 + 7;
  int num;
  cin >> num;
  for (int i = 1; i <= num; i++)
  {
    int n = bitsNum(i); // find the number of bits of current number
    ans = ((ans << n) % mod + i) % mod;
  }
  cout << (int)ans;
  return 0;
}

/*
here we push the number in ans variable, find the bits of next number and push the ans
variable left shift that number of bits so the next number can fit in and then push the number
to ans like before.
Reference => https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
*/