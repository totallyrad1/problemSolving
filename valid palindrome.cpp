class Solution {
public:
    bool isPalindrome(std::string s) {
        std::string str = "";
        int i = 0;
        while(s[i]){
            if(s[i] >= 'a' && s[i] <= 'z'){
                str += s[i];
            }else if (s[i] >= 'A' && s[i] <= 'Z'){
                str += s[i] + 32;
            }else if(s[i] >= '0' && s[i] <= '9'){
                str += s[i];
            }
            i++;
        }
        i = 0;
        int size = str.size() - 1;
        while(i < size){
            if(str[i] != str[size])
                return false;
            i++;
            size--;
        }
        return true;
    }
};