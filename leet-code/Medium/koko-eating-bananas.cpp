class Solution {
public:
    bool  checkEatingSpeed(vector<int>& piles, int h, int speed){
        int hoursSpent = 0;
        for(auto &num:piles){
            int div = num / speed;
            hoursSpent += div;
            if(num % speed != 0) hoursSpent++;
            if(hoursSpent > h) break;
        }
        return hoursSpent <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = 1000000000;
        while(left <= right){
            int mid = (right + left) / 2;
            if(checkEatingSpeed(piles, h, mid)) right = mid - 1;
            else left = mid + 1;
        }
        return left;
    }
};

