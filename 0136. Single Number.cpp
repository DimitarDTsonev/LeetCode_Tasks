// Task : https://leetcode.com/problems/single-number/description/

#include <iostream>
#include <vector>

int singleNumber(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int num = 0;
    for (auto x : nums){
        num ^= x;
    }
    return num;
}

main() {
    // Example 1: 
    std::vector<int> vec1 = { 2, 2, 1 };
    std::cout << singleNumber(vec1) << '\n';

     // Example 2: 
    std::vector<int> vec2 = { 4, 1, 2, 1, 2 };
    std::cout << singleNumber(vec2) << '\n';

     // Example 3: 
    std::vector<int> vec3 = { 1 };
    std::cout << singleNumber(vec3) << '\n';

    return 0;
}
