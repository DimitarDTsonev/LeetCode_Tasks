// Task: https://leetcode.com/problems/roman-to-integer/description/

#include<string>
#include<iostream>

int romanToInt(std::string s) {
    int number = 0;
    int sLength = s.length();
    for (int i = 0; i < sLength; i++) {
        switch (s[i]) {
        case 'I':
            number += 1;
            break;
        case 'V':
            number += 5;
            break;
        case 'X':
            number += 10;
            break;
        case 'L':
            number += 50;
            break;
        case 'C':
            number += 100;
            break;
        case 'D':
            number += 500;
            break;
        case 'M':
            number += 1000;
            break;
        }
    }

    for (int i = 1; i < sLength; i++) {
        if ((s[i] == 'V' || s[i] == 'X') && s[i - 1] == 'I') {
            number -= 1 + 1;
        }

        if ((s[i] == 'L' || s[i] == 'C') && s[i - 1] == 'X') {
            number -= 10 + 10;
        }

        if ((s[i] == 'D' || s[i] == 'M') && s[i - 1] == 'C') {
            number -= 100 + 100;
        }
    }
    return number;
}

int main() {
    // Test 1:
    std::string roman1 = "III";
    std::cout << romanToInt(roman1) << std::endl;

    // Test 2:
    std::string roman2 = "LVIII";
    std::cout << romanToInt(roman2) << std::endl;

    // Test 3:
    std::string roman3 = "MCMXCIV";
    std::cout << romanToInt(roman3) << std::endl;

    return 0;
}
