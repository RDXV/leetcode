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

// recursive method
int rec(int idx, string str)
{
  int len = str.length();
  if (idx == len) // base case for reaching end
    return 1;
  if (str[idx] == '0') // string cannot start with '0'
    return 0;
  int res = rec(idx + 1, str); // for strings with single char considered
  if (idx < len - 1 && (str[idx] == '1' || (str[idx] == '2' && str[idx + 1] < '7')))
  {
    res += rec(idx + 2, str); // instead  of single char, consider 2 chars till 26, add to res not assign
  }
  return res;
}



int main()
{
  // freopen("input.txt", "r",stdin);
  // freopen("output.txt","w",stdout);
  string s;
  cin >> s;
  cout << rec(0, s); // 0 is idx we are at
  return 0;
}