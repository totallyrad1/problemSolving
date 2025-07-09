class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for(auto &c : columnTitle){
            result = result * 26 + ((c - 'A') + 1);
        }
        return result;
    }
};