// Task: https://leetcode.com/problems/intersection-of-two-arrays/description/?envType=daily-question&envId=2024-03-10

#include<iostream>
#include<vector>
#include<unordered_set>

std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
	std::unordered_set<int> set(nums1.begin(), nums1.end());
	std::vector<int>res;

	for (int num : nums2) {
		if (set.find(num) != set.end()) {
			res.push_back(num);
			set.erase(num);
		}
	}
	return res;
}

void printVec(const std::vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 1, 2, 2, 1 };
	std::vector<int> vec2 = { 2, 2 };
	printVec(intersection(vec1, vec2));

	// Example 2:
	std::vector<int> vec3 = { 4, 9, 5 };
	std::vector<int> vec4 = { 9, 4, 9, 8, 4 };
	printVec(intersection(vec3, vec4));

	return 0;
}
