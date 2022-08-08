#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool check(vector<int> nums)
{
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] <= nums[i - 1])
        {
            return false;
        }
    }
    return true;
}
int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> nums;
    int input, count = 0;
    while (cin >> input)
        nums.push_back(input);
    if (nums.size() == 1)
    {
        cout << 0;
        exit(0);
    }

    while (!check(nums))
    {
        // cout << "hello";
        for (int i = nums.size() - 1; i > 0; i--) // not the first element
        {
            if (nums[i] <= nums[i - 1])
            {
                nums[i]++;
                count++;
            }
        }
    }
    cout << "min operations " << count;

    // Time limit exceeded
    /*
    Another answer would be
    for(int i=1;i;<nums.size();i++)
    {
        if(nums[i]<=nums[i-1])
        {
            count+=(nums[i-1]-nums[i])+1; // atleast nums[i] same as nums[i-1]
             nums[i]=nums[i-1]+1;
        }
    }
    reutrn count;
    */
}