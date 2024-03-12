// Task: https://leetcode.com/problems/binary-search/description/?envType=study-plan-v2&envId=binary-search

#include<iostream>
#include<vector>

int search(std::vector<int>& nums, int target) {
    // For speed:
    std::ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    

    int low = 0;
    int high = nums.size();
    int mid = 0;

    while (low <= high) {
        mid = low + (high - low) / 2;
        
        if (nums[mid] == target) {
            return mid;
        }
        if (nums[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    // Example 1:
    std::vector<int> vec1 = { -1 , 0, 3, 5, 9, 12 };
    std::cout << search(vec1, 9) << "\n";
    
    // Example 2:
    std::cout << search(vec1, 2) << "\n";

    return 0;
}
