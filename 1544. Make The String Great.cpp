#include<iostream>
#include<string> 

std::string makeGood(std::string& s) {
    for (int i = 0; i < s.size(); ++i){
        if(s[i] == s[i + 1] + 32 || s[i] == s[i + 1] - 32){
            for (int j = i; j < s.size() - 1; j++){
                s[j] = s[j + 2];
            }
            s.pop_back();
            s.pop_back();
            i = -1;
        }
    } 
    return s;
}

int main() {
    // Example 1:
    std::string s1("leEeetCode");
    std::cout << makeGood(s1) << std::endl;

    // Example 2:
    std::string s2("abBAcC");
    std::cout << makeGood(s2) << std::endl;

    //Example 3:
    std::string s3("s");
    std::cout << makeGood(s3) << std::endl;
    
    return 0;
}
