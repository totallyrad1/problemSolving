class Solution {
public:
    int mySqrt(int x) {
        int i = 0;
        while(i < 46340 && i * i <= x){
            if((i + 1) * (i + 1) > x) return i;
            i++;
        }
        return i;
    }
};