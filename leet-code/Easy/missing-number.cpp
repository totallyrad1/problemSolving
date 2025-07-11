class Solution {
public:
    int missingNumber(vector<int>& nums) {
        vector<int> saves = vector<int>(nums.size() + 1, -1);
        int i = 0;
        while(i < nums.size()){
            saves[nums[i]] = nums[i];
            i++;
        }
        i = 0;
        while(i < saves.size()){
            if(saves[i] == -1){
                return i;
            }
            i++;
        }

        return saves.size();
    }
};