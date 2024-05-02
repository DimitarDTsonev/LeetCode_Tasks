// Task : https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/description/?envType=daily-question&envId=2024-05-02

#include <iostream>
#include <vector>

 int findMaxK(vector<int>& nums) {
    int size = nums.size();
    int l = 0;
    int r = size - 1;
    sort(nums.begin(), nums.end());
    while(l < r && nums[l] != -nums[r]){
        if(-nums[l] > nums[r]){
            l++;
        }
        else{
            r--;
        }
    }
    return (l < r) ? nums[r] : -1;
}

int main(){
    // Example 1:
    std::vector<int> vec1 = { -1, 2, -3, 3 };
    std::cout << findMaxK(vec1) << '\n';

     // Example 2:
    std::vector<int> vec2 = { -1, 10, 6, 7, -7, 1 };
    std::cout << findMaxK(vec2) << '\n';

     // Example 3:
    std::vector<int> vec3 = { -10, 8, 6, 7, -2, -3 };
    std::cout << findMaxK(vec3) << '\n';
    
    return 0;
}
