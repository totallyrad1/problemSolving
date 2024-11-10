class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for(std::vector<int>::iterator it = nums.begin(); it != nums.end();){
            if(*it == val){
                nums.erase(it);
                continue;
            }else{
                ++it;
            }
        }
        return nums.size();
    }
};