class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
       std::set<int> res;
       int i = 0;
        while(i < nums.size())
            res.insert(nums[i++]);
        std::vector<int> vs(res.begin(), res.end());
        nums = vs;
       return res.size();
    }
};