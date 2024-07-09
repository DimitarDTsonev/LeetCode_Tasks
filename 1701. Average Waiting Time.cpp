// Task : https://leetcode.com/problems/average-waiting-time/?envType=daily-question&envId=2024-07-09

#include <vector>

double averageWaitingTime(std::vector<std::vector<int>>& customers) {
	double allWaiting = 0;
	int currTime = 0;

	for (const auto& customer : customers) {
		int arrival = customer[0];
		int service = customer[1];
		
		if (currTime < arrival) {
			currTime = arrival;
		}
		
		int waiting_time = currTime - arrival + service;
		allWaiting += waiting_time;
		currTime += service;
	}

	return allWaiting / customers.size();
}

int main() {
	// Ecample 1: 
	std::vector<std::vector<int>> vec1 = { {1, 2}, {2, 5}, {4, 3} };
	std::cout << averageWaitingTime(vec1) << '\n';

	// Ecample 2: 
	std::vector<std::vector<int>> vec2 = { {5, 2}, {5, 4}, {10, 3}, {20, 1} };
	std::cout << averageWaitingTime(vec2) << '\n';

	return 0;
}
