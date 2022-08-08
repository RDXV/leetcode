// https://leetcode.com/problems/jewels-and-stones/
#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    unordered_map<char, int> nmap;
    // char not string as we have to take individual elements to match
    string stones, jewels;
    cin >> stones;
    if (stones.length() == 0)
    {
        cout << 0;
        exit(0);
    }
    for (auto i : stones)
    {
        nmap[i]++;
        // if str=mmM then m=2,M=1 where i=m for first case
    }
    cin >> jewels;
    if (jewels.length() == 0)
    {
        cout << 0;
        exit(0);
    }
    int sum = 0;
    for (int i = 0; i < jewels.length(); i++)
    {
        for (auto j : nmap)
        {
            if (jewels[i] == j.first) // if character matches the mapped character, add to sum
            {
                sum += j.second;
            }
        }
    }
    cout << "sum is " << sum;
}