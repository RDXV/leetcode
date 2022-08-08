// https:leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
#include <iostream>
#include <vector>
#include <map>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> in, out;
    // unordered_map<int, int> nmap;
    map<int, int> nmap;
    int input;
    while (cin >> input)
        in.push_back(input);
    for (auto i : in)
    {
        nmap[i]++;
    }
    // for (auto i : nmap)
    // {
    //     cout << i.first << " " << i.second << "\n";
    // }
    int sum = 0;
    for (int i = 0; i < in.size(); i++)
    {
        for (auto j : nmap)
        {
            if (in[i] > j.first)
            {
                sum += j.second;
            }
        }
        out.push_back(sum);
        sum = 0;
    }
    for (auto i : out)
    {
        cout << i << " ";
    }
}