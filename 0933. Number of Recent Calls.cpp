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
  std::cout << recentCounter.ping(1) << " ";     // requests = [1], range is [-2999,1], return 1
  std::cout << recentCounter.ping(100) << " ";   // requests = [1, 100], range is [-2900,100], return 2
  std::cout << recentCounter.ping(3001) << " ";  // requests = [1, 100, 3001], range is [1,3001], return 3
  std::cout << recentCounter.ping(3002) << " ";  // requests = [1, 100, 3001, 3002], range is [2,3002], return 3
  
  return 0;
}
