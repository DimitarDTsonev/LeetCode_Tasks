// Task: https://leetcode.com/problems/last-stone-weight/description/

#include <iostream>
#include <vector>
#include <queue>

int lastStoneWeight(std::vector<int>& stones) {
	std::priority_queue<int> pq;
	int size = stones.size();
	int frs;
	int snd;

	for (size_t i = 0; i < size; i++) {
		pq.push(stones[i]);
	}

	while (size > 1) {
		frs = pq.top();
		pq.pop();
		snd = pq.top();
		pq.pop();

		if (frs == snd && pq.size() > 1) {
			continue;
		}
		else if (pq.size() == 0) {
			pq.push(frs > snd ? (frs - snd) : (snd - frs));
			break;
		}
		pq.push(frs > snd ? (frs - snd) : (snd - frs));
	}

	return pq.top();
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 2, 7, 4, 1, 8, 1 };
	std::cout << lastStoneWeight(vec1) << "\n";

	// Example 2:
	std::vector<int> vec2 = { 1 };
	std::cout << lastStoneWeight(vec2) << "\n";

	// Example 3:
	std::vector<int> vec3 = { 1, 3 };
	std::cout << lastStoneWeight(vec3) << "\n";

	return 0;
}
