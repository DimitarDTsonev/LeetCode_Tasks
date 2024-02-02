// Task: https://leetcode.com/problems/sequential-digits/description/?envType=daily-question&envId=2024-02-02
#include<algorithm>

#include<iostream>

#include<vector>


std::vector<int> sequentialDigits(int low, int high) {
	std::vector<int> vec;
	
	for (size_t i = 1; i < 10; i++) {
		int num = i;
		int nextDigit = i + 1;

		while (num <= high && nextDigit <= 9) {
			num = num * 10 + nextDigit;
			if (low <= num && num <= high) {
				vec.push_back(num);
			}
			++nextDigit;
		}
	}

	std::sort(vec.begin(), vec.end());

	return vec;
}

void printVec(const std::vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	// Example 1:
	std::vector<int> vec = sequentialDigits(121, 300);
	printVec(vec);

	// Example 2:
	std::vector<int> vec1 = sequentialDigits(1011, 13000);
	printVec(vec1);

	return 0;
}
