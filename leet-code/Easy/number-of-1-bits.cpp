class Solution {
public:
    int hammingWeight(int n) {
        int count = 0;
        while(n){
            int bit = n % 2;
            count+= bit;
            n /= 2;
        }
        return count;
    }
};