// Task: https://leetcode.com/problems/steps-to-make-array-non-decreasing/description/

#include<iostream>
#include<vector>
#include<stack>

int totalSteps(std::vector<int>& nums) {
    int size = nums.size();
    std::stack<std::pair<int, int>> st;
    int steps = -1;

    for (int i = size - 1; i >= 0; i--) {
        int counter = 0;
        while (!st.empty() && st.top().first < nums[i]) {
            counter = std::max(counter + 1, st.top().second);
            st.pop();
        }
        steps = std::max(steps, counter);
        st.push({ nums[i], counter });
    }

    return steps;
}

int main() {
	// Example 1:
	std::vector<int> vec = { 5, 3, 4, 4, 7, 3, 6, 11, 8, 5, 11 };
	std::cout << totalSteps(vec) << " ";

	// Example 2:
	std::vector<int> vec1 = { 4, 5, 7, 7, 13 };
	std::cout << totalSteps(vec1) << " ";

	return 0;
}
