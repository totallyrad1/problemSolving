class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> clear;
        for(auto num : nums){
            clear.insert(num);
        }
        nums = vector<int>(clear.begin(), clear.end());
        int index = nums.size() - 3;
        if(index >= 0) return nums[index];
        else return nums[nums.size() - 1];
    }
};