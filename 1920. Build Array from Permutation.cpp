// Task : https://leetcode.com/problems/build-array-from-permutation/description/?envType=daily-question&envId=2025-05-06

#include <iostream>
#include <vector>

std::vector<int> buildArray(std::vector<int>& nums) {
    int size = nums.size();
    std::vector<int> ans(size);
    
    for (int i = 0; i < size; i++) {
        ans[i] = nums[nums[i]];
    }
    return ans;
}

void printVec(const std::vector<int>& vec) {
    for (const int& iter : vec) {
        std::cout << iter << " ";
    }
    std::cout << '\n';
}

int main() {
    // Ecample 1:
    std::vector<int> vec1 = { 0, 2, 1, 5, 3, 4 };
    std::vector<int> ans1 = buildArray(vec1);
    printVec(ans1);

    // Example 2:
    std::vector<int> vec2 = { 5, 0, 1, 2, 3, 4 };
    std::vector<int> ans2 = buildArray(vec2);
    printVec(ans2);
}
