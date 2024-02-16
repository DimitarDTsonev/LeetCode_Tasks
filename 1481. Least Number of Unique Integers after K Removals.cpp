// Task: https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/?envType=daily-question&envId=2024-02-16

#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>

int findLeastNumOfUniqueInts(std::vector<unsigned>& arr, int k) {
	std::unordered_map<unsigned, unsigned> map;
	for (auto iter : arr) {
		map[iter]++;
	}

	std::vector<int> vec;
	int count = 0;

	for (auto iter : map) {
		vec.push_back(iter.second);
	}

	std::sort(vec.begin(), vec.end());


	for (int i = 0; i < vec.size(); ++i) {	// 
		if (k > vec[i]) {
			k -= vec[i];
			vec[i] = 0;
		}
		else {
			vec[i] -= k;
			k = 0;
		}
		if (vec[i] != 0) {
			++count;
		}
	}

	return count;
}

int main() {
	// Example 1:
	std::vector<unsigned> vec1 = { 5, 5, 4 };
	std::cout << findLeastNumOfUniqueInts(vec1, 1) << "\n";

	// Example 2:
	std::vector<unsigned> vec2 = { 4, 3, 1, 1, 3, 3, 2 };
	std::cout << findLeastNumOfUniqueInts(vec2, 3) << "\n";

	return 0;
}
