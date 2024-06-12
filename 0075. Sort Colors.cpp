// Task : https://leetcode.com/problems/sort-colors/description/?envType=daily-question&envId=2024-06-12

#include <iostream>
#include <vector>

void sortColors(std::vector<int>& nums) {
    int low = 0;
    int mid = 0;
    int high = nums.size() - 1;

    while(mid <= high) {
        if (nums[mid] == 0) {
            std::swap(nums[low], nums[mid]);
            low++;
            mid++;
        }
        else if (nums[mid] == 1) {
            mid++;
        }
        else {
            std::swap(nums[mid], nums[high]);
            high--;
        }
    }
}

void printVec(const std::vectro<int>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << " ";
    }
    stc::cout << '\n';
}

int main() {
    // Example 1:
    std::vector<int> vec1 = { 2, 0, 2, 1, 1, 0 };    
    sortColors(vec1);
    printVec(vec1);
    
    // Example 2:
    std::vector<int> vec2 = { 2, 0, 1 };    
    sortColors(vec2);
    printVec(vec2);
    
    return 0;
}
