/*
 * @lc app=leetcode id=374 lang=cpp
 *
 * [374] Guess Number Higher or Lower
 */

// @lc code=start
/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution
{
public:
    int guessNumber(int n)
    {
        long long hi = n, lo = 1;
        long long ans;
        while (lo <= hi)
        {
            long long mid = (hi - lo) / 2 + lo;
            if (guess(mid) == 0)
            {
                ans = mid;
                return ans;
            }
            else if (guess(mid) == -1)
            {
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        return ans;
    }
};
// @lc code=end
