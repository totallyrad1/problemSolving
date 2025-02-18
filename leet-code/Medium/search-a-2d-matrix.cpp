class Solution {
public:
    int getValue(vector<vector<int>>& matrix, int index){
        int i = index / matrix[0].size();
        int j = index % matrix[0].size();

        return matrix[i][j];
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty())
            return false;
        int right = (matrix.size() * matrix[0].size()) - 1;
        int left = 0;
        while(left <= right){
            int median = (right + left) / 2;
            int value = getValue(matrix, median);
            if(value == target)
                return true;
            if(value > target)
                right = median - 1;
            else if(value < target)
                left = median + 1;
        }
        return false;
    }
};