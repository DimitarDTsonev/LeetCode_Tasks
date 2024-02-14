// Task: https://leetcode.com/problems/can-place-flowers/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>

bool canPlaceFlowers(std::vector<int>& flowerbed, int n) {
	if (n == 0) {
		return true;
	}

	int i, size = flowerbed.size();
	
	for (i = 0; i < size; ++i) {
		if (flowerbed[i] == 1) {
			continue;
		}
		else if ((i == 0 && size == 1) ||
			(i == 0 && i + 1 < size && flowerbed[i + 1] == 0) ||
			(i == size - 1 && flowerbed[i - 1] == 0) ||
			(i > 0 && flowerbed[i - 1] == 0 && flowerbed[i + 1] == 0)) {
			flowerbed[i] = 1;
			--n;
		}

		if (n == 0) {
			return true;
		}
	}
	return false;
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 1, 0, 0, 0, 1 };
	std::cout << canPlaceFlowers(vec1, 1) << "\n";

	// Example 2:
	std::cout << canPlaceFlowers(vec1, 2) << "\n";

	// Example 3:
	std::vector<int> vec3 = { 1, 0, 0, 0, 0, 1 };
	std::cout << canPlaceFlowers(vec3, 2) << "\n";

	// Example 3:
	std::vector<int> vec4 = { 0 };
	std::cout << canPlaceFlowers(vec4, 1) << "\n";

	return 0;
}
