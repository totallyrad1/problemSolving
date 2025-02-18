class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i =0; i < nums.size() ; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int left = i + 1, right = nums.size() - 1;
            while(left < right){
                int sum = nums[left] + nums[right] + nums[i];
                if(sum == 0){
                    ans.push_back({nums[left],nums[right], nums[i]});
                    while(left < right && nums[left] == nums[left + 1]) left++;
                    while(left < right && nums[right] == nums[right - 1]) right--;
                    left++;
                    right--;
                } else if(sum < 0){
                    left++;
                }else
                    right--;
            }
        }
        return ans;
    }
};