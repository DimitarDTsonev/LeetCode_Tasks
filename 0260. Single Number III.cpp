// Task : https://leetcode.com/problems/single-number-iii/description/?envType=daily-question&envId=2024-05-31

#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> singleNumber(std::vector<int>& nums) {
	std::unordered_map<int, int> map(nums.size());
	std::vector<int> res;

	for (auto& n : nums) {
		map[n]++;
	}

	for (auto& n : map) {
		if (n.second == 1) {
			res.push_back(n.first);
		}
	}
	return res;
}

void printVec(const std::vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << '\n';
}

int main() {
	// Examolpe 1:
	std::vector<int> vec1 = { 1, 2, 1, 3, 2, 5 };
	printVec(singleNumber(vec1));

	// Examolpe 2:
	std::vector<int> vec2 = { -1, 0 };
	printVec(singleNumber(vec2));

	// Examolpe 3:
	std::vector<int> vec3 = { 0, 1 };
	printVec(singleNumber(vec3));

	return 0;
}
