// Task: https://leetcode.com/problems/minimum-common-value/description/?envType=daily-question&envId=2024-03-09

#include<iostream>
#include<vector>

int getCommon(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::ios_base::sync_with_stdio(false);      // ---> Stop synchronizing the C++ streams with the C streams!
    std::cin.tie(NULL);                         // ---> When we use std::cin and std::cout whenever we use std::cin, std::cout is being flushed first!                        
    std::cout.tie(NULL);                        // ---> The same goes the oposite way. When we use std::cout first the function flush() is called to std::cin!

    int i = 0;
    int j = 0;

    while (i < nums1.size() && j < nums2.size()) {
        if (nums1[i] == nums2[j]) {
            return nums1[i];
        }
        else if (nums1[i] < nums2[j]) {
            i++;
        }
        else {
            j++;
        }
    }
    return -1;
}

int main() {
	// Example 1:
	std::vector<int> vec1 = { 1, 2, 3 };
	std::vector<int> vec2 = { 2, 4 };
	std::cout << getCommon(vec1, vec2) << "\n";

	// Example 2:
	std::vector<int> vec3 = { 1, 2, 3, 6 };
	std::vector<int> vec4 = { 2, 3, 4, 5 };
	std::cout << getCommon(vec3, vec4) << "\n";

	return 0;
}
