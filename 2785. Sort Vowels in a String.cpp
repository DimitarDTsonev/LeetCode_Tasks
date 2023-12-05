#include<iostream>
#include<string>
#include<vector>
#include<array>

std::string sortVowels(std::string& s) {
    std::array<int, 256> ascii{};
    std::vector<int> vowelIndexes;
    for (size_t i = 0; i < s.size(); ++i) {
        const auto& currentChar = std::tolower(s[i]);
        if (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || currentChar == 'o' 
		|| currentChar == 'u') {              
            ascii[static_cast<int>(s[i])]++;
            vowelIndexes.emplace_back(i);
        }
    }
    size_t currentAscii = 0;
    for (size_t i = 0; i < vowelIndexes.size(); ++i) {
        while (ascii[currentAscii] <= 0) {
            ++currentAscii;
        }
        s[vowelIndexes[i]] = static_cast<char>(currentAscii);
        --ascii[currentAscii];
    }

    return s;
}

int main() {
	std::string s("lEetcOde");
	std::cout << sortVowels(s);

	return 0;
}
