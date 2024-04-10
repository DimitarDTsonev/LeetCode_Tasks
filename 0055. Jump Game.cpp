// Task : https://leetcode.com/problems/jump-game/description/

#include <iostream>
#include <vector>

bool canJump(std::vector<int>& nums) {
	int size = nums.size() - 1;
	for (int i = nums.size() - 2; i >= 0; i--) {
		if (nums[i] + i >= size) {
			size = i;
		}
	}
	return size == 0;
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 2, 3, 1, 1, 4 };
	std::cout << canJump(vec1) << '\n';

	// Example 2:
	std::vector<int> vec2 = { 3, 2, 1, 0, 4 };
	std::cout << canJump(vec2) << '\n';

	// Example 3:
	std::vector<int> vec3 = { 0 };
	std::cout << canJump(vec3) << '\n';

	// Example 4:
	std::vector<int> vec4 = { 0 , 2, 3 };
	std::cout << canJump(vec4) << '\n';

	return 0;
}
