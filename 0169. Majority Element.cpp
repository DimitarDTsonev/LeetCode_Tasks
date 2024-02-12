// Task: https://leetcode.com/problems/majority-element/?envType=daily-question&envId=2024-02-12

// O(n) time, O(n) space:
#include<iostream>
#include<vector>
#include<unordered_map>

int majorityElement(std::vector<int>& nums) {
    std::unordered_map<int, int> map;

    for (int num : nums) {
        if (map.find(num) != map.end()) {
            ++map[num];
        } 
        else {
            map[num] = 1;
        }
    }
        
    int max = 0, toReturn = -1;
    
    for (const auto& pair : map) {
        if (pair.second > nums.size() / 2) {
            return pair.first;
        }
        if (max < pair.second) {
            max = pair.second;
            toReturn = pair.first;
        }
    }

    return toReturn;
}

// O(n) time, O(1) space:

int majorityElement(vector<int>& nums) {
    int n=nums.size();
    int count=0;
    int num=0;
    for(int i=0;i<n;i++){
        if (count==0){
            num=nums[i];
            count++;
        }
        else if(num==nums[i]){
            count++;
        }
        else{
            count--;
        }
    }
    
    return num; 
}

int main() {
    // Example 1:
    std::vector<int> vec1 = { 3, 2, 3 };
    std::cout << majorityElement(vec1) << "\n";

    // Example 2:
    std::vector<int> vec2 = { 2, 2, 1, 1, 1, 2, 2 };
    std::cout << majorityElement(vec2) << "\n";
    
    return 0;
}
