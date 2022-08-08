// https://leetcode.com/problems/sum-of-unique-elements/
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int sum = 0;
    vector<int> in;
    unordered_map<int, int> nmap;
    int input;
    while (cin >> input)
        in.push_back(input);
    for (auto i : in)
    {
        nmap[i]++;
    }
    for (auto i : nmap)
    {
        if (i.second == 1) // if occurence is 1
        {
            sum += i.first; // add the numbers
        }
    }
    cout << "sum is " << sum;
}