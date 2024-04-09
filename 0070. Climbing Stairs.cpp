// Task : https://leetcode.com/problems/climbing-stairs/description/

#include <iostream>
#include <vector>
#include <unordered_map>

namespace SM {
	// Easy approach with optimal space but not optimal for time:
	int climbStairs(int n) {
		if (n == 0 || n == 1) {
			return 1;
		}
		int curr = 1;
		int prev = 1;
		int tmp = 0;

		for (size_t i = 2; i < n + 1; i++) {
			tmp = curr;
			curr += prev;
			prev = tmp;
		}

		return curr;
	}
}

namespace Mem {
	// Memoization: The fastest solution:
	int climbStairs(int n, std::unordered_map<int, int>& memo) {
		if (n == 0 || n == 1) {
			return 1;
		}
		if (memo.find(n) == memo.end()) {
			memo[n] = climbStairs(n - 1, memo) + climbStairs(n - 2, memo);
		}
		return memo[n];
	}


	int climbStairs(int n) {
		std::unordered_map<int, int> memo;
		return climbStairs(n, memo);
	}
}

namespace DP {
	// Dinamic programing: Using n additional memory
	int climbStairs(int n) {
		std::vector<int> vec(n + 1, 1);

		for (size_t i = 2; i < n + 1; i++) {
			vec[i] = vec[i - 2] + vec[i - 1];
		}

		return vec[n];
	}
}

int main() {
	// Example 1:
	std::cout << SM::climbStairs(2) << '\n';

	// Example 2:
	std::cout << Mem::climbStairs(3) << '\n';

	// Example 3:
	std::cout << DP::climbStairs(4) << '\n';

	return 0;
}
