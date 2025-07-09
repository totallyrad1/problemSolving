class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int, int> count;
        for(auto &num : nums){
            if(count.find(num) == count.end()){
                count.insert({num, 0});
            }
            count[num]++;
        }
        for(auto [num, count] : count){
            if(count == 1){
                return num;
            }
        }
        return 0;
    }
};