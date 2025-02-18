class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<char>> treextrees(9);
        for(int i = 0; i< board.size(); i++){
            set<char> lhrba;
            for(int j = 0; j <board[i].size() ; j++){
                if(board[i][j] == '.')
                    continue;
                int subBoxIndex = (i / 3) * 3 + (j / 3);
                treextrees[subBoxIndex].push_back(board[i][j]);
                if(lhrba.count(board[i][j]) > 0)
                    return false;
                lhrba.insert(board[i][j]);
            }
        }
        for(int i = 0; i< board.size(); i++){
            set<char> lhrba;
            for(int j = 0; j <board[i].size() ; j++){
                if(board[j][i] == '.')
                    continue;
                if(lhrba.count(board[j][i]) > 0)
                    return false;
                lhrba.insert(board[j][i]);
            }
        }
        for(auto &t: treextrees){
            set<char> lhrba;
            for(auto &s : t){
                if(lhrba.count(s) > 0)
                    return false;
                lhrba.insert(s);
            }
        }
        return true;
    }
};