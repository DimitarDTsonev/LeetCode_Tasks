// Task: https://leetcode.com/problems/set-mismatch/description/?envType=daily-question&envId=2024-01-22

#include<iostream>
#include<vector>

std::vector<int> findErrorNums(std::vector<int>& nums) {
    int n = nums.size(), missing = 0 , duplicate = 0;
    std::vector<int> v(n+1,0);
    
    for(int i = 0; i < n ; i++){
        v[nums[i]]++;
    }
    
    for(int i = 1; i < v.size(); i++){
        if(v[i] == 2)duplicate = i;
        if(v[i] == 0)missing = i;
    }
    
    return { duplicate, missing };
}

void printVec(const std::vector<int>& vec){
    for(size_t i = 0; i < vec.size(); i++){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Example 1:
    std::vector<int> vec1 = { 1, 2, 2, 4 };
    std::vector<int> vec2 = findErrorNums(vec1);
    printVec(vec2);

    // Example 2:
    std::vector<int> vec3 = { 1, 1 };
    std::vector<int> vec4 = findErrorNums(vec3);
    printVec(vec4);
    
    return 0;
}
