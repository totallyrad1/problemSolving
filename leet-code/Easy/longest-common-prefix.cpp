class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string res = "";
        int index = 0;
        while(strs[0][index]){
            char save = strs[0][index];
            for(auto &str: strs){
                if(str.size() > index){
                    if(str[index] != save)  return res;
                }else{
                    return res;
                }
            }
            index++;
            res += save;
        }
        return res;
    }
};