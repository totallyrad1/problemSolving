class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int ans = nums[0];
        while(left <= right){
            int mid = (right + left) / 2;
            if(nums[mid] < nums[0]){
                ans = nums[mid];
                right = mid -1;
            }else
                left = mid + 1;
        }
        return ans;
    }
};