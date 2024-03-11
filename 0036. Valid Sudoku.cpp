// Task: https://leetcode.com/problems/valid-sudoku/description/

#include<iostream>
#include<vector>

bool isValidSudoku(std::vector<std::vector<char>>& board) {
	const short SIZE = 9;
	bool column[SIZE][SIZE] = { false };
	bool row[SIZE][SIZE] = { false };
	bool grid[SIZE][SIZE] = { false };
	int index = 0;
	int gNum = 0;

	for (size_t i = 0; i < SIZE; i++){
		for (size_t j = 0; j < SIZE; j++){
			if (board[i][j] == '.') {
				continue;
			}

			index = board[i][j] - '0' - 1;
			gNum = (i / 3) * 3 + (j / 3);

			if (row[i][index] || column[j][index] || grid[gNum][index]) {
				return false;
			}
		
			row[i][index] = true;
			column[j][index] = true;
			grid[gNum][index] = true;
		}
	}

	return true;
}

int main() {
	// Example 1:
	std::vector<std::vector<char>> mat1 = {
	{'5','3','.','.','7','.','.','.','.'},
	{'6','.','.','1','9','5','.','.','.'},
	{'.','9','8','.','.','.','.','6','.'},
	{'8','.','.','.','6','.','.','.','3'},
	{'4','.','.','8','.','3','.','.','1'},
	{'7','.','.','.','2','.','.','.','6'},
	{'.','6','.','.','.','.','2','8','.'},
	{'.','.','.','4','1','9','.','.','5'},
	{'.','.','.','.','8','.','.','7','9'}
	};

	std::cout << isValidSudoku(mat1) << "\n";

	// Example 2:
	std::vector<std::vector<char>> mat2 = {
	{'8','3','.','.','7','.','.','.','.'},
	{'6','.','.','1','9','5','.','.','.'},
	{'.','9','8','.','.','.','.','6','.'},
	{'8','.','.','.','6','.','.','.','3'},
	{'4','.','.','8','.','3','.','.','1'},
	{'7','.','.','.','2','.','.','.','6'},
	{'.','6','.','.','.','.','2','8','.'},
	{'.','.','.','4','1','9','.','.','5'},
	{'.','.','.','.','8','.','.','7','9'}
	};

	std::cout << isValidSudoku(mat2) << "\n";

	return 0;
}
