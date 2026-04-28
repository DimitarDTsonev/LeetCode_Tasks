// Task : https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/description/?envType=daily-question&envId=2026-04-28

int minOperations(vector<vector<int>>& grid, int x) {
    std::vector<int> nums;
    long long totalOperations = 0;
    
    for (auto& row : grid) {
        for (int i : row) {
            nums.push_back(i);
        }
    }
        
    std::sort(nums.begin(), nums.end());
    int target = nums[nums.size() / 2];
        
    for (int i : nums) {
        int temp = std::abs(i - target);
            
        if (temp % x != 0) {
            return -1;
        }

        totalOperations += temp / x;
    }

    return totalOperations;
}

int main() {
    // Example 1:
    std::vector<std::vector<int>> nums1 = { { 2, 4 }, { 6, 8 }};
    std::cout << minOperations(nums1, 2) << '/n';

    // Example 2:
    std::vector<std::vector<int>> nums2 = { { 1, 5 }, { 2, 3 }};
    std::cout << minOperations(nums2, 1) << '/n';

    // Example 3:
    std::vector<std::vector<int>> nums3 = { { 4, 2 }, { 3, 8 }};
    std::cout << minOperations(nums3, 2) << '/n';
}
