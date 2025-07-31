// Task : https://leetcode.com/problems/bitwise-ors-of-subarrays/description/?envType=daily-question&envId=2025-07-31

#include <iostream>
#include <vector>

int subarrayBitwiseORs(std::vector<int>& arr) {
    int size = arr.size();
    std::unordered_set<int> st;

    for (int i = 0; i < size; i++) {
        st.insert(arr[i]);
        for (int j = i - 1; j >= 0; j--) {
            if ((arr[i] | arr[j]) == arr[j]) {
                break;
            }
            arr[j] |= arr[i];
            st.insert(arr[j]);
        }
    }

    return st.size();
}

int main() {
    //Exampl 1:
    std::vector<int> vec1 = { 0 };
    std::cout << subarrayBitwiseORs(vec1) << '\n';
    
    //Exampl 2:
    std::vector<int> vec2 = { 1, 1, 2 };
    std::cout << subarrayBitwiseORs(vec2) << '\n';

    //Exampl 1:
    std::vector<int> vec3 = { 1, 1, 4 };
    std::cout << subarrayBitwiseORs(vec3) << '\n';
    
    return 0;
}
