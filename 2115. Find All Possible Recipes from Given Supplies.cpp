// Task: https://leetcode.com/problems/find-all-possible-recipes-from-given-supplies/description/?envType=daily-question&envId=2025-03-21

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <queue>

std::vector<std::string> findAllRecipes(std::vector<std::string>& recipes, 
										std::vector<std::vector<std::string>>& ingredients, 
										std::vector<std::string>& supplies) {
	int size = recipes.size();
	std::unordered_set<std::string> supp(supplies.begin(), supplies.end());
	std::vector<int> deg(size, 0);
	std::unordered_map < std::string, std::vector<int>> adj;
	std::queue<int> queue;
	std::vector<std::string> result;
	int iter = 0;
	std::string toPush = "";

	for (int i = 0; i < size; i++) {
		for (const std::string& str : ingredients[i]) {
			if (!supp.count(str)) {
				adj[str].push_back(i);
				deg[i]++;
			}
		}
	}

	for (int i = 0; i < size; i++) {
		if (deg[i] == 0) {
			queue.push(i);
		}
	}

	while (!queue.empty()) {
		iter = queue.front();
		queue.pop();
		toPush = recipes[iter];
		result.push_back(toPush);

		for (auto j : adj[toPush]) {
			if (--deg[j] == 0) {
				queue.push(j);
			}
		}
	}

	return result;
}

void printVec(const std::vector<std::string> vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
}

int main() {
	// Example 1:
	std::vector<std::string> recipes = { "bread" };
	std::vector<std::vector<std::string>> ingredients = { {"yeast", "flour"} };
	std::vector < std::string> supplies = { "yeast", "flour", "corn" };
	std::vector<std::string> vec = findAllRecipes(recipes, ingredients, supplies);
	printVec(vec);
}
