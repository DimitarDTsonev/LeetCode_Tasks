// Task: https://leetcode.com/problems/alice-and-bob-playing-flower-game/description/

#include<iostream>

long long flowerGame(int n, int m) {
    return (long long) n * m / 2;
}

int main() {
    // Example 1:
    std::cout << flowerGame(3, 2);

    // Example 2:
    std::cout << flowerGame(1, 1);
    
    return 0;
}
