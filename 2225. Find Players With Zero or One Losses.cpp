#include<iostream>
#include<vector>
#include<map>

// There are two answears to the task:
// The first one in only with the usage of vectors and pairs but is slower than the second one
// The second one uses map 
void loss_win(std::vector<std::pair<int, int>>& losses_wins, int number) {
	for (size_t i = 0; i < losses_wins.size(); i++) {
		if (number == losses_wins[i].first) {
			losses_wins[i].second++;
			return;
		}
	}
	losses_wins.push_back(std::pair<int, int>(number, 1));
}

bool containsInLoss(std::vector<std::pair<int, int>> losses, int number) {
	for (size_t i = 0; i < losses.size(); i++) {
		if (number == losses[i].first) {
			return true;
		}
	}
	return false;
}

int partition(std::vector<int>& arr, int low, int high) {
	int pivot = arr[high]; 
	int i = low - 1; 

	for (int j = low; j < high; j++) {
		if (arr[j] < pivot) {
			i++;
			std::swap(arr[i], arr[j]);
		}
	}

	std::swap(arr[i + 1], arr[high]);
	return i + 1;
}

void quicksort(std::vector<int>& arr, int low, int high) {
	if (low < high) {
		int pivotIndex = partition(arr, low, high);

		quicksort(arr, low, pivotIndex - 1);
		quicksort(arr, pivotIndex + 1, high);
	}
}

std::vector<std::vector<int>> findWinners(std::vector<std::vector<int>>& matches) {
	std::vector<std::vector<int>> toReturn(2);
	std::vector<std::pair<int, int>> losses{};
	std::vector<std::pair<int, int>> wins{};
	
	for (size_t i = 0; i < matches.size(); i++) {
		loss_win(wins, matches[i][0]);
		loss_win(losses, matches[i][1]);
	}
	
	for (size_t i = 0; i < losses.size(); i++) {
		if (losses[i].second == 1) {
			toReturn[1].push_back(losses[i].first);
		}
	}

	for (size_t i = 0; i < wins.size(); i++) {
		if (!containsInLoss(losses, wins[i].first)) {
			toReturn[0].push_back(wins[i].first);
		}
	}

	quicksort(toReturn[0], 0, toReturn[0].size() - 1);
	quicksort(toReturn[1], 0, toReturn[1].size() - 1);

	return toReturn;
}
// The first one ends!

// The second one begin here:
std::vector<std::vector<int>> findWinnersss(std::vector<std::vector<int>>& matches) {
	std::map<int, int>mp1;
	std::map<int, int>mp2;

	for (int i = 0; i < matches.size(); i++) {
		mp1[matches[i][0]]++;
		mp2[matches[i][1]]++;
	}

	std::vector<std::vector<int>>ans;
	std::vector<int>temp1;

	for (auto it : mp1) {
		if (mp2.find(it.first) == mp2.end()) {
			temp1.push_back(it.first);
		}
	}

	ans.push_back(temp1);
	std::vector<int>temp2;
	for (auto it : mp2) {
		if (it.second == 1) {
			temp2.push_back(it.first);
		}
	}

	ans.push_back(temp2);
	return ans;
}

int main() {
	std::vector<std::vector<int>> matches{ {1, 3}, { 2, 3 }, { 3, 6 }, { 5, 6 }, { 5, 7 }, { 4, 5 }, { 4, 8 }, { 4, 9 }, { 10, 4 }, { 10, 9 } };
	std::vector<std::vector<int>> returned = findWinners(matches);

  // Test for the first way:
	for (size_t i = 0; i < 2; i++) {
		for (size_t j = 0; j < returned[i].size(); j++) {
			std::cout << returned[i][j] << " ";
		}
		std::cout << std::endl;
	}

  // Test for the second way:
  std::vector<std::vector<int>> returned = findWinnersss(matches);
  for (size_t i = 0; i < 2; i++) {
		for (size_t j = 0; j < returned[i].size(); j++) {
			std::cout << returned[i][j] << " ";
		}
		std::cout << std::endl;
	}

	return 0;
}
