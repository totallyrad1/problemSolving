class Solution {
public:
    vector<string> result;
    int num;
    string s;

    void dfs(int left, int right){
        if(s.size() == num * 2){
            result.push_back(s);
            return ;
        }
        if(left < num) {
            s += "(";
            dfs(left + 1, right);
            s.pop_back();
        }
        if(right < left) {
            s += ")";
            dfs(left, right + 1);
            s.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        num = n;
        dfs(0,0);
        return result;
    }
};