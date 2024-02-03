// Task: https://leetcode.com/problems/partition-array-for-maximum-sum/description/?envType=daily-question&envId=2024-02-03

#include<iostream>
#include<vector>

int maxSumAfterPartitioning(std::vector<int>& arr, int k) {
	int n = arr.size(), sum = 0;
	std::vector<int> vec(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		int maxA = 0, max = 0;
		
		for (int j = 1; j <= k && i - j >= 0; j++) {
			maxA = std::max(maxA, arr[i - j]); 
			max = std::max(max, vec[i - j] + j * maxA);
		}
		vec[i] = max;
	}
	return vec[n];
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 1, 15, 7, 9, 2, 5, 10 };
	std::cout << maxSumAfterPartitioning(vec1, 3) << std::endl;

	// Example 2:
	std::vector<int> vec2 = { 1, 4, 1, 5, 7, 3, 6, 1, 9, 9, 3 };
	std::cout << maxSumAfterPartitioning(vec2, 4) << std::endl;

	// Example 3:
	std::vector<int> vec3 = { 1 };
	std::cout << maxSumAfterPartitioning(vec3, 1) << std::endl;

	return 0;
}
