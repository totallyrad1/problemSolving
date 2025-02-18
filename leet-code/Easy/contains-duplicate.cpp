class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> saves;
        for(auto &num: nums){
            if(saves.count(num) > 0)
                return true;
            saves.insert(num);
        }
        return false;
    }
};