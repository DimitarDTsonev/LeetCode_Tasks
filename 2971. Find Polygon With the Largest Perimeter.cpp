// Task: https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/description/?envType=daily-question&envId=2024-02-15

#include<iostream>
#include<vector>
#include<algorithm>

long long largestPerimeter(std::vector<int>& nums) {
	std::ios::sync_with_stdio(false);
	long long perimeter = -1, sum = 0;
	sort(nums.begin(), nums.end());
	
	for (size_t i = 0; i < nums.size(); i++) {
		if (nums[i] < sum) {
			perimeter = nums[i] + sum;
		}
		sum += nums[i];
	}

	return perimeter;
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 5, 5 ,5 };
	std::cout << largestPerimeter(vec1) << "\n";
	
	// Example 2:
	std::vector<int> vec2 = { 1, 12, 1, 2, 5, 50, 3 };
	std::cout << largestPerimeter(vec2) << "\n";

	// Example 3:
	std::vector<int> vec3 = { 5, 5, 50 };
	std::cout << largestPerimeter(vec3) << "\n";

	return 0;
}
