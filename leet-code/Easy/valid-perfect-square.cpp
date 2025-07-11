class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 0;
        while( i <= num && i < 46341){
            if(i * i == num ) return true;
            i++;
        }

        return false;
    }
};