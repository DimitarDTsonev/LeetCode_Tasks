// Task : https://leetcode.com/problems/crawler-log-folder/description/?envType=daily-question&envId=2024-07-10

#include <iostream>
#include <string>
#include <vector>

int minOperations(vector<string>& logs) {
    unsigned res = 0;
        
    for (auto& dir : logs) {
        if (dir == "../") {
            res -= (res > 0);
        }
        else if (dir != "./") {
            res++;
        }
    }
    return res;
}

int main() {
    // Example 1: 
    std::vector<std::string>> s1 = { "d1/", "d2/", "../", "d21/", "./" };
    std::cout << minOperations(s1) << '\n';

     // Example 2: 
    std::vector<std::string>> s2 = { "d1/", "d2/", "./", "d3/", "../", "d31/" };
    std::cout << minOperations(s2) << '\n';

     // Example 3: 
    std::vector<std::string>> s3 = { "d1/", "../", "../", "../" };
    std::cout << minOperations(s3) << '\n';
    
    return 0;
}
