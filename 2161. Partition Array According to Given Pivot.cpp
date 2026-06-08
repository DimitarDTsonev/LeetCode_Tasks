// Task : https://leetcode.com/problems/partition-array-according-to-given-pivot/description/?envType=daily-question&envId=2026-06-08
#include <iostream>
#include <vector>

std::vector<int> pivotArray(std::vector<int>& nums, int pivot) {
    int size = nums.size();
    std::vector<int> res(size);
    int i = 0;
    int j = size - 1; 
    int left = 0;
    int right = j;
        
    while (i < size) {
        if (nums[i] < pivot) {
            res[left++] = nums[i];
        }
            
        if (nums[j] > pivot) {
            res[right--] = nums[j];
        }

        i++;
        j--;
    }
        
    while (left <= right) {
        res[left++] = pivot;
    }
        
    return res;
}

void printVec(const std::vector<int> vec) {
    for (int iter : vec) {
        std::cout << iter << " ";    
    }
    std::cout << '\n';
}

int main() {
    // Example 1:
    std::vector<int> vec1 = { 9, 12, 5, 10, 14, 3, 10 };
    std::vector<int> res1 = pivotArray(vec1, 10);
    printVec(res1);
    
    // Example 2:
    std::vector<int> vec2 = { -3, 4, 3, 2 };
    std::vector<int> res2 = pivotArray(vec2, 2);
    printVec(res2);
}
