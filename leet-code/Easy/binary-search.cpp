class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while(left <= right){
            int median = (right + left) / 2;
            if(nums[median] == target)
                return median;
            if(target > nums[median]){
                left = median + 1;
            }else{
                right = median -1;
            }

        }
        return -1;
    }
};