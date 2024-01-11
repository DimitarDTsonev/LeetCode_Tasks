// Task: https://leetcode.com/problems/string-to-integer-atoi/description/

#include<iostream>
#include<string>

int myAtoi(std::string s) {
        int toReturn = 0;

        int it = 0;
        while(it < s.size() && s[it] == ' ') { ++it; }
        bool isNegative = (s[it] == '-');

        if(isNegative || s[it] == '+') { ++it; }

        while(it < s.size() && s[it] == '0') { ++it; }

        while(it < s.size())
        {
            if(!std::isdigit(s[it])) { break; }

            if(INT_MAX / 10 < toReturn)
            {
                toReturn = (isNegative ? INT_MIN : INT_MAX);
                return toReturn;
            }

            toReturn *= 10;

            if(INT_MAX - (s[it] -'0') < toReturn)
            {
                toReturn = (isNegative ? INT_MIN : INT_MAX);
                return toReturn;
            }

            toReturn += s[it] -'0';
            ++it;
        }
        if(isNegative) { return -toReturn; }
        return toReturn;
    }

int main(){
    // Example 1:
    std::string s1 { "42" };
    std::cout << myAtoi(s1) << std::endl;

    // Example 2:
    std::string s2 { "   -42" };
    std::cout << myAtoi(s2) << std::endl;

    // Example 3:
    std::string s3 { "4193 with words" };
    std::cout << myAtoi(s3) << std::endl;
    
    return 0;
}
