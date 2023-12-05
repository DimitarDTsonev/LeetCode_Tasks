#include<iostream>
#include<vector>

// Bacis recursive approach:
unsigned long long fib1(int n) {
    unsigned long long result = 0;
    if(n == 0){
        return 0;
    }
    else if(n == 1){
        return 1;
    }
    else {
        result = fib1(n - 1) + fib1(n - 2);
        return result;
    }
}

// Memoized approach:
unsigned long long fib2(int n, std::vector<unsigned long long>& memo){
    unsigned long long result = 0;
    if(n == 0){
        return 0;
    }
    if(memo[n] != 0){
        return memo[n];
    }
    
    memo[n] = fib2(n - 1, memo) + fib2(n - 2, memo);
    return memo[n]; 
}


// Bottom-up approach:
unsigned long long fib3(int n){
    if(n == 0){
        return 0;
    }
    if(n == 1){
        return 1;
    }
    std::vector<unsigned long long> memo(n + 1);
    memo[0] = 0;
    memo[1] = 1;

    for (size_t i = 2; i < n + 1; i++) {
        memo[i] = memo[i - 1] + memo[i - 2]; 
    }
    
    return memo[n];
}

int main() {
    int n = 50;
    if(n == 0){
        std::vector<unsigned long long> memo(n + 1);
        memo[0] = 0;
        std::cout << fib2(n, memo) << std::endl;
    }
    else{
    std::vector<unsigned long long> memo(n + 1);
        memo[0] = 0;
        memo[1] = 1;
        std::cout << fib2(n, memo) << std::endl;
    }
    
    std::cout << fib3(n) << std::endl;
    
    // At n = 50 this function executes for little under 2 min which is much slower that the other two functions!
    std::cout << fib1(n) << std::endl;

    return 0;
}
