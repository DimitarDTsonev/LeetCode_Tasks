#include<iostream>
#include<vector>

int timeRequiredToBuy(std::vector<int>& tickets, int k){
    unsigned time = 0, i = 0;
    while(tickets[k] != 0){
        if(i == tickets.size() - 1){
            if(tickets[i] == 0){
                i = 0;
            }
            else{
                --tickets[i];
                ++time;
                i = 0;
            }
        }
        else{
            if(tickets[i] == 0){
                ++i;
            }
            else{
                --tickets[i];
                ++i;
                ++time;
            }
        }
    }
    return time;
}


int main() {
    std::vector<int> v{2,3,2};
    std::cout << timeRequiredToBuy(v, 2) << std::endl;

     std::vector<int> v1{5,1,1,1};
    std::cout << timeRequiredToBuy(v1, 0) << std::endl;
    return 0;
}