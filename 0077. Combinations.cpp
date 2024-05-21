// Task : https://leetcode.com/problems/combinations/description/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> combine(int n, int k) {
	std::vector<std::vector<int>> allCombinations;
	std::vector<int> currentCombination(k);

	for (int i = 0; i < k; ++i) {
		currentCombination[i] = i + 1;
	}

	while (true) {
		allCombinations.push_back(currentCombination);

		int i;
		for (i = k - 1; i >= 0; --i) {
			if (currentCombination[i] != i + n - k + 1) {
				break;
			}
		}

		if (i < 0) {
			break;
		}

		currentCombination[i]++;
		for (int j = i + 1; j < k; ++j) {
			currentCombination[j] = currentCombination[j - 1] + 1;
		}
	}

	return allCombinations;
}

void printCombinations(std::vector<std::vector<int>> com) {
	std::cout << "{ ";
	for (const auto& combination : com) {
		std::cout << "{ ";
		for (int num : combination) {
			std::cout << num << " ";
		}
		std::cout << "} \n";
	}
	std::cout << "} \n";
}

int main() {
	//Example 1:
	std::vector<std::vector<int>> comb1 = combine(4, 2);
	printCombinations(comb1);		

	//Example 2:
	std::vector<std::vector<int>> comb2 = combine(1, 1);
	printCombinations(comb2);

	return 0;
}
