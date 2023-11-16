#include <iostream>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>

std::string findDifferentBinaryString(std::vector<std::string>& nums) {
    const int sizeOfBinaryNum = nums[0].size();
    std::string toReturn;  // Initialize with '0'

    std::vector<int> toDecimal;
    for (size_t i = 0; i < nums.size(); i++) {
        toDecimal.push_back(std::stoi(nums[i], 0, 2));  // Use nums[i] instead of nums[0]
    }

    int maxDecimal = 0;
    for (size_t i = 0; i < toDecimal.size(); i++) {
        maxDecimal = std::max(maxDecimal, toDecimal[i]);  // Fix the maxDecimal calculation
    }

    int decResult = 0;
    bool found = false;
    for (size_t i = 0; i < maxDecimal + pow(2, sizeOfBinaryNum); i++) {
        for (size_t j = 0; j < toDecimal.size(); j++) {
            if (i == toDecimal[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            decResult = i;
            break;
        }
        found = false;
    }

    std::string binaryString = std::bitset<16>(decResult).to_string();

    for (size_t i = 16 - sizeOfBinaryNum; i < 16; ++i) {
        toReturn.push_back(binaryString[i]);
    }

    return toReturn;
}

int main() {
    std::vector<std::string> nums = { "0000", "0001", "0010" };

    std::string result = findDifferentBinaryString(nums);

    std::cout << "Different Binary String: " << result << std::endl;

    return 0;
}