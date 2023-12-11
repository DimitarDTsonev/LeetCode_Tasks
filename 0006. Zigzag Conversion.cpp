// Task 6 of LeetCode:
// https://leetcode.com/problems/zigzag-conversion/description/

#include<iostream>
#include<string>
#include<vector>

std::string convert(std::string beg, int numRows) {
	std::vector<std::string> vec(numRows, "");

    size_t i = 0;
    while (i < beg.length()) {
        for (int row = 0; row < numRows && i < beg.length(); ++row) {
            vec[row].push_back(beg[i]);
            ++i;
        }

        for (int row = numRows - 2; row >= 1 && i < beg.length(); --row) {
            vec[row].push_back(beg[i]);
            ++i;
        }
    }

    std::string after;
    for (const std::string& row : vec) {
        after += row;
    }

    return after;
}

int main() {
	std::string beg("PayPalIsHiring");

	std::cout << convert(beg, 3) << std::endl;
    std::cout << convert(beg, 4) << std::endl;
    
	return 0;
}
