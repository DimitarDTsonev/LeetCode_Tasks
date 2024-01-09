// Problem : https://leetcode.com/problems/running-sum-of-1d-array/description/
// Time complexity: O(n), Space complexity: O(1).
// Beats 100.0% for time and 90% for memory:
std::vector<int> runningSum(std::vector<int>& nums) {
    for (int i = 1; i < nums.size(); i++) {
        nums[i] = nums[i - 1] + nums[i];
    }
    return nums;
}

void printVector(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
}

int main() {
    // Example 1:
	std::vector<int> vec = { 1, 2, 3, 4 };
	std::vector<int> result =  runningSum(vec);
    printVector(result);

    // Example 2:
    std::vector<int> vec2 = { 1, 1, 1, 1, 1   };
    std::vector<int> result2 = runningSum(vec);
    printVector(result);

    // Example 3:
    std::vector<int> vec3 = { 3, 1, 2, 10, 1 };
    std::vector<int> result3 = runningSum(vec);
    printVector(result3);

	return 0;
}
