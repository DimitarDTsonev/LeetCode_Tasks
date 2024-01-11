// Task: https://leetcode.com/problems/median-of-two-sorted-arrays/

#include <iostream>
#include <vector>

double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int x = nums1.size();
    int y = nums2.size();
    int low = 0;
    int high = x;
    double median = 0;

    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];

        int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if (maxX <= minY && maxY <= minX) {
            if ((x + y) % 2 == 0) {
                median = (std::max(maxX, maxY) + std::min(minX, minY)) / 2.0;
                break;
            }
            else {
                median = std::max(maxX, maxY);
                break;
            }
        }
        else if (maxX > minY) {
            high = partitionX - 1;
        }
        else {
            low = partitionX + 1;
        }
    }
    return median;
}

int main() {
    // Test 1:
    std::vector<int> nums1 = { 1, 3 };
    std::vector<int> nums2 = { 2 };

    std::cout << "Median: " << findMedianSortedArrays(nums1, nums2) << std::endl;

    // Test 2:
    std::vector<int> nums3 = { 1, 2 };
    std::vector<int> nums4 = { 3, 4 };

    std::cout << "Median: " << findMedianSortedArrays(nums3, nums4) << std::endl;

    return 0;
}
