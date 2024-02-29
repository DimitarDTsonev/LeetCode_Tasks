// Task: https://leetcode.com/problems/number-of-recent-calls/description/?envType=study-plan-v2&envId=leetcode-75

#include<queue>

class RecentCounter {
public:
    std::queue<int> requests;

    RecentCounter() {}

    int ping(int t) {
        requests.push(t);

        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();
        }

        return requests.size();
    }
};

int main() {
  // Example 1:
  RecentCounter recentCounter = new RecentCounter();
  std::cout << recentCounter.ping(1) << " ";
  std::cout << recentCounter.ping(100) << " ";
  std::cout << recentCounter.ping(3001) << " ";
  std::cout << recentCounter.ping(3002) << " ";
  
  return 0;
}
