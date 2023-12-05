#include<iostream>
#include<string>
#include<stack>
#include<vector>

// Standart solution using stack:
int calculate(std::string s) {
    s += '+';
    std::stack<int> stk; 
    
    long long int ans = 0, curr = 0;
    char sign = '+'; 
    
    for(int i=0; i<s.size(); i++){
        if(isdigit(s[i])) {
            curr = curr*10 + (s[i]-'0');
        }             
        else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){   
            if(sign == '+') {
                stk.push(curr);
            }
            else if(sign == '-') {
                stk.push(curr*(-1)); 
            }
            else if(sign == '*'){
                int num = stk.top(); 
                stk.pop(); 
                stk.push(num*curr); 
            }
            else if(sign == '/'){
                int num = stk.top();
                stk.pop(); 
                stk.push(num/curr);  
            }
            curr = 0; 
            sign = s[i]; 
        }
    }
    
    while(stk.size()){
        ans += stk.top();
        stk.pop();
    }
            
    return ans;    
}

// Faster method using vector:
//int calculate(std::string s) {
    //     char op = '+'; 
    //     int curr = 0; 
    //     std::vector<int> stk; 
        
    //     for (int i = 0; i < s.size(); ++i) {
            
    //         if(isdigit(s[i])) curr = curr*10 + (s[i] - '0'); 
            
    //         if(i==s.size()-1 || s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
    //             if (op == '+') stk.push_back(curr); 
    //             else if (op == '-') stk.push_back(curr*(-1)); 
    //             else if (op == '*'){
    //                 int num = stk.back();
    //                 stk.pop_back();
    //                 stk.push_back(num * curr);
    //             }
    //             else if (op == '/'){
    //                 int num = stk.back();
    //                 stk.pop_back();
    //                 stk.push_back(num / curr); 
    //             }
                
    //             curr = 0;
    //             op = s[i];      
    //         }
    //     }
    //     return accumulate(stk.begin(), stk.end(), 0); 
//}

int main(){
    // Example 1:
    std::string e1("3+2*2");
    std::cout << calculate(e1) << std::endl;

    // Example 2:
    std::string e2("3/2");
    std::cout << calculate(e2) << std::endl;

    // Example 3:
    std::string e3("3+5/2");
    std::cout << calculate(e3) << std::endl;

    return 0;
}
