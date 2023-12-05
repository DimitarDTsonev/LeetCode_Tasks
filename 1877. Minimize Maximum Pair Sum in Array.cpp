#include<iostream>
#include<vector>
#include<algorithm>

// // First way: sorting the vector and using additional vector for the sum of the pairs: 
int minPairSum1(std::vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    std::vector<int> paired;

    for (size_t i = 0; i < nums.size() / 2; i++) {
        paired.push_back(nums[i] + nums[nums.size() - 1 - i]);
    }

    int max = 0;
    for (size_t i = 0; i < paired.size(); i++) {
        if (max < paired[i]) {
            max = paired[i];
        }
    }
    return max;
}

// Second way using a container like a hash: the 
int minPairSum2(std::vector<int>& nums) {
    int max = INT_MIN;
    int min = INT_MAX;
    int hash[100001] = {0};

    // Initialising 1 at the index of the number we have in the vector
    for (int num : nums) {
        hash[num]++;
        max = std::max(max, num);
        min = std::min(min, num);
    }

    int low = min;
    int high = max;
    max = INT_MIN;
    while (low <= high) {
        if (hash[low] == 0) low++;
        else if (hash[high] == 0) high--;
        else {
            max = std::max(max, low + high);
            hash[low]--;
            hash[high]--;
        }
    }

    return max; 
}

int main(){
    // Tests:
    std::vector<int> v{3,5,4,2,4,6};
    std::vector<int> v1{3,5,2,3};
    
    std::cout << minPairSum1(v) << std::endl;
    std::cout << minPairSum1(v1) << std::endl;
    std::cout << minPairSum2(v) << std::endl;
    std::cout << minPairSum2(v1) << std::endl;

    return 0;
}
