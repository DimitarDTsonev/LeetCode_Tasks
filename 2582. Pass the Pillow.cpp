// Task: https://leetcode.com/problems/pass-the-pillow/description/?envType=daily-question&envId=2024-07-06

#include <iostream>

int passThePillow(int n, int time) {
    time = time % (2 * n - 2);
    return time < n ? 1 + time : (2 * n - time - 1);
}

int main() {
    // Example 1:
    std::cout << passThePillow(4, 5) << '\n';

    // Example 2:
    std::cout << passThePillow(3, 2) << '\n';
    
    return 0;
}
