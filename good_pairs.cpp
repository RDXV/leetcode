// https://leetcode.com/problems/number-of-good-pairs/
#include <iostream>
#include <vector>
#include <unordered_map>
// void first()
// {
//     // first is O(n^2) solution which comprises going through the vector 2 times and counting the pairs
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
//     vector<int> nums;
//     unordered_map<int, int> nmap;
//     int input;
//     while (cin >> input)
//         nums.push_back(input);
// }
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> nums;
    unordered_map<int, int> nmap;
    int input;
    while (cin >> input)
        nums.push_back(input);
    // find total good pairs where a good pair is
    // nums[i]==nums[j] if i<j
    for (auto i : nums)
    {
        nmap[i]++;
        // It means when i(let's say 4) arrives then increase nmap[4] by 1 which becomes 1 if started
        // again if i(which is an element of the given vector) comes then again nmap[4]++ which becomes 2 now
    }
    if (nums.size() == 0 || nums.size() == 1)
    {
        cout << 0;
        exit(0);
    }
    int res = 0, k = 0;
    for (auto a : nmap)
    {

        // for each number do nC2
        cout << a.first << " has " << a.second << " occurences\n";
        k = a.second;
        if (k == 1)
        {
            // only 1 occurence and no pair
            res += 0;
        }
        else
        {
            res += (k * (k - 1)) / 2;
        }
        k = 0;
    }
    cout << "number of pairs is " << res;
    // Note that order of numbers does not matter despite it says i<j. for 3 4s in any order, pairs would be 3*2/2=3
    // Add these pairs to result variable and print sum
    /*
    OR
    
    for (auto i = nums.begin(); i != nums.end(); i++)
    {
        cout << *i << " ";
    }
    cout << "\n";
    for (auto i : nums)
    {
        cout << i << " ";
    }
    */
}