// Task : https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/description/?envType=daily-question&envId=2024-05-29

#include <iostream>
#include <string>

int numSteps(std::string s) {
    int size = s.size();
    int step = 0;
    int carry=0;

    for(int i= size - 1; i > 0; i--) {
        int dig = s[i] - 0 + carry;

        if(dig % 2 == 0){
            step++;
        }
        else{
            step+=2;
            carry=1;
        }
    }
    return step+carry;
}

int main() {
    // Example 1:
    std::cout << numSteps("1011") << '\n';

    // Example 2:
    std::cout << numSteps("10") << '\n';

    // Example 3:
    std::cout << numSteps("1") << '\n';
    
    return 0;
}
