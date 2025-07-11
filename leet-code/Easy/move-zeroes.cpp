class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()){
            int j = 0;
            while(j + 1< nums.size()){
                if(nums[j] == 0){
                    nums[j] = nums[j +1];
                    nums[j + 1] = 0;
                }
                j++;
            }
            i++;
        }
    }
};