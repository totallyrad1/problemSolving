class Solution {
public:
    bool isValid(string s) {
        stack<char> ans;
        for(auto &c: s){
            if(c == '(' || c == '{' || c == '[') ans.push(c);
            else{
                if(ans.empty()) return false;
                if(c == ')' && ans.top() != '(' 
                ||  c == ']' && ans.top() != '[' || 
                    c == '}' && ans.top() != '{') return false;
                ans.pop();
            }
        }
        if(!ans.empty())
            return false;
        return true;
    }
};