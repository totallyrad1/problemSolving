class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> ans(temperatures.size(), 0);
        stack<pair<int,int>> s;
        for(int i = temperatures.size() - 1; i > -1; i--){
            while(!s.empty() && s.top().first <= temperatures[i]){
                s.pop();
            }
            if(!s.empty()){
                ans[i] =  s.top().second - i;
            }
            s.push({temperatures[i], i});
        }
        return ans;
    }
};