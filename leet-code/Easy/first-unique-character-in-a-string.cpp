class Solution {
public:
    int firstUniqChar(string s) {
        int i = 0;
        while(s[i]){
            char save = s[i];
            s[i] = -1;
            if(s.find(save) == string::npos) return i;
            s[i] = save;
            i++;
        }
        return -1;
    }
};