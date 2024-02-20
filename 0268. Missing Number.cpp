// Task: https://leetcode.com/problems/missing-number/description/

#include<iostream>
#include<vector>
#include<numeric>	// using std::accumulate that get the sum of the elements of vector using iterators

// The intuitive solution using sums and for - loop that takes:
// O(n) -> for time 
// O(1) -> for space
int missingNumber(std::vector<int>& nums) {
	std::ios::sync_with_stdio(false);

	int size = nums.size();
	int sum = 0;
	int allSum = (size * (size + 1)) / 2;

	for (size_t i = 0; i < nums.size(); i++) {
		sum += nums[i];
	}

	return allSum - sum;
}

// Optimise solution, beats 100%
int missingNumber(std::vector<int>& nums) {
	std::ios::sync_with_stdio(false);
	int size = nums.size();
	int allSum = (size * (size + 1)) / 2;

	return allSum - std::accumulate(nums.begin(), nums.end(), 0);
}

int main() {
	// Example 1; 
	std::vector<int> vec1 = { 3, 0, 1 };
	std::cout << missingNumber(vec1) << "\n";

	// Example 2:
	std::vector<int> vec2 = { 0, 1 };
	std::cout << missingNumber(vec2) << "\n";

	// Example 3: 
	std::vector<int> vec3 = { 9,6,4,2,3,5,7,0,1 };
	std::cout << missingNumber(vec3) << "\n";

	return 0;
}
