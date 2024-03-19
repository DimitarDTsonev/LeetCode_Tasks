// Task: https://leetcode.com/problems/task-scheduler/?envType=daily-question&envId=2024-03-19

#include<iostream>
#include<vector>
#include<algorithm>

int leastInterval(std::vector<char>& tasks, int n) {
	int freq[26] = { 0 };
	for (char ch : tasks) {
		freq[ch - 'A']++;
	}

	std::sort(freq, freq + 26);

	int cnt = freq[25];
	int slots = (--cnt) * n;

	for (int i = 0; i < 25; i++) {
		slots -= std::min(freq[i], cnt);
	}

	return slots > 0 ? slots + tasks.size() : tasks.size();
}

int main() {
	// Example 1:
	std::vector<char> vec1 = { 'A','A','A', 'B', 'B', 'B' };
	std::cout << leastInterval(vec1, 2) << "\n";

	// Example 2:
	std::vector<char> vec2 = { 'A','C','A', 'B', 'D', 'B' };
	std::cout << leastInterval(vec2, 1) << "\n";

	// Example 3:
	std::vector<char> vec3 = { 'A','A','A', 'B', 'B', 'B' };
	std::cout << leastInterval(vec3, 3) << "\n";

	return 0;
}
