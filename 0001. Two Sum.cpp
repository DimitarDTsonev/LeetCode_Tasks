#include<iostream>
#include<vector>

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::vector<int> result;

	for (size_t i = 0; i < nums.size(); i++) {
		for (size_t j = i + 1; j < nums.size(); j++) {
			if (nums[i] + nums[j] == target) {
				result.push_back(i);
				result.push_back(j);
				return result;
            }
		}
	}
	return result;
}

void printVec(std::vector<int>& vec){
    for (size_t i = 0; i < vec.size(); i++){
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
}

int main() {
    // Test 1:
    std::vector<int> vec1 = { 2, 7, 11, 15 }, result1;
    int target1 = 9;
    result1 = twoSum(vec1, target1);
    printVec(result1);

    // Test 2:
    std::vector<int> vec2 = { 3, 2, 4 }, result2;
    int target2 = 6;
    result2 = twoSum(vec2, target2);
    printVec(result2);

    // Test 3:
    std::vector<int> vec3 = { 3, 3 }, result3;
    int target3 = 6;
    result3 = twoSum(vec3, target3);
    printVec(result3);

    return 0;
}
