class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() == 1)
            return 0;
        int left = 0;
        int right = height.size() - 1;
        int rightMax = 0;
        int leftMax = 0;
        int ans = 0;
        while(left < right){
            if(height[left] < height[right]){
                if(height[left] > leftMax){
                    leftMax = height[left];
                }else{
                    ans += leftMax - height[left];
                }
                left++;
            }else{
                if(height[right] > rightMax){
                    rightMax = height[right];
                }else{
                    ans += rightMax - height[right];
                }
                right--;
            }
        }
        return ans;
    }
};