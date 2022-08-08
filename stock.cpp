// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
#include <iostream>
#include <vector>
using namespace std;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    vector<int> prices;
    int input;
    while (cin >> input)
        prices.push_back(input);

    int profit = 0, max_profit = 0;
    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            profit = max(prices[j] - prices[i], profit);
        }
    }
    // Gives time error
    /*

     int maxPro = 0;
    int minPrice = INT_MAX;
    for(int i = 0; i < prices.size(); i++){
        minPrice = min(minPrice, prices[i]);
        maxPro = max(maxPro, prices[i] - minPrice);
        
    */
    cout << "profit is " << profit;
}