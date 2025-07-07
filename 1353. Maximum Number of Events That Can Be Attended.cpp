// Task : https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/description/?envType=daily-question&envId=2025-07-07

#include <iostream>
#include <vector>
#include <queue>

int maxEvents(std::vector<std::vector<int>>& events) {
    std::sort(events.begin(), events.end());

    std::priority_queue<int, std::vector<int>, greater<int>> minHeap;
    int day = 0;
    int index = 0; 
    int size = events.size();
    int res = 0;

    while (!minHeap.empty() || index < size) {
        if (minHeap.empty()) {
            day = events[index][0];
        }

        while (index < size && events[index][0] <= day) {
            minHeap.push(events[index][1]);
            ++index;
        }

        minHeap.pop();
        ++res;
        ++day;

        while(!minHeap.empty() && minHeap.top() < day) {
            minHeap.pop();
        }
    }

    return res;
}

int main() {
    // Example 1: 
    std::vector<std::vector<int>> event1 = { { 1, 2 }, { 2, 3 }, { 3, 4 } };
    std::cout << maxEvents(event1) << '\n';

     // Example 2: 
    std::vector<std::vector<int>> event2 = { { 1, 2 }, { 2, 3 }, { 3, 4 }, { 1, 2 } };
    std::cout << maxEvents(event2) << '\n';
    
    return 0;
}
