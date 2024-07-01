// Task : https://leetcode.com/problems/three-consecutive-odds/description/?envType=daily-question&envId=2024-07-01

#include <iostream>
#include <vector>

bool threeConsecutiveOdds(std::vector<int>& arr) {
	for (size_t i = 1; i < arr.size() - 1; i++) {
		if (arr[i - 1] % 2 == 1 && arr[i] % 2 == 1 && arr[i + 1] % 2 == 1) {
			return true;
		}
	}
	return false;
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 2, 6, 4, 1 };
	std::cout << threeConsecutiveOdds(vec1) << '\n';

	// Example 1:
	std::vector<int> vec2 = { 1, 2, 34, 3, 4, 5, 7, 23, 12 };
	std::cout << threeConsecutiveOdds(vec2) << '\n';

	return 0;
}
