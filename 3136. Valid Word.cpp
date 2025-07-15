// Task : https://leetcode.com/problems/valid-word/description/?envType=daily-question&envId=2025-07-15

#include <iostream>
#include <string>

bool isVowel(char ch) {
    return ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u' ||
           ch == 'A' || ch == 'E' || ch == 'O' || ch == 'I' || ch == 'U';
}

bool isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

bool isValid(std::string word) {
    int size = word.size();

    if (size < 3) {
        return false;
    }

    bool vowel = false;
    bool consonant = false;

    for (int i = 0; i < size; i++) {
        if (!(isDigit(word[i]) ||
            word[i] > 64 && word[i] < 91 ||
            word[i] > 96 && word[i] < 123)) {
                return false;
        } else if (isDigit(word[i])) {
            continue;
        } else if (isVowel(word[i])) {
            vowel = true;
        } else {
            consonant = true;
        }
    }

    return vowel && consonant;
}

int main() {
    // Example 1:
    std::cout << isValid("234Adas") << '\n';

    // Example 2:
    std::cout << isValid("b3") << '\n';

    // Example 3:
    std::cout << isValid("a3$e") << '\n';

    return 0;
}
