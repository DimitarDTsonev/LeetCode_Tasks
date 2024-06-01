// Task : https://leetcode.com/problems/score-of-a-string/description/?envType=daily-question&envId=2024-06-01

#include <iostream>
#include <string>

int scoreOfString(std::string s) {
    int score = 0;

        for(int i = 0; i < s.size() - 1; i++){
            score += std::abs(s[i] - s[i + 1]);
        }
    
        return score;
}

int main() {
    // Example 1:
    std::cout << scoreOfString("hello") << '\n';

    // Example 2:
    std::cout << scoreOfString("zaz") << '\n';

    return 0;
}
