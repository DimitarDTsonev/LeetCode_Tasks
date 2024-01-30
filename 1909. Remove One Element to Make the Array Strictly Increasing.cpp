// Task: https://leetcode.com/problems/remove-one-element-to-make-the-array-strictly-increasing/description/

bool canBeIncreasing(std::vector<int>& nums) {
    int holder = 0, iter = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] <= nums[i - 1]) {
            std::vector<int>::iterator it = std::find(nums.begin(), nums.end(), nums[i - 1]);
            holder = nums[i - 1];
            iter = i - 1;
            nums.erase(it);
            break;
        }
    }

    bool is = false;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] <= nums[i - 1]) {
            is = true;
            break;
        }
    }

    if (is) {
        nums[iter] = holder;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] <= nums[i - 1]) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    // Example 1:
    std::vector<int> vec = { 1, 2, 10, 5, 7 };
    std::cout << canBeIncreasing(vec) << " ";

    // Example 2:
    std::vector<int> vec1 = { 105, 924, 32, 968 };
    std::cout << canBeIncreasing(vec1) << " ";

    // Example 3:
    std::vector<int> vec2 = { 1, 1, 1 };
    std::cout << canBeIncreasing(vec2) << " ";

    // Example 4:
    std::vector<int> vec3 = { 13,205,553,527,790,238 };
    std::cout << canBeIncreasing(vec3) << " ";

    return 0;
}
