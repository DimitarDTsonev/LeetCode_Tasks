// Task: https://leetcode.com/problems/plus-one/description/

#include<iostream>
#include<vector>

std::vector<int> plusOne(std::vector<int>& digits) {
	for (int i = digits.size() - 1; i >= 0; i--) {
		if (digits[i] != 9) {
			digits[i]++;
			return digits;
		}
		digits[i] = 0;
	}
	digits.insert(digits.begin(), 1);

	return digits;
}

void printVec(const std::vector<int> vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 1, 2, 3 };
	printVec(plusOne(vec1));

	// Example 2:
	std::vector<int> vec2 = { 4, 3, 2, 1 };
	printVec(plusOne(vec2));

	// Example 3:
	std::vector<int> vec3 = { 9 };
	printVec(plusOne(vec3));

	// Example 4:
	std::vector<int> vec4 = { 9, 9 };
	printVec(plusOne(vec4));

	return 0;
}
