#include <iostream>
#include <vector>

long long getDescentPeriods(std::vector<int>& prices) {
    long long res = 1;
    long long cnt = 1;

    for (int i = 0; i < prices.size() - 1; i++) {
        if (prices[i] == prices[i + 1] + 1){
            ++cnt;
        } else {
            cnt = 1;
        }
        res += cnt;
    }
    return res;
}

int main() {
    // Example 1:
    std::vector<int> vec1 = { 3, 2, 1, 4 };
    std::cout << getDescentPeriods(vec1) << '\n';

    // Example 2:
    std::vector<int> vec2 = { 8, 6, 7, 7 };
    std::cout << getDescentPeriods(vec2) << '\n';

    // Example 3:
    std::vector<int> vec3 = { 1 };
    std::cout << getDescentPeriods(vec3) << '\n';    
} 
