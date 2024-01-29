// Task: https://leetcode.com/problems/next-greater-element-ii/description/

#include<iostream>
#include<vector>
#include<stack>

void printVec(const std::vector<int> vec) {
	for (size_t i = 0; i < vec.size(); i++) {
		std::cout << vec[i] << " ";
	}
	std::cout << std::endl;
}

std::vector<int> nextGreaterElements(std::vector<int>& nums) {
	int size = nums.size();
	
	std::vector<int> toRreturn(size, -1);
	std::stack<int> st;
	
	for (int i = 2 * size - 1; i >= 0; i--) {
		while (!st.empty() and st.top() <= nums[i % size]) {
			st.pop();
		}
		if (i < size) {
			if (!st.empty()) toRreturn[i] = st.top();
		}
		st.push(nums[i % size]);
	}
	return toRreturn;
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 1, 2, 1 };
	std::vector<int> vec2 = nextGreaterElements(vec1);
	printVec(vec2);

	// Example 2:
	std::vector<int> vec3 = { 1, 2, 3, 4, 3 };
	std::vector<int> vec4 = nextGreaterElements(vec3);
	printVec(vec4);

	return 0;
}
