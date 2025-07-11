class Solution {
public:
    int isV(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c =='u') return true;
        if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c =='U') return true;
        return false;
    }
    string reverseVowels(string s) {
        int st = 0;
        int e = s.size() - 1;
        
        while(st < e){
            if(isV(s[st]) && isV(s[e])){
                char temp = s[st];
                s[st] = s[e];
                s[e] = temp;
                st++;
                e--;
            }
            if(!isV(s[st]))
                st++;
            if(!isV(s[e]))
                e--;
        }
        return s;
    }
};