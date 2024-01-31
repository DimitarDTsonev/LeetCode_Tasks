// Task: https://leetcode.com/problems/daily-temperatures/description/?envType=daily-question&envId=2024-01-31

#include<iostream>
#include<vector>

std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
	std::vector<int> res(temperatures.size(), 0);
	std::vector<int> st;

	for (int i = temperatures.size() - 1; i >= 0; --i) {
		int curr = temperatures[i];

		while (!st.empty() && curr >= temperatures[st.back()]) {
			st.pop_back();
		}

		if (!st.empty()) {
			res[i] = st.back() - i;
		}

		st.push_back(i);
	}
	return res;
}

void printVec(const std::vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 73, 74, 75, 71, 69, 72, 76, 73 };
	std::vector<int> vec2 = dailyTemperatures(vec1);
	printVec(vec2);
	
	// Example 2:
	std::vector<int> vec3 = { 30, 40, 50, 60 };
	std::vector<int> vec4 = dailyTemperatures(vec3);
	printVec(vec4);
	
	// Example 3:
	std::vector<int> vec5 = { 30, 60, 90 };
	std::vector<int> vec6 = dailyTemperatures(vec5);
	printVec(vec6);
	          
	return 0;
}
