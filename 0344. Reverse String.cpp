// Task : https://leetcode.com/problems/reverse-string/description/

#include <iostream>
#include <vector>

void reverseString(std::vector<char>& s) {
    int i = 0;
    int j = s.size() - 1;

    while(i < j){
        std::swap(s[i++], s[j--]);
    }
}

void printVec(const std::vector<char>& vec) {
    for(size_t i = 0; i < vec.size(); i++){
        std::cout << vec[i] << " ";
    }
    std::cout << '\n';
}

int main() {
    // Example 1:
    std::vector<char> vec1 = { 'h', 'e', 'l', 'l', 'o' }; 
    reverseString(vec1);
    printVec(vec1);

    // Example 2:
    std::vector<char> vec2 = { 'H', 'a', 'n', 'n', 'a', 'h' }; 
    reverseString(vec2);
    printVec(vec2);    

    return 0;
}
