class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // int i = 0;
        // while()
        vector<int> res;
        int i = 0;
        int size = nums.size();
        int maxVal = max(size, nums[nums.size() - 1]); 
        vector<int> saves = vector<int>(nums.size() + 1, -1);
        // int i = 0;
        while(i < nums.size()){
            saves[nums[i]] = nums[i];
            i++;
        }
        i = 0;
        while(i < saves.size()){
            if(saves[i] == -1 && i > 0){
                res.push_back(i);
            }
            i++;
        }
        // if(maxVal != nums[nums.size() - 1]) res.push_back(maxVal);
        return res;
    }
};