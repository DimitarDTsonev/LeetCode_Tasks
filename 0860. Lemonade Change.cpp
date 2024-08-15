// Task : https://leetcode.com/problems/lemonade-change/description/?envType=daily-question&envId=2024-08-15

#include <iostream>
#include <vector>

bool lemonadeChange(std::vector<int>& bills) {
	unsigned five = 0, ten = 0;

	for (int& it : bills) {
		if (it == 5) {
			five++;
		}
		else if (it == 10 && five >= 1) {
			ten++;
			five--;
		}
		else if (ten >= 1 && five >= 1) {
			five--;
			ten--;
		}
		else if (five >= 3) {
			five -= 3;
		}
		else {
			return false;
		}
	}
	return true;
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 5, 5, 5, 10, 20 };
	std::cout << lemonadeChange(vec1) << '\n';

	// Example 2:
	std::vector<int> vec2 = { 5, 5, 10, 10, 20 };
	std::cout << lemonadeChange(vec2) << '\n';

	return 0;
}
