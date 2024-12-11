// Task : https://leetcode.com/problems/find-the-original-typed-string-i/description/?envType=problem-list-v2&envId=asohcqu1

#include <iostream>
#include <set>
#include <string>

int possibleStringCount(std::string word) {
    unsigned size = word.size();
    unsigned counter = 1;
    std::unordered_set<char> us;

    for (int i = 0; i < size; i++) {
        if (i != 0 && (us.find(word[i]) != us.end()) && word[i] == word[i - 1]) {
            ++counter;
        }
        else {
                us.insert(word[i]);
        }
    }
        
    return counter;
}

int main() {
    // Test 1:
    std::cout << possibleStringCount("abbcccc") << '\n';

    // Test 2:
    std::cout << possibleStringCount("abcd") << '\n';

    // Test 3:
    std::cout << possibleStringCount("aaaa") << '\n';

    return 0;
}
