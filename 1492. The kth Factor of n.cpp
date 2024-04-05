// Task: https://leetcode.com/problems/the-kth-factor-of-n/description/?envType=study-plan-v2&envId=amazon-spring-23-high-frequency

#include <iostream>

int kthFactor(int n, int k) {
    for (int i = 1; i < n + 1; i++){
        if(n % i == 0){
            k--;
        }
        if(k == 0){
            return i;
        }
    }
    return -1;
}

int main() {
    // Example 1:
    std::cout << kthFactor(12, 3) << "\n"; 
    
    // Example 2:
    std::cout << kthFactor(7, 2) << "\n";

    // Example 3:
    std::cout << kthFactor(4, 4) << "\n";
    
    return 0;
}
