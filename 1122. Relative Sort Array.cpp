// Task : https://leetcode.com/problems/relative-sort-array/description/?envType=daily-question&envId=2024-06-11

#include <iostream>
#include <map>
#include <vector>

std::vector<int> relativeSortArray(std::vector<int>& arr1, std::vector<int>& arr2) {
	std::map<int, int>map;
	std::vector<int>res;
	int counter = 0;

	for (int i = 0; i < arr1.size(); i++) {
		map[arr1[i]]++;
	}

	while (counter < arr2.size()) {
		if (map[arr2[counter]]) {
			res.push_back(arr2[counter]);
			map[arr2[counter]]--;
		}
		else {
			counter++;
		}
	}

	for (auto it : map) {
		int freq = it.second;
		for (int i = 0; i < freq; i++) {
			res.push_back(it.first);
		}
	}
	return res;
}

void printVec(const std::vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); i++)	{
		std::cout << vec[i] << " ";
	}
	std::cout << '\n';
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 2, 3, 1, 3, 2, 4, 6, 7, 9, 2, 19 };
	std::vector<int> vec2 = { 2, 1, 4, 3, 9, 6 };
	printVec(relativeSortArray(vec1, vec2));

	// Example 2:
	std::vector<int> vec3 = { 28, 6, 22, 8, 44, 17 };
	std::vector<int> vec4 = { 22, 28, 8, 6 };
	printVec(relativeSortArray(vec3, vec4));

	return 0;
}
