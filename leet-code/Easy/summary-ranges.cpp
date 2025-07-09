class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;
        int i = 0;
        while(i < nums.size()){
            int start = nums[i];
            int last = 0;
            i++;
            int count = 0;
            while(i < nums.size() && nums[i] == nums[i - 1] + 1){
                last = nums[i];
                count++;
                i++;
            }
            if(count > 0){
                res.push_back(to_string(start) + "->" + to_string(last));
            }else{
                res.push_back(to_string(start));
            }
        }
        return res;
    }
};