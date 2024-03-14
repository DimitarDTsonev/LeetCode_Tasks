// Task: https://leetcode.com/problems/binary-subarrays-with-sum/description/?envType=daily-question&envId=2024-03-14

#include<iostream>
#include<vector>
#include<unordered_map>

int numSubarraysWithSum(std::vector<int>& nums, int goal) {
	int cnt = 0;
	int prefix = 0;
	std::unordered_map<int, int> map{ { 0, 1 } };

	for (const int iter : nums) {
		prefix += iter;
		const auto it = map.find(prefix - goal);
		if (it != map.end()) {
			cnt += it->second;
		}
		++map[prefix];
	}

	return cnt;
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 1, 0, 1, 0, 1 };
	std::cout << numSubarraysWithSum(vec1, 2) << "\n";
	
	// Example 2:
	std::vector<int> vec2 = { 0, 0, 0, 0, 0 };
	std::cout << numSubarraysWithSum(vec2, 0) << "\n";

	return 0;
}
