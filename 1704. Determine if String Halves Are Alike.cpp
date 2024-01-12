// Task: https://leetcode.com/problems/determine-if-string-halves-are-alike/description/?envType=daily-question&envId=2024-01-12
#include<iostream>
#include<string>

bool halvesAreAlike(std::string s) {
	int counter1 = 0, counter2 = 0, size = s.size() / 2;
	char ch = ' ';
	bool b = false;
	for (size_t i = 0; i < s.size(); i++) {
		ch = s[i];
		b = (ch == 'a' || ch == 'e' || ch == 'o' || ch == 'i' || ch == 'u' || ch == 'A'
			|| ch == 'O' || ch == 'E' || ch == 'U' || ch == 'I');
		if ((i < size) && b) {
			++counter1;
		}
		else if (b) {
			++counter2;
		}
	}
	return (counter1 == counter2);
}

int main() {
	// Example 1:
	std::string s1 = "book";
	std::cout << halvesAreAlike(s1) << std::endl;

	// Example 2:
	std::string s2 = "textbook";
	std::cout << halvesAreAlike(s2) << std::endl;

	return 0;
}
