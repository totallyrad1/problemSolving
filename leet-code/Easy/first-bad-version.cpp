// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int i = 0;
        while(isBadVersion(n)){
            n--;
        }
        return n + 1;
    }
};