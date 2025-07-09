class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int , vector<int>> seen;
        int i = 0;
        while(i < nums.size()){
            if(seen.find(nums[i]) != seen.end()){
                vector<int> toCheck = seen[nums[i]];
                for(auto n: toCheck){
                    if(abs(n - i) <= k){
                        return true;
                    }
                }
                seen[nums[i]].push_back(i);
            }else{
                seen.insert({nums[i],{i}});
            }
            i++;
        }
        return false;
    }
};