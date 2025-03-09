// Task : https://leetcode.com/problems/alternating-groups-ii/description/?envType=daily-question&envId=2025-03-09

#include <iostream>
#include <vector>

int numberOfAlternatingGroups(std::vector<int>& colors, int k) {
    int alternating = 0;
    int size = colors.size();
    int left = 0;
        
    for (int right = 0; right < size + k - 1; ++right) {
        if (right > 0 && colors[right % size] == colors[(right - 1) % size]) {
            left = right;  
        }
            
        if (right - left + 1 >= k) {
            ++alternating;  
        }
    }

    return alternating;
}

int main() {
    // Example 1:
    std::vector<int> vec1 = { 0, 1, 0, 1, 0 };
    std::cout << numberOfAlternatingGroups(vec1, 3) << std::endl;
    
    // Example 2:
    std::vector<int> vec2 = { 0, 1, 0, 0, 1, 0, 1 };
    std::cout << numberOfAlternatingGroups(vec3, 6) << std::endl;
    
    // Example 3:
    std::vector<int> vec3 = { 1, 1, 0, 1 };
    std::cout << numberOfAlternatingGroups(vec3, 4) << std::endl;
    
    return 0;
}
