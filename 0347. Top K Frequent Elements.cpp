// Task: https://leetcode.com/problems/top-k-frequent-elements/description/

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

std::vector<int> topKFrequent(std::vector<int>& nums, int k) {
    std::unordered_map<int, int> map;
    std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, std::greater<std::vector<int>>> pq;
    std::vector<int> res;

    for (int a : nums) {
        map[a]++;
    }

    for (auto& a : map) {
        pq.push({ a.second, a.first });
        if (pq.size() > k) pq.pop();
    }

    while (!pq.empty()) {
        res.push_back(pq.top()[1]);
        pq.pop();
    }
    
    return res;
}

void printVec(const std::vector<int>& vec) {
    for (size_t i = 0; i < vec.size(); i++){
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

int main() {
    // Example 1:
    std::vector<int> vec1 = { 1, 1, 1, 2, 2, 3 };
    printVec(topKFrequent(vec1, 2));

    // Example 2:
    std::vector<int> vec2 = { 1 };
    printVec(topKFrequent(vec2, 1));

	return 0;
}
