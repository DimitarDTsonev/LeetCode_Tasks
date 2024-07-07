// Task : https://leetcode.com/problems/water-bottles/description/?envType=daily-question&envId=2024-07-07

#include <iostream>

 int numWaterBottles(int numBottles, int numExchange) {
    unsigned res = numBottles;

    while (numBottles >= numExchange) {
        res += numBottles / numExchange;
        numBottles = (numBottles / numExchange) + (numBottles % numExchange); 
    }
    return res;
}

int main() {
    // Example 1:
    std::cout << numWaterBottles(9, 3) << '\n';

     // Example 2:
    std::cout << numWaterBottles(15, 4) << '\n';
    
    return 0;
}
