// Task: https://leetcode.com/problems/majority-element/?envType=daily-question&envId=2024-02-12

// O(n) time, O(n) space:
#include<iostream>
#include<vector>
#include<unordered_map>

int majorityElement(vector<int>& nums) {
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
