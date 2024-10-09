// Task : https://leetcode.com/problems/sort-the-people/description/?envType=problem-list-v2&envId=an1rjax7

#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

std::vector<std::string> sortPeople(std::vector<std::string>& names, std::vector<int>& heights) {
    int size = names.size();
    std::vector<std::pair<int, std::string>> data(size);
    for (size_t i = 0; i < size; i++) {
        data[i] = { heights[i], names[i]};
    }

    std::sort(data.begin(), data.end(), std::greater<>());

    for (size_t i = 0; i < size; i++) {
        names[i] = data[i].second;
    }

    return names;
}

void printVec(const std::vector<std::string>& vec) {
    for (size_t i = 0; i < vec.size(); i++){
        std::cout << vec[i] << " ";
    }
    std::cout << "\n";
}

int main()
{
	// Example 1:
    std::vector<std::string> names1 = { "Mary", "John", "Emma" };
    std::vector<int> heights1 = { 180, 165, 170 };
    sortPeople(names1, heights1);
    printVec(names1);

    // Example 2:
    std::vector<std::string> names2 = { "Alice", "Bob", "Bob" };
    std::vector<int> heights2 = { 155, 185, 150 };
    sortPeople(names2, heights2);
    printVec(names2);
}
