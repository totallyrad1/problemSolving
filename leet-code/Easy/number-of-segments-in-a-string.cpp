class Solution {
public:
    int countSegments(string s) {
        int count = 0;
        int i = 0;
        while(s[i]){
            while(s[i] == ' ') i++;
            if(s[i])  count++;
            while(s[i] != ' ' && s[i]) i++;   
        }
        return count;
    }
};