// Task : https://leetcode.com/problems/get-equal-substrings-within-budget/description/?envType=daily-question&envId=2024-05-28

#include <iostream>
#include <string>

int equalSubstring(std::string s, std::string t, int maxCost) {
    int res = 0;
    int currCost = 0;
    int iter = 0;

    for (int i = 0; i < s.size(); i++){
        currCost += std::abs(s[i] - t[i]);

        while(currCost > maxCost){
            currCost -= std::abs(s[iter] - t[iter]);
            iter++;
        }
        res = std::max(res, i - iter + 1);
    }
    return res;
}

int main() {
    // Example 1:
    std::cout << rqualSubString("abcd", "bcdf", 3) << '\n';

    // Example 2:
    std::cout << rqualSubString("abcd", "cdef", 3) << '\n';

    // Example 3:
    std::cout << rqualSubString("abcd", "acde", 0) << '\n';
    
    return 0;
}
