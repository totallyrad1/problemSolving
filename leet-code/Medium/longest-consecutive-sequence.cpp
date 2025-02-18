class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int save;
        int flag = 0;
        int count = 1;
        int result= 0;
        for(auto &num: s){
            if(!flag){
                save = num;
                flag = 1;
            }else{
                if(abs(num - save) == 1){
                    count++;
                }else{
                    count = 1;
                }
                save = num;
            }
            if(count > result)
                result = count;
        }
        return result;
    }
};