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
vi solve(vvi &tasks)
{
  int n = tasks.size();

  // first push the indices as we need them
  fo(i, n) tasks[i].push_back(i);

  sort(tasks.begin(), tasks.end()); // tasks now from smallest start time to longest

  int curr_time = tasks[0][0];
  priority_queue<pii, vector<pii>, greater<pii>> pq;
  int idx = 0; // start from smallest starting element and keep track
  vi ans;

  while (ans.size() < tasks.size())
  {
    // push all elements with smaller starting time
    while (idx < tasks.size() && tasks[idx][0] <= curr_time)
    {
      pq.push({tasks[idx][1], tasks[idx][2]}); // push the current tasks' process time and idx
      idx++;                                   // make sure to increase it for next task to be considered
    }

    if (!pq.empty())
    {
      auto [top_process_time, top_idx] = pq.top();
      pq.pop();
      // change the current time to smallest top time
      curr_time += top_process_time; // add this processing time and then the index
      ans.push_back(top_idx);
    }
    else if (idx < tasks.size())
    {
      // case where gap to next starting time, so we move to that task as we did idx++ above
      curr_time = tasks[idx][0]; // store this new time to fill the gap
    }
  }
  return ans;
}

int main()
{
  int n; // number of tasks
  cin >> n;

  vvi tasks(n, vi(2)); // n*2
  fo(i, n) cin >> tasks[i][0] >> tasks[i][1];

  vi ans = solve(tasks);
  for (int num : ans)
    cout << num << " ";
  return 0;
}

/*
here we have to take the shortest time task first along with those in same time, push them in min heap which sorts by smallest processing time
 case [[1,2], [2,4], [3,2], [4,1]] => here the shortest task is [1,2] so we take it first and now after doing this, we are at time=1+2=3

 Now here we consider all tasks with starting time<=3 which are [[2,4], [3,2]]. Out of these we take [3,2] as it's processing time is smaller(2<4) and run this task
 Now we are at time = 3+2=5, and we push in pq all the tasks smaller than 5 which are [[2,4], [4,1]]. Here again 1<4 so we consider this task and at the end, ans of their
 indices as [0,2,3,1] where tasks[1] = [2,4] was done at the end
*/