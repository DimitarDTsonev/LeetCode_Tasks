// Task : https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone/?envType=daily-question&envId=2024-06-13

#include <iostream>
#include <vector>
#include <algorithm>

int minMovesToSeat(std::vector<int>& seats, std::vector<int>& students) {
      sort(seats.begin(), seats.end());
      sort(students.begin(), students.end());
      int res = 0;
  
      for (int i = 0; i < seats.size(); i++) {
            res += std::abs(seats[i] - students[i])''
      }
    return res;
}

int main () {
    // Example 1:
    std::vector<int> s1 = { 3, 1, 5 };
    std::vector<int> st1 = { 2, 7, 4 };
    std::cout << minMovesToSeat(s1, st1) << '\n';

    // Example 2:
    std::vector<int> s2 = { 4, 1, 5, 9 };
    std::vector<int> st2 = { 1, 3, 2, 6 };
    std::cout << minMovesToSeat(s2, st2) << '\n';

    // Example 1:
    std::vector<int> s3 = { 2, 2, 6, 6 };
    std::vector<int> st3 = { 1, 3, 2, 6 };
    std::cout << minMovesToSeat(s3, st3) << '\n';
    
    return 0;
}
