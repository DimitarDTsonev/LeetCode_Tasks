// Task: https://leetcode.com/problems/palindromic-substrings/description/?envType=daily-question&envId=2024-02-10

#include<iostream>
#include<string>

int isPalindrome(const std::string& s, int start, int end) {
    int count = 0;
    while (start >= 0 && end < s.length() && s[start] == s[end]) {
        ++count;
        --start;
        ++end;
    }
    return count;
}

int countSubstrings(std::string s) {
    int count = 0;
    int n = s.length();
    int odd = 0;
    int even = 0;
        
    for (int i = 0; i < n; ++i) {
        odd = isPalindrome(s, i, i);
        even = isPalindrome(s, i, i + 1);
        count += odd;
        count += even;
    }

    return count;
}

int main() {
    // Example 1:
    std::cout << countSubstrings("abc");

    // Example 2:
    std::cout << countSubstring("aaa");

    return 0;
}
