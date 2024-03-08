// Task: https://leetcode.com/problems/count-elements-with-maximum-frequency/description/?envType=daily-question&envId=2024-03-08

#include <iostream>
#include <vector>
#include <map>

int maxFrequencyElements(std::vector<int>& nums) {
	std::map<int, int> map;
	int maxCount = 0;
	int max = INT_MIN;

	for (int i = 0; i < nums.size(); i++) {
		map[nums[i]]++;

		if (map[nums[i]] > max) {
			max = map[nums[i]];
			maxCount = 0;
		}

		if (map[nums[i]] == max) {
			maxCount++;
		}
	}

	return max * maxCount;
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 1, 2, 2, 3, 1, 4 };
	std::cout << maxFrequencyElements(vec1) << "\n";

	// Example 2:
	std::vector<int> vec2 = { 1, 2, 3, 4, 5 };
	std::cout << maxFrequencyElements(vec2) << "\n";

	return 0;
}
