// Task: https://leetcode.com/problems/product-of-array-except-self/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<vector>

// O(n^2) for time O(n) for space
std::vector<int> productExceptSelf(std::vector<int>& nums) {
	std::ios::sync_with_stdio(false);
	unsigned size = nums.size();
	std::vector<int> toReturn(size);
	int product = 1;
	for (size_t i = 0; i < size; i++) {
		for (size_t j = 0; j < size; j++) {
			if (i != j) {
				product *= nums[j];
			}
		}
		toReturn[i] = product;
		product = 1;
	}
	return toReturn;
}

// O(n) for time O(1) for space:
std::vector<int> productExceptSelf(std::vector<int>& nums) {
	std::ios::sync_with_stdio(false);
	unsigned size = nums.size();
	int totalProduct = 1;
	unsigned zeros = 0;
	for (size_t i = 0; i < size; i++) {
		if (nums[i] == 0) {
			++zeros;
			continue;
		}
		totalProduct *= nums[i];
	}

	if (zeros > 1) {
		for (size_t i = 0; i < size; i++) {
			nums[i] = 0;
		}
		return nums;
	}

	if (zeros == 1) {
		for (size_t i = 0; i < size; i++) {
			if (nums[i] == 0) {
				nums[i] = totalProduct;
			}
			else {
				nums[i] = 0;
			}
		}
		return nums;
	}

	for (size_t i = 0; i < size; i++) {
		nums[i] = totalProduct / nums[i];
	}

	return nums;
}


void printVec(const std::vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << "\n";
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 1, 2, 3, 4 };
	std::vector<int> vec2 = productExceptSelf(vec1);
	printVec(vec2);

	// Example 2:
	std::vector<int> vec3 = { -1, 1, 0, -3, 3 };
	std::vector<int> vec4 = productExceptSelf(vec3);
	printVec(vec4);

	return 0;
}
