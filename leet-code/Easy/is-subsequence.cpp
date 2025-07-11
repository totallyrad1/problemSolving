class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        int j = 0;
        while(t[i] && s[j]){
            if(t[i] == s[j])
            {
                j++;
            }
            i++;
        }
        if(!s[j]) return true;
        return false;
    }
};