class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> count;
        for(auto &num: nums){
            if(count.find(num) == count.end()){
                count.insert({num,1});
            }else{
                count[num]++;
            }
        }
        int res;
        int highetOcc = -1;
        for(auto &[num,count] : count){
            if(count > highetOcc){
                res = num;
                highetOcc = count;
            }
        }
        return res;
    }
};