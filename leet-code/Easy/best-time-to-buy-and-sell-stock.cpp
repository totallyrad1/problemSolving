class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2)
            return 0;
        int left = 0;
        int right = 1;
        int val = prices[right] - prices[left];
        while(right < prices.size()){
            if(prices[right] < prices[left])
                left = right;
            else{
                if(prices[right] - prices[left] >= val)
                {
                    val = prices[right] - prices[left];
                }
            }
            right++;
        }
        if(val < 0)
            val = 0;
        return val;
    }
};