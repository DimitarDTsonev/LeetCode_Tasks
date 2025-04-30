#include <iostream>
#include <vector>

int findNumbers(std::vector<int>& nums) {
    int counter = 0;

    for(const int& num : nums) {
        if (num < 10 || (num > 99 && num < 999) || (num > 9999 && num < 100000)) {
            continue;
        }
        counter++;
    }

    return counter;
}

int main() {
    // Example 1:
    std::vector<int> vec1 = { 12, 345, 2, 6, 7896 };
    std::cout << findNumber(vec1) << '\n';

    // Example 2:
    std::vector<int> vec2 = { 555, 901, 482, 1771 }; 
    std::cout << findNumber(vec2) << '\n';

    return 0;
}
