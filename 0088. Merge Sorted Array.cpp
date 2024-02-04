#include<iostream>
#include<vector>
#include<algorithm>

void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {	
	for (int i = 0; i < n; i++) {
		nums1[m + i] = nums2[i];
	}
	std::sort(nums1.begin(), nums1.end());
}

void printVec(const std::vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	// Example 1:
	std::vector<int> vec1(6, 0);            // Note that the tests in the LeetCode system are with already allocated memory. For that I use this!: 
	vec1[0] = 1;
	vec1[1] = 2;
	vec1[2] = 3;
	std::vector<int> vec2 = { 2, 5, 6 };

	merge(vec1, 3, vec2, 3);
	printVec(vec1);

	// Example 2:
	std::vector<int> vec3 = { 1 };
	std::vector<int> vec4 = {  };

	merge(vec3, 1, vec4, 0);
	printVec(vec3);

	// Example 3:
	std::vector<int> vec5(1);
	std::vector<int> vec6 = { 1 };

	merge(vec5, 0, vec6, 1);
	printVec(vec5);

	return 0;
}
