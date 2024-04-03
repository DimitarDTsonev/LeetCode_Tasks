// Task: https://leetcode.com/problems/word-search/?envType=daily-question&envId=2024-04-03

#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
	bool exist(std::vector<std::vector<char>>& board, std::string word) {
		for (int i = 0; i < board.size(); i++)
			for (int j = 0; j < board[0].size(); j++)
				if (dfs(board, word, i, j, 0))
					return true;
		return false;
	}
private:
	bool dfs(std::vector<std::vector<char>>& board, const std::string& word, int i, int j, int s) {
		if (i < 0 || i == board.size() || j < 0 || j == board[0].size())
			return false;
		if (board[i][j] != word[s] || board[i][j] == '*')
			return false;
		if (s == word.length() - 1)
			return true;

		const char cache = board[i][j];
		board[i][j] = '*';
		const bool exists = dfs(board, word, i + 1, j, s + 1) ||
			dfs(board, word, i - 1, j, s + 1) ||
			dfs(board, word, i, j + 1, s + 1) ||
			dfs(board, word, i, j - 1, s + 1);
		board[i][j] = cache;
		return exists;
	}
};

int main() {
	// Example 1:
	Solution s1;
	std::vector<std::vector<char>> mat1 = { {'A','B','C','E'} ,{ 'S', 'F', 'C','S' }, {'A', 'D', 'E', 'E'} };
	std::cout << s1.exist(mat1, "ABCCED") << "\n";

	// Example 2:
	Solution s2;
	std::vector<std::vector<char>> mat2	 = { {'A','B','C','E'} ,{ 'S', 'F', 'C','S' }, {'A', 'D', 'E', 'E'} };
	std::cout << s2.exist(mat2, "SEE") << "\n";

	// Example 3:
	Solution s3;
	std::vector<std::vector<char>> mat3 = { {'A','B','C','E'} ,{ 'S', 'F', 'C','S' }, {'A', 'D', 'E', 'E'} };
	std::cout << s3.exist(mat3, "ABCD") << "\n";

	return 0;
}
