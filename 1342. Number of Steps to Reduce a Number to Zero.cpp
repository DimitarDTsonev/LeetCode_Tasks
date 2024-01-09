// Task: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/description/

#include<iostream>

// Iterative method:
int numberOfSteps(int num) {
    unsigned counter = 0;
    while(num != 0){
        if(num % 2 == 0){
        num /= 2;
        }
        else{
            num -= 1;
        }
        ++counter;
    }
    return counter;
}

// Bitwise manipulation way:
int numberOfSteps(int num) {
    int a=0,b=0;
    while (num){
        a+=num%2;
        b++;
        num/=2;
    }
    return (a+b>0?a+b-1:0);
}

int main() {
    // Example 1:
    std::cout << numberOfSteps(14) << std::endl;

    // Example 2:
    std::cout << numberOfSteps(8) << std::endl;

    // Example 3:
    std::cout << numberOfSteps(123) << std::endl;
    return 0;
}
