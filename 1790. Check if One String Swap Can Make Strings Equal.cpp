// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal/description/?envType=daily-question&envId=2025-02-05

#include <iostream>
#include <string>

bool areAlmostEqual(string s1, string s2) {
    if (s1.length() != s2.length()) {
        return false;
    }

    int fStrCounter = -1;
    int sStrCounter = -1;
    int cnt = 0;

    for (int i = 0; i < s1.length(); i++) {
        if (s1[i] != s2[i]) {
            cnt++;
            
            if (fStrCounter == -1) {
                fStrCounter = i;
            } else if (sStrCounter == -1) {
                sStrCounter = i;
            }
        }
    }

    if (cnt == 0) {
        return true;
    } else if (cnt == 2 && s1[fStrCounter] == s2[sStrCounter] &&
               s1[sStrCounter] == s2[fStrCounter]) {
        return true;
    }

    return false;
}

int main() {
    // Example 1:
    std::cout << areAlmostEqual("bank", "kanb") << std::endl;

    // Example 2:
    std::cout << areAlmostEqual("attack", "defend") << std::endl;

    // Example 3:
    std::cout << areAlmostEqual("kelb", "kelb") << std::endl;

    return 0;
}
