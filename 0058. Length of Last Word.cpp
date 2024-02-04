// Task: https://leetcode.com/problems/length-of-last-word/description/

#include<iostream>
#include<string>

int lengthOfLastWord(std::string s) {
    int count = 0;
    int n = s.size();
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1 && isspace(s[i]))
            n--;
        else if (i != n - 1 && isspace(s[i]))
            return count;
        else
            count++;
    }
    return count;
}

int main() {
	// Example 1:
	std::string s1("Hello World");
	std::cout << lengthOfLastWord(s1) << std::endl;

	// Example 2:
	std::string s2("   fly me   to   the moon  ");
	std::cout << lengthOfLastWord(s2) << std::endl;

	// Example 3:
	std::string s3("luffy is still joyboy");
	std::cout << lengthOfLastWord(s3) << std::endl;

	return 0;
}
