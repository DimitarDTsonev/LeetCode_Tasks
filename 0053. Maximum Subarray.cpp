#include<iostream>
#include<vector>

int maxSubArray(vector<int>& nums) {
    int best = nums[0], sum = 0;
    for (int k = 0; k < nums.size(); k++) {
        sum = max(nums[k], sum + nums[k]);
        best = max(best, sum);
    }
    return best;
}

int main(){
    // Test 1: --> 6
    std::vector<int> v1 = { -2, 1, -3, 4, -1, 2, 1, -5, 4 }; 
    std::cout << maxSubArray(v1) << std::endl;
    
    // Test 1: --> 1
    std::vector<int> v2 = { 1 }; 
    std::cout << maxSubArray(v2) << std::endl;

    // Test 3: --> 23
    std::vector<int> v3 = { 5, 4, -1, 7, 8 }; 
    std::cout << maxSubArray(v3) << std::endl;

    return 0;
}
