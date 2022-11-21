/*
 * @lc app=leetcode id=1027 lang=cpp
 *
 * [1027] Longest Arithmetic Subsequence
 */

// @lc code=start
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

class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        // nums[i]-nums[j] values can vary from 0 to 1001 after adding 500 as 0<=nums[i]<=500
        int n = nums.size();
        vvi dp(n, vi(1001, 0));
        int maxval = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                int diff = nums[i] - nums[j] + 500; // max value of nums[i]=500
                // for current ith element, to find the value, we check the longest subsequence till jth
                // as after jth element we are adding this. If till jth, ans=0, store ans as 2 for ith and jth element subsequence

                dp[i][diff] = dp[j][diff] > 0 ? dp[j][diff] + 1 : 2; // add 1 if exists otherwise store 2
                maxval = max(maxval, dp[i][diff]);
            }
        }
        return maxval;
    }
};
// @lc code=end

/* few things to understand, there are 2 variables -
1. nums[i] or i, till which we have to find the optimal solution each time till last element,
2. diff = nums[i]-nums[j] which is diff between 2 numbers

as we have to find subsequence, we have to keep checking for same diff as update the values
*/