class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> ans;
        for(auto &token : tokens){
            if(token == "*" || token == "-" || token == "/" || token == "+"){
                int n2 = ans.top();
                ans.pop();
                int n1 = ans.top();
                ans.pop();
                if(token == "+")
                    ans.push(n1 + n2);
                if(token == "-")
                    ans.push(n1 - n2);
                if(token == "/")
                    ans.push(n1 / n2);
                if(token == "*")
                    ans.push(n1 * n2);
            }else{
                stringstream ss(token);
                int num;
                ss >> num;
                ans.push(num);
            }
        }
        return ans.top();
    }
};