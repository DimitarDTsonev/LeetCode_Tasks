// Task : 

#include <iostream>
#include <string>

int appendCharacters(std::string s, std::string t) {
    unsigned i = 0;
    unsigned j = 0;
    unsigned sizeS = s.length();
    unsigned sizeT = t.length();

    while (i < sizeS && j < sizeT) {
        if(s[i] == t[j]){
            j++;
        }
        i++;
    }
    return sizeT - j;
}

int main() {
    // Example 1:
    std::cout << appendCharacters("coaching", "coding") << '\n';

    // Example 2:
    std::cout << appendCharacters("abcde", "a") << '\n';

    // Example 3:
    std::cout << appendCharacters("z", "abcde") << '\n';

    return 0;
}
