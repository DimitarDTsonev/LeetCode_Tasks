// Task: https://leetcode.com/problems/counting-bits/description/

#include<iostream>
#include<vector>
#include<bitset>

// This method is easier to be written
std::vector<int> countBits1(int  n) {
	std::vector<int> toReturn(n + 1);
	std::string curr{};
	int num = 0;
	for (size_t i = 0; i < n + 1; i++) {
		curr = std::bitset<sizeof(int) * 8>(i).to_string();
		for (size_t j = 0; j < curr.size(); j++) {
			if (curr[j] == '1') {
				++num;
			}
		}
		toReturn[i] = num;
		num = 0;
	}
	return toReturn;
}

// Faster method by shifting the bits.  
std::vector<int> countBits2(int n) {
    std::vector <int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        ans[i] = ans[i >> 1] + (i & 1);
    }
    return ans;
}

// Printing function for the tests:
void printVec(std::vector<int>& vec) {
	for (size_t i = 0; i < vec.size(); i++){
		std::cout << vec[i] << " ";
	}
}

int main() {
    // Test 1:
	std::vector<int> vec(countBits1(-1));
	printVec(vec);

     // Test 2:
	std::vector<int> vec(countBits1(5));
	printVec(vec);

    // Test 1:
	std::vector<int> vec(countBits2(-1));
	printVec(vec);

     // Test 2:
	std::vector<int> vec(countBits2(5));
	printVec(vec);
    
	return 0;
}
