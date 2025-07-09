class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res;
        vector<int> curr = {1};
        int index = 0;
        while(index <= rowIndex){
            vector<int> temp = {};
            if(index == 0){
                res.push_back({1});
            }else{
                temp.push_back(curr[0]);
                int i = 0;
                while(i + 1 < curr.size()){
                    temp.push_back(curr[i] + curr[i +1]);
                    i++;
                }
                temp.push_back(curr[curr.size() - 1]);
                curr = temp;
            }
            index++;
        }
        return curr;
    }
};