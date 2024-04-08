// Task : https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/?envType=daily-question&envId=2024-04-08

#include<iostream>
#include<vector>
#include<queue>

bool contains(std::vector<int> arr, int num){
    for(size_t i = 0; i < arr.size(); i++){ 
        if(arr[i] == num){
            return true;
        }
    }
    return false;
}

void popFront(std::vector<int>& vec){
    for (size_t i = 0; i < vec.size() - 1; i++){
        vec[i] = vec[i + 1];
    }
    vec.pop_back();
}

int countStudents(std::vector<int>& students, std::vector<int>& sandwiches){        
    while(contains(students, sandwiches[0])){
        if(students[0] == sandwiches[0]){
            popFront(students);
            popFront(sandwiches);
        }
        else{
            students.push_back(students[0]);
            popFront(students);
        }
    }
    return students.size();
}

int main(){
    std::vector<int> st{1,1,1,0,0,1};
    std::vector<int> sandwiches{1,0,0,0,1,1};
    std::cout << countStudents(st, sandwiches) << std::endl;

    std::vector<int> st1{1,1,0,0,};
    std::vector<int> sandwiches1{0,1,0,1};
    std::cout << countStudents(st1, sandwiches1) << std::endl;

    return 0;
}
