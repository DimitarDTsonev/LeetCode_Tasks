// Task: https://leetcode.com/problems/sqrtx/description/

#include <iostream>

int mySqrt(int x) {
    if (x == 0 || x == 1) {
        return x;
    }
    long long left = 1;
    long long right = x;
    long long res = 0;
    long long mid = 0;
    while (left <= right) {
        mid = left + (right - left) / 2;
        if (mid * mid == x) {
            return mid;
        }
        if (mid * mid < x) {
            left = mid + 1;
            res = mid;
        } else {
        right = mid - 1;
        }
    }
    return res;
}

int main() {
    // Example 1:
    std::cout << mySqrt(2) << '\n';
    
    // Example 2:
    std::cout << mySqrt(8) << '\n';
    
    return 0;
}
