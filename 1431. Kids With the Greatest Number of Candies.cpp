// Task: https://leetcode.com/problems/kids-with-the-greatest-number-of-candies/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>

std::vector<bool> kidsWithCandies(std::vector<int> candies, int extraCandies) {
	int n = candies.size();
	std::vector<bool> toReturn(n, false);

	int maxCandies = 0;

	for (size_t i = 0; i < n; i++) {
		maxCandies = std::max(maxCandies, candies[i]);
	}

	for (size_t i = 0; i < n; i++) {
		if (candies[i] + extraCandies >= maxCandies) {
			toReturn[i] = true;
		}
	}
	return toReturn;
}

void printVec(const std::vector<bool>& vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 2, 3, 5, 1, 3 };
	printVec(kidsWithCandies(vec1, 3));

	// Example 2:
	std::vector<int> vec2 = { 4, 2, 1, 1, 2 };
	printVec(kidsWithCandies(vec2, 1));

	// Example 3:
	std::vector<int> vec3 = { 12, 1, 12 };
	printVec(kidsWithCandies(vec3, 10));

	return 0;
}
