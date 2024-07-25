// Task: https://leetcode.com/problems/two-sum/description/

#include<iostream>
#include<vector>
#include<unordered_map>


std::vector<int> twoSum(std::vector<int>& nums,int target){
    const size_t size = nums.size();
    std::unordered_map<int, int> map;
    
    for(int i = 0;i<size;i++){
        if(map.find(target - nums[i])!=map.end()){
            return std::vector<int>{map[target - nums[i]],i};
        }
        map[nums[i]] = i;
    }
    return {};
}


void printVec(std::vector<int>& vec){
    const size_t size = vec.size();	
    for (size_t i = 0; i < size; i++){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Test 1:
    std::vector<int> vec1 = { 2, 7, 11, 15 }, result1;
    int target1 = 9;
    result1 = twoSum(vec1, target1);
    printVec(result1);

    // Test 2:
    std::vector<int> vec2 = { 3, 2, 4 }, result2;
    int target2 = 6;
    result2 = twoSum(vec2, target2);
    printVec(result2);

    // Test 3:
    std::vector<int> vec3 = { 3, 3 }, result3;
    int target3 = 6;
    result3 = twoSum(vec3, target3);
    printVec(result3);

    return 0;
}
