// Task: https://leetcode.com/problems/optimal-partition-of-string/description/?envType=study-plan-v2&envId=amazon-spring-23-high-frequency

#include <iostream>
#include <string>

int partitionString(string s) {
    int res = 0;
    long long bit = 0;
    int number = 0;

    for(auto& ch : s){
        number = 1 << (ch - 'a');
        if(bit & number){
            res++;
            bit = 0;
        }
        bit |= number;  
    }

    return 1 + res;
}

int main() {
    // Example 1:
    std::cout << partitionString("abacaba") << "\n";

    // Example 2:
    std::cout << partitionString("ssssss") << "\n";
    
    return 0;
}
