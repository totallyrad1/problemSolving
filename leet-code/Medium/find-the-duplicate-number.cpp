class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       set<int> found;
       for(auto &it :nums){
            if(found.count(it)> 0)
                return it;
            found.insert(it);
        }
        return -1;
    }
};