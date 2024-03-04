// Task: https://leetcode.com/problems/bag-of-tokens/description/?envType=daily-question&envId=2024-03-04

#include<iostream>
#include<vector>
#include<algorithm>

int bagOfTokensScore(std::vector<int>& tokens, int power) {
    int size = tokens.size();
    int max = 0;
    int curr = 0;
    int left = 0;
    int right = size - 1;
    sort(tokens.begin(), tokens.end());

    while (left <= right) {
        if (power >= tokens[left]) {
            power -= tokens[left];
            ++curr;
            ++left;
            max = std::max(max, curr);
        }
        else if(curr > 0){
            power += tokens[right];
            --curr;
            --right;
        }
        else {
            break;
        }
    }

    return max;
}

int main() {
    // Example 1:
    std::vector<int> vec1 = { 100 };
    std::cout << bagOfTokensScore(vec1, 50) << "\n";

    // Example 2:
    std::vector<int> vec2 = { 200, 100 };
    std::cout << bagOfTokensScore(vec2, 150) << "\n";

    // Example 3:
    std::vector<int> vec3 = { 100, 200, 300, 400 };
    std::cout << bagOfTokensScore(vec3, 200) << "\n";

	return 0;
}
