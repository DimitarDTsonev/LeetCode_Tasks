#include<iostream>

bool isPalindrome(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)){
        return false;
    }
    int reversed = 0, xCopy = x;
    while(xCopy > 0){
        if (reversed > INT_MAX / 10){
            return false;
        }
        reversed *=  10;
        reversed = reversed + (xCopy % 10);         
        xCopy = xCopy / 10;   
    }
    return reversed == x;
}

int main() {
    // Test 1:
    int x1 = 121;
    std::cout << isPalindrome(x1) << std::endl;

    // Test 2:
    int x2 = -121;
    std::cout << isPalindrome(x2) << std::endl;

    // Test 3:
    int x3 = 10;
    std::cout << isPalindrome(x3) << std::endl;
    
    return 0;
}
