class Solution {
public:
    int lengthOfLastWord(string s) {
            int i = s.size() - 1;
            while(std::isspace(s[i]))
                i--;
            int start = i;
            while(i >= 0){
                if(std::isspace(s[i]))
                    return start - i;
                i--; 
            }
        return start - i;
    }
};