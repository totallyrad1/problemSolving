class Solution {
public:
    int arrangeCoins(int n) {
        int val = 1;
        int count = 0;
        while(n){
            if(n < val ) return count;
            n -=val;
            val+=1;
            count++;
        }
        return count;
    }
};