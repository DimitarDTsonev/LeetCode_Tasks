#include<iostream>
#include<string>
#include<vector>

// Beats 96% for time and 60% for memory:
int prefixCount(std::vector<std::string>& words, std::string pref) {
	unsigned counter = 0, sizePref = pref.size();
	for (int i = 0; i < words.size(); i++) {
		if (words[i].substr(0, sizePref) == pref) {
			++counter;
		}
	}
	return counter;
}

int main() {
	std::vector<std::string> words{ "pay","attention","practice","attend" };
	std::string pref{ "at" };

	std::cout << prefixCount(words, pref);

	return 0;
}
