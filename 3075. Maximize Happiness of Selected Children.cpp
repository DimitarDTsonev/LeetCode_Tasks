// Task : https://leetcode.com/problems/maximize-happiness-of-selected-children/description/?envType=daily-question&envId=2024-05-09

#include <iostream>
#include <vector>
#include <algorithm>

long long maximumHappinessSum(std::vector<int>& happiness, int k) {
	sort(happiness.begin(), happiness.end(), std::greater<int>());
	int i = 0;
	long long res = 0;

	while (k--) {
		happiness[i] = std::max(happiness[i] - i, 0);
		res += happiness[i++];
	}
	return res;
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 1, 2, 3 };
	std::cout << maximumHappinessSum(vec1, 2) << '\n';

	// Example 2: 
	std::vector<int> vec2 = { 1, 1, 1, 1 };
	std::cout << maximumHappinessSum(vec2, 2) << '/n';

	// Example 3: 
	std::vector<int> vec3 = { 2, 3, 4, 5 };
	std::cout << maximumHappinessSum(vec2, 1) << '/n';

	return 0;
}
