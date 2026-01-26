// Task : https://leetcode.com/problems/minimum-absolute-difference/description/?envType=daily-question&envId=2026-01-26

#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

 std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr) {
    std::vector<std::vector<int>> res;
    std::sort(arr.begin(), arr.end());
    int minDiff = INT_MAX;
    int size = arr.size();
    int currAbs = 0;

    for(int i = 1; i < size; i++) {
        currAbs = std::abs(arr[i] - arr[i - 1]);
            
        if (currAbs < minDiff) {
            minDiff = currAbs;
            res.clear();
            res.push_back({ arr[i - 1], arr[i] });
        } else if (currAbs == minDiff) {
            res.push_back({ arr[i - 1], arr[i] });
        }
    }

    return res;
}

void printMatrix(const std::vector<std::vector<int>>& vec) {
    for (int i = 0; i < vec.size(); i++) {
        for (int j = 0; j < vec[i].size(); j++) {
            std::cout << vec[i][j] << " "; 
        }
    }
    std::cout << '\n';
}

int main() {
    // Example 1:
    std::vector<int> vec1 = { 1, 2, 3, 4 };
    std::vector<std::vector<int>> res1 = minimumAbsDifference(vec1);
    printMatrix(res1);
    
    // Example 2:
    std::vector<int> vec2 = { 1, 3, 6, 10, 15 };
    std::vector<std::vector<int>> res2 = minimumAbsDifference(vec2);
    printMatrix(res2);
    
    // Example 3:
    std::vector<int> vec3 = { 3, 8, -10, 23, 19, -4, -14, 27 };
    std::vector<std::vector<int>> res3 = minimumAbsDifference(vec3);
    printMatrix(res3);

    return 0;  
}
