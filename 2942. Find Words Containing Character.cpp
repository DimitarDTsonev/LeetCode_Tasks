// Task : https://leetcode.com/problems/find-words-containing-character/description/?envType=daily-question&envId=2025-05-24

std::vector<int> findWordsContaining(std::vector<std::string>& words, char x) {
    std::vector<int> res;
    for (int i = 0; i < words.size(); i++) {
        for(int j = 0; j < words[i].length(); j++) {
            if (words[i][j] == x) {
                res.push_back(i);
                break;
            }
        }
    }     
    return res;
}

void printVec(const std::vector<int>& vec) {
    for (int num : vec) {
        std::cout << num << " ";
    }
    std::cout << '\n';
}

int main() {
    // Example 1:
    std::vector<std::string> words1 = { "leet", "code" };
    std::vector<int> vec1 = findWordsContaining(words1, 'e');
    printVec(vec1);
    
    // Example 2:
    std::vector<std::string> words2 = { "abc", "bcd", "aaaa", "cbc" };
    std::vector<int> vec2 = findWordsContaining(words2, 'a');
    printVec(vec2);

    // Example 3:
    std::vector<std::string> words3 = { "abc", "bcd", "aaaa", "cbc" };
    std::vector<int> vec3 = findWordsContaining(words3, 'z');
    printVec(vec3);
    
    return 0;
}
