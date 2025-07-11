class Solution {
public:
    string res = "";
    string base = "0123456789abcdef";
    void makeHex(unsigned int num){
        if(num < 16){
            res += base[num];
        }else{
            makeHex(num /16);
            makeHex(num % 16);
        }
    }

    string toHex(int num) {
        if(num == -1) return "ffffffff";
        makeHex((unsigned int)num);
        return res;
    }
};