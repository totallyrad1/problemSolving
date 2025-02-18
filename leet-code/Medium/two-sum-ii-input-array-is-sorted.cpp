class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int start = 0;
        set<int> dp;
        while(start < numbers.size()){
            int end = numbers.size() - 1;
            if(dp.count(numbers[start]) > 0){
                start++;
                continue;
            }
            while(end > start){
                if(numbers[end] + numbers[start] == target)
                    return {start+ 1,end + 1};
                end--;
            }
            dp.insert(numbers[start]);
            start++;
        }
        return {};
    }
};