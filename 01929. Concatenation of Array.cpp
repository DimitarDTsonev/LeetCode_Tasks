#include<iostream>>
#include<vector>

std::vector<int> getConcatenation(std::vector<int>& nums) {
    unsigned n = nums.size();
    std::vector<int> newNums(nums);
    for(int i = 0; i < n; i++){
        newNums.push_back(nums[i]);
    }
    return newNums;
}

int main(){
    // Example 1:
    std::vector<int> v{ 1, 2, 1 };
    v = getConcatenation(v);
    for (size_t i = 0; i < v.size(); i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
    
    // Example 2:
    std::vector<int> v1{ 1, 3, 2, 1 };
    v1 = getConcatenation(v1);
    for (size_t i = 0; i < v1.size(); i++) {
        std::cout << v1[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}