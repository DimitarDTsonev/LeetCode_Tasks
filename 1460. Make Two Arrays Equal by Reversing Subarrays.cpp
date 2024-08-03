// Task : https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays/description/?envType=daily-question&envId=2024-08-03

#include <iostream>
#include <vector>

bool canBeEqual(std::vector<int>& target, std::vector<int>& arr) {
    std::vector<int> vec1(1001);
    std::vector<int> vec2(1001);

    for (int& v : target) {
        ++vec1[v];
    }

    for (int& v : arr) {
        ++vec2[v];
    }

    return vec1 == vec2;
}

int main() {
    //Example 1: 
    std::vector<int> vec1 = { 1, 2, 3, 4 };
    std::vector<int> vec2 = { 2, 4, 1, 3 };
    std::cout << canBeEqual(vec1, vec2) << '\n';

    //Example 2: 
    std::vector<int> vec3 = { 7 };
    std::vector<int> vec4 = { 7 };
    std::cout << canBeEqual(vec3, vec4) << '\n';

    //Example 3: 
    std::vector<int> vec5 = { 3, 7, 9 };
    std::vector<int> vec6 = { 3, 7, 11 };
    std::cout << canBeEqual(vec5, vec6) << '\n';
    
    return 0;
}
