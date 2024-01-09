// Task: https://leetcode.com/problems/richest-customer-wealth/

#include<iostream>
#include<vector>

// Beats 100.0% for time and 50% for space:

int maximumWealth(std::vector<std::vector<int>>& accounts) {
	int maxWealth = 0, width = accounts[0].size();

	for (size_t i = 0; i < accounts.size(); i++) {
		int currentWealth = 0;
		for (size_t j = 0; j < width; j++) {
			currentWealth += accounts[i][j];
		}
		maxWealth = std::max(maxWealth, currentWealth);
	}

	return maxWealth;
}

// Beats 90% for time and 90% for space:
int maximumWealth(std::vector<std::vector<int>>& accounts) {
	int maxWealth = 0;
	int currentWealth = 0;
	int width = accounts[0].size();
	for (size_t i = 0; i < accounts.size(); i++) {
		for (size_t j = 0; j < width; j++) {
			currentWealth += accounts[i][j];
		}
		if (maxWealth < currentWealth) {
			maxWealth = currentWealth;
		}
		currentWealth = 0;
	}

	return maxWealth;
}

int main() {
	// Example 1:
	std::vector<std::vector<int>> acc1 = { { 1, 2, 3 }, { 3, 2, 1 } };
	std::cout << maximumWealth(acc1) << std::endl;

	// Example 2:
	std::vector<std::vector<int>> acc2 = { { 1, 5 }, { 7, 3 }, { 3,5 } };
	std::cout << maximumWealth(acc2) << std::endl;

	// Example 2:
	std::vector<std::vector<int>> acc3 = { { 2, 8, 7 }, { 7, 1, 3 }, { 1, 9, 5 } };
	std::cout << maximumWealth(acc3) << std::endl;

	return 0;
}
