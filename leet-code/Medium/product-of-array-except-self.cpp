class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        long long sum = 1;
        vector<int> ans(nums.size());
        for(int i = 0; i < nums.size(); i++){
            sum *= nums[i];
        }
        for(int i = 0; i < nums.size(); i++){
            if(nums[i])
                ans[i] = sum / nums[i];
            else{
                for(int x = 0; x < nums.size(); x++){
                    int res = 1;
                    for(int j = 0; j < nums.size(); j++){
                        if(x != j)
                            res *= nums[j];
                    }
                    ans[x] = res;
                }
            }
        }
        return ans;
    }
};