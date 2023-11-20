#include<iostream>

int solve(int n, int k){
    if(n == 1){
        return 0;
    }
    return (solve(n - 1, k) + k) % n;
}

int findTheWinner(int n, int k) {
    int toReturn = solve(n, k) + 1;
    return toReturn;
}

int main() {
    // Example 1:
    std::cout << findTheWinner(5, 2) << std::endl;
    
    // Example 2:
    std::cout << findTheWinner(6, 5) << std::endl;
    
    return 0;
}