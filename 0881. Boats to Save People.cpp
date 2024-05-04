// Task : https://leetcode.com/problems/boats-to-save-people/description/?envType=daily-question&envId=2024-05-04

#include <iostream>
#include <vector>
#include <algorithm>

int numRescueBoats(std::vector<int>& people, int limit) {
	std::sort(people.begin(), people.end());
	int counter = 0;
	
	for (int i = 0, j = people.size() - 1; i <= j; j--) {
		counter++;

		if (people[i] <= limit - people[j]) {
			i++;
		}
	}

	return counter;
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 1, 2 };
	std::cout << numRescueBoats(vec1, 3) << '\n';

	// Example 2:
	std::vector<int> vec2 = { 3, 2, 2, 1 };
	std::cout << numRescueBoats(vec2, 3) << '\n';

	// Example 3:
	std::vector<int> vec3 = { 3, 5, 3, 4 };
	std::cout << numRescueBoats(vec3, 5) << '\n';

	// Example 4:
	std::vector<int> vec4 = { 5, 1, 4, 2 };
	std::cout << numRescueBoats(vec4, 6) << '\n';

	// Example 5:
	std::vector<int> vec5 = { 3, 2, 3, 2, 2 };
	std::cout << numRescueBoats(vec5, 6) << '\n';

	return 0;
}
