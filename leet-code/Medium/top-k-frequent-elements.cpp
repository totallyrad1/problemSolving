class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> count;
        for(auto &num:nums){
            count[num]++;
        }
        vector<pair<int,int>> count1;
        for(auto &[key, value]: count){
            count1.push_back({value,key});
        }
        sort(count1.rbegin(), count1.rend());
        vector<int> ans(k);        
        for(int i = 0; i < k ; i++){
            ans[i] = count1[i].second;
        }
        return ans;
    }
};