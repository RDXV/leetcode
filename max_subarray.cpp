// https://leetcode.com/problems/maximum-subarray/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> a;
    int input;
    while (cin >> input)
        a.push_back(input);
    int sum = a[0], max_sum = a[0];
    for (int i = 0; i < a.size(); i++)
    {
        sum = max(sum + a[i], a[i]);
        // we should not do if(sum<0)sum=0 as it will not consider when all numbers negative
        cout << "sum is " << sum << "\n";
        max_sum = max(max_sum, sum);
    }
    cout << max_sum;
}