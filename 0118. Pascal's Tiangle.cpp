// Task: https://leetcode.com/problems/pascals-triangle/description/ 
#include<iostream>
#include<vector>

void print(std::vector<std::vector<int>> vec){
    unsigned length = vec.size();
    for (size_t i = 0; i < length; i++) {
        unsigned lengthi = vec[i].size();
        for (size_t j = 0; j < lengthi; j++) {
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;        
    }
}

std::vector<std::vector<int>> generate(int numRows) {
    std::vector<std::vector<int>> triangle;

    for (int i = 0; i < numRows; ++i) {
        std::vector<int> row(i + 1, 1);
        for (int j = 1; j < i; ++j) {
            row[j] = triangle[i - 1][j - 1] + triangle[i - 1][j];
        }

        triangle.push_back(row);
    }

    return triangle;
}

int main(){
    int numRows = 5;
    std::vector<std::vector<int>> toReturn;

    //std::cin >> numRows;
    toReturn = generate(numRows);
    print(toReturn);

    return 0;
}
