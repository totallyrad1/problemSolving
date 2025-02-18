class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size() - 1;
        while(start < s.size() && !isalnum(s[start]))
                start++;
        while(end >= 0 && !isalnum(s[end]))
            end--;
        while(start < end){
            if(tolower(s[start]) != tolower(s[end]))
                return false;
            start++;
            end--;
            while(start < s.size() && !isalnum(s[start]))
                start++;
            while(end >= 0 && !isalnum(s[end]))
                end--;
        }
        return true;
    }
};