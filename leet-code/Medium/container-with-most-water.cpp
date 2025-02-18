class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = -1;
        int start = 0;
        int end = height.size() -1;
        while(start < end){
            int minim = min(height[start], height[end]);
            int dis = end - start;
            int value = minim * dis;
            if(value > ans){
                ans = value;
            }
            if(height[start] > height[end])
                end--;
            else
                start++;
        }
        return ans;
    }
};