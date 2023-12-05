#include<iostream>
#include<string>

std::string removeDuplicates(std::string s) {
	int i = 0, size = s.size();
	for (size_t j = 0; j < size; i++, j++) {
		s[i] = s[j];
		if (i > 0 && s[i - 1] == s[i]) {
			i -= 2;
		}
	}
	return s.substr(0, i);
}

int main() {
	// Example 1:
	std::string str = { "abbaca" };
	std::cout << removeDuplicates(str) << std::endl;

	// Example 2;
	std::string str1 = { "azxxzy" };
	std::cout << removeDuplicates(str1) << std::endl;

	// Example 3:
	std::string str2 = { "aaaaaa" };
	std::cout << removeDuplicates(str2);

	return 0;
}
