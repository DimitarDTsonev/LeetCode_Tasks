// Task: https://leetcode.com/problems/longest-substring-without-repeating-characters/

#include<iostream>
#include<string>
#include<unordered_map>

int lengthOfLongestSubstring(std::string s) {
        int n = s.length();
        int maxLength = 0;
        std::unordered_map<char, int> charMap;
        int left = 0;
        
        for (int right = 0; right < n; right++) {
            if (charMap.count(s[right]) == 0 || charMap[s[right]] < left) {
                charMap[s[right]] = right;
                maxLength = std::max(maxLength, right - left + 1);
            } else {
                left = charMap[s[right]] + 1;
                charMap[s[right]] = right;
            }
        }
        return maxLength;
    }

int main(){
    std::string s = "abcabc";
    std::string s1 = "bbbbb";
    std::string s2 = "pwwkew";
    
    std::cout << lengthOfLongestSubstring(s) << std::endl;
    std::cout << lengthOfLongestSubstring(s1) << std::endl;
    std::cout << lengthOfLongestSubstring(s2) << std::endl;

    return 0;
}
