// Task: https://leetcode.com/problems/remove-element/description/

#include<iostream>
#include<vector>

int removeElement(std::vector<int>& nums, int val) {
    int j = 0; 

    for (size_t i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[j++] = nums[i];
        }
    }

    return j;
}

int main() {
    // Example 1:
    std::vector<int> vec1 = { 3, 2, 2, 3 };
    std::cout << removeElement(vec1, 3) << "\n";

    std::vector<int> vec2 = { 0, 1, 2, 2, 3, 0, 4, 2 };
    std::cout << removeElement(vec2, 2) << "\n";

	return 0;
}
