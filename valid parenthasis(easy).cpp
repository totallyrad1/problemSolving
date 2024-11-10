#include <iostream>

class Solution {
public:
    bool isValid(std::string s) {
        int i = 0;
        int start = -1;
        while(s[i]){
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                start = i;
            else if(start != -1 && (s[i] == ')' || s[i] == ']' || s[i] == '}')){
                if(i - start == 1 && ((s[i] == ')' && s[start] == '(') || (s[i] == ']' && s[start] == '[') || (s[i] == '}' && s[start] == '{'))){
                    s.erase(start, 2);
                    i = 0;
                    start = -1;
                    continue;
                }else
                    return false;
            }
            i++;
        }
        if(s == "")
            return true;
        return false;
    }
};

int main(){
    Solution sol;
    std::cout << sol.isValid("")<< std::endl;
}