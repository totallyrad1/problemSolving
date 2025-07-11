class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 1) return false;
        if(n == 1) return true;
        int i = 1;
        int count = 0;
        while(i <= n && count < 15){
            if(i * 4 == n) return true;
            i *= 4;
            count++;
        }

        return false;
    }
};