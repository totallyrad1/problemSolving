class Solution {
public:
    vector<vector<int>> dp;
    int width;
    int height;
    int checkBounds(int x, int y){
        if(x >= width || y >= height)
            return 0;
        return 1;
    }
    int rec(int x, int y){
        if(x == width -1 && y == height -1)
            return 1;
        if(dp[y][x] != -1)
            return dp[y][x];
        dp[y][x] = 0;
        int &res = dp[y][x];
        if(checkBounds(x + 1, y)){ //RIGHT
            res += rec(x + 1, y);
        }
        if(checkBounds(x, y + 1)){ // DOWN
            res += rec(x, y + 1);
        }
        return res;
    }
    int uniquePaths(int m, int n) {
        this->width = n;
        this->height = m;
        dp = vector<vector<int>>(m, vector<int>(n, -1));
        return rec(0, 0);
    }
};