class Solution {
public:
    int checkAndMark(char c , string &magazine){
        int i = 0;
        while(magazine[i]){
            if(magazine[i] == c) {
                magazine[i] = -1;
                return 1;
            }
            i++;
        }
        return 0;
    }
    bool canConstruct(string ransomNote, string magazine) {
        int i = 0;
        while(ransomNote[i]){
            if(checkAndMark(ransomNote[i], magazine) == 0) return false;
            // cout << magazine << endl;
            i++;
        }
        return true;
    }
};