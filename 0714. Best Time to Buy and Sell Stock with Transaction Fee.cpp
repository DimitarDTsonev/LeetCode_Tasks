// Task: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/description/

#include<iostream>
#include<vector>

int maxProfit(std::vector<int>& prices, int fee) {
	int buy = INT_MIN, sell = 0;

	for (int price : prices) {
		buy = std::max(buy, sell - price);
		sell = std::max(sell, buy + price - fee);
	}

	return sell;
}

int main() {
	std::vector<int> v{ 1, 3, 2, 8, 4, 9 };
	int fee = 2;

	std::cout << maxProfit(v, fee);

	return 0;
}
