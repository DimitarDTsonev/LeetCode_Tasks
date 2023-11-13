#include<iostream>
#include<string>
#include<vector>
#include<array>

std::string sortVowels(std::string& s) {
    // Array to store the count of each ASCII value
    std::array<int, 256> ascii{};
    std::vector<int> vowelIndexes;
    for (size_t i = 0; i < s.size(); ++i) {
        const auto& currentChar = std::tolower(s[i]);
        if (currentChar == 'a' || currentChar == 'e' || currentChar == 'i' || currentChar == 'o' || currentChar == 'u') {
            //Increment the count for the ASCII value of the vowel               
            ascii[static_cast<int>(s[i])]++;
            vowelIndexes.emplace_back(i);
        }
    }
    size_t currentAscii = 0;
    for (size_t i = 0; i < vowelIndexes.size(); ++i) {
        //Find the next non-zero count ASCII value
        while (ascii[currentAscii] <= 0) {
            ++currentAscii;
        }
        //Replace the original vowel with the next ASCII value
        s[vowelIndexes[i]] = static_cast<char>(currentAscii);
        //Decrease the count of the used ASCII value
        --ascii[currentAscii];
    }

    return s;
}

int main() {
	std::string s("lEetcOde");

	std::cout << sortVowels(s);


	return 0;
}
  }
