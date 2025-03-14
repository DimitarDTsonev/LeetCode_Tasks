// Task : https://leetcode.com/problems/zero-array-transformation-ii/description/?envType=daily-question&envId=2025-03-13

#include <iostream>
#include <vector>

int minZeroArray(std::vector<int>& nums, std::vector<std::vector<int>>& queries) {
    int sizeN = nums.size();
    int sizeQ = queries.size();
    int sum = 0;
    int k = 0;
    std::vector<int> diffArr(sizeN + 1);
    int right = 0;
    int left = 0;
    int value = 0;
    
    for (int i = 0; i < sizeN; i++) {
        while (sum + diffArr[i] < nums[i]) {
            k++;

            if (k > sizeQ) {
                return -1;
            }

            left = queries[k - 1][0];
            right = queries[k - 1][1];
            value = queries[k - 1][2];

            if (right >= i) {
                diffArr[std::max(left, i)] += value;

                if (right + 1 < diffArr.size()) {
                    diffArr[right + 1] -= value;
                }
            }
        }
        sum += diffArr[i];
    }

    return k;
}

int main() {
	 // Example 1:
	std::vector<int> nums1 = { 2, 0, 2 };
	std::vector<std::vector<int>> queries1 = { { 0, 2, 1 }, { 0, 2, 1 }, { 1, 1, 3 } };
	std::cout << minZeroArray(nums1, queries1) << '\n';

	 // Example 2:
	std::vector<int> nums2 = { 4, 3, 2, 1 };
	std::vector<std::vector<int>> queries2 = { { 1, 3, 2 }, { 0, 2, 1 } };
	std::cout << minZeroArray(nums2, queries2) << '\n';

	// Example 3:
	std::vector<int> nums3 = { 10 };
	std::vector<std::vector<int>> queries3 = { { 0, 0, 5 }, { 0, 0, 3 }, { 0, 0, 2 } };
	std::cout << minZeroArray(nums3, queries3) << '\n';

	return 0;
}
