// Task : https://leetcode.com/problems/reveal-cards-in-increasing-order/?envType=daily-question&envId=2024-04-10

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

std::vector<int> deckRevealedIncreasing(std::vector<int>& deck) {
	std::sort(deck.begin(), deck.end());
	unsigned size = deck.size();
	std::vector<int> res(size, 0);
	std::deque<int> deq;

	for (size_t i = 0; i < size; i++) {
		deq.push_back(i);
	}

	int idx = 0;
	for (int card : deck) {
		idx = deq.front();
		deq.pop_front();
		res[idx] = card;

		if (!deq.empty()) {
			deq.push_back(deq.front());
			deq.pop_front();
		}
	}

	return res;
}

void printVec(const std::vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << '\n';
}

int main() {
	// Example 1: 
	std::vector<int> vec1 = { 17, 13, 11, 2, 3, 5, 7 };
	printVec(deckRevealedIncreasing(vec1));

	// Example 2:
	std::vector<int> vec2 = { 1, 1000 };
	printVec(deckRevealedIncreasing(vec2));

	return 0;
}
