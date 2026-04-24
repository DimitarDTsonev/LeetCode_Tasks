// Task : https://leetcode.com/problems/furthest-point-from-origin/submissions/1986980643/?envType=daily-question&envId=2026-04-24

#include <iostream> 
int furthestDistanceFromOrigin(string moves) {
    int R = 0;
    int L = 0;
    int space = 0;

    for (int i = 0; i < moves.length(); i++) {
        if (moves[i] == 'R') {
            ++R;
        } else if (moves[i] == 'L') {
            ++L;
        } else {
            ++space;
        }
    }

    if (R > L) {
        return space + R - L;
    } else {
        return space + L - R;
    }
}

int main() {
    // Example 1:
    std::string example1 = { "L_RL__R" };
    std::cout << furthestDistanceFromOrigin(example1) << '/n';
    
    // Example 2:
    std::string example2 = { "_R__LL_" };
    std::cout <<  furthestDistanceFromOrigin(example2) << '/n';

    // Example 3:
    std::string example3 = { "_______" };   
    std::cout <<  furthestDistanceFromOrigin(example3) << '/n';
}
