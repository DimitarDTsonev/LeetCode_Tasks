// Task: https://leetcode.com/problems/is-subsequence/description/?envType=study-plan-v2&envId=leetcode-75

#include<iostream>
#include<string>

bool isSubsequence(std::string s, std::string t) {
    int cntS = 0, cntT = 0;

    while(cntS < s.size() && cntT < t.size()){
        if(s[cntS] == t[cntT]){
            ++cntS;
        }
        ++cntT;
    }

    return (cntS == s.size());
}

int main() {
    // Example 1:
    std::cout << isSubsequence("abc", "ahbgdc") << "\n";

    // Example 2:
    std::cout << isSubsequence("axc, "ahbgdc") << "\n";
    
  return 0;
}
