// Task : https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/?envType=daily-question&envId=2025-07-13

#include <iostream>
#include <vector>
#include <algorithm>

int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    std::sort(players.begin(), players.end());
    std::sort(trainers.begin(), trainers.end());

    int cnt = 0;
    int iterP = 0;
    int iterT = 0;

    while (iterP < players.size() && iterT < trainers.size()) {
        if (players[iterP] <= trainers[iterT]) {
            ++cnt;
            ++iterP;
        }
            
        ++iterT;
    }

    return cnt;
}

int main() {
    // Example 1:
    std::vector<int> players1 = { 4, 7, 9 };
    std::vector<int> trainers1 = { 8, 2, 5, 8 };
    std::cout << matchPlayersAndTrainers(players1, trainers1) << '\n';

    // Example 2:
    std::vector<int> players2 = { 1, 1, 1 };
    std::vector<int> trainers2 = { 10 };
    std::cout << matchPlayersAndTrainers(players2, trainers2) << '\n';
    
    return 0;
}
