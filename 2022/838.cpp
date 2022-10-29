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

string pushDominoes(string s)
{

  int n = s.length(); // n>0
  vi left(n, 0);      // from right to left dominos fall
  vi right(n, 0);     // from left to right dominos fall

  // left to right for 'R'
  int rpos = n + 1;
  for (int i = 0; i < n; i++)
  {
    if (s[i] == 'R')
      rpos = i; // the index of 'R'
    else if (s[i] == 'L')
      rpos = n + 1; // current idx cannot be fallen as it is 'L'

    right[i] = rpos == n + 1 ? n + 1 : i - rpos; // n+1 if not possible and i-rpos is closest distance of R to current '.'
  }

  // right to left for 'L'
  int lpos = -1;
  for (int i = n - 1; i >= 0; i--)
  {
    if (s[i] == 'R')
      lpos = -1; // not possible to find nearest 'L' for 'R'
    else if (s[i] == 'L')
      lpos = i; // store the idx of 'L' everytime as we have to find closest

    left[i] = lpos == -1 ? n + 1 : lpos - i; // if -1 it means not possible so n+1 for below conditions, otherwise lpos-i for closest idx
  }

  // print both to see
  string res = s;
  for (int i = 0; i < res.length(); i++)
  {
    if (right[i] < left[i])
    {
      // 'R' closer than 'L'
      res[i] = 'R';
    }
    else if (left[i] < right[i])
      res[i] = 'L';

    // since left[i] and right[i]=n+1 for invalid cases, they will not change which takes care of strings like "R", "L", "..."
  }
  return res;
}

int main()
{
  string s = "...";
  cout << pushDominoes(s);
  return 0;
}

/*
create 2 arrays left and right such that for string => ".L.R...LR..L.."
right = [0,0,0,0,1,2,3,0,0,1,2,0,0,0]
left = [1,0,0,0,3,2,1,0,0,2,1,0,0,0]
which we achieve by going 0 to n, n to 0 respecitvely

Then we compare left and right vectors.

1. If both are 0 - we just copy what we had in dominoes.
2. If right[i] is 0 but left[i] is not, it means this domino falls to the left, and vice versa.
3. if they are both equal, which means that we have balance of the forces and we stay vertical.
4. If we have to different values in right[i] and left[i], we find the minimum which means that it's closer.
The closer one will drop the domino first

For creating the above arrays, we go from left to right for right(n,0) and check is s[i]=='R' then we store pos=i
where pos will help to find the distance from closest R to current '.'
If s[i]=='L' we store pos=n+1 as the previoud R cannot make it R as there is L in between.
Initially here pos=n+1 or when 'L' comes in between, pos=n+1 to tell it can't fall from R

We apply same concept with left(n,0) except default value of pos is -1 not n+1
Once this is done, we check for each index if the right[i] < left[i] then res[i]='R'
else if left[i] < right[i] then res[i]='L' , if they are same then let them be what they are
*/