// Task : https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

#include <iostream>
#include <vector>

int maxProfit(vector<int>& prices) {
    std::ios_base::sync_with_stdio(false);
    int profit = 0;
    int buy = prices[0];
    for (size_t i = 1; i < prices.size(); i++) {
        if (prices[i] < buy) {
            buy = prices[i];
        } else if (prices[i] - buy > profit) {
            profit = prices[i] - buy;
        }
    }
    return profit;
}

int main() {
    // Example 1:
    std::vector<int> vec1 = { 7, 1, 5, 3, 6, 4 };
    std::cout << maxProfit(vec1) << '\n';

    // Example 2:
    std::vector<int> vec2 = { 7, 6, 4, 3, 1 };
    std::cout << maxProfit(vec2) << '\n';
    
    return 0;
}
