// Task: https://leetcode.com/problems/pascals-triangle-ii/description/
#include<iostream>
#include<vector>

void printRow(std::vector<int> vec){
    for (size_t i = 0; i < vec.size(); i++){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

// The function works with index so the counting starts at 0 not at 1!
// For example if the input is 5  you will get -> 1 5 10 10 5 1, 
// instead of 1 4 6 4 1 which is the actual 5th row in the Pascal's Triangle!
std::vector<int> getRow(int rowIndex) {
    if (rowIndex < 0) {
        return {};
    }

    std::vector<std::vector<int>> triangle;

    for (int i = 0; i <= rowIndex; ++i) {
        std::vector<int> row(i + 1, 1);

        for (int j = 1; j < i; ++j) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        triangle.push_back(row);
    }

    return triangle[rowIndex];
}

int main(){
    unsigned rowIndex = 5;
    std::vector<int> row;
    // std::cin >> row;

    row = getRow(rowIndex);
    printRow(row);

    return 0;
}
