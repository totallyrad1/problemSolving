struct Node {
    map<char , Node*> links;
    int endOf;
    Node(){
        endOf = 0;
    }
};
class Solution {
public:
    int width;
    int height;
    const vector<pair<int, int>> Directions = {{0, -1}, {0, 1}, {1 , 0}, {-1, 0}};
    int Bound(int x,int y){
        if(x < 0 || y < 0 || x >= width || y >= height)
            return 0;
        return 1;
    }
    void constructTrie(string &word, Node* head){
        for(auto &ch : word){
            Node *newNode = new Node();
            head->links.insert({ch, newNode});
            head = newNode;
        }
        head->endOf = 1;
    }
    bool dfs(int x,int y, Node* head, vector<vector<char>>& board, string path = ""){
        if(!Bound(x, y))
            return false;
        char ch = board[y][x];
        if(head->links.find(ch) == head->links.end()) return false;
        path.push_back(ch);
        head = head->links[ch];
        if(head->endOf)
            return true;
        char temp = board[y][x];
        board[y][x] = '#';
        for(auto &dir:Directions){
            if(dfs(x + dir.first, y + dir.second,head, board, path))
                return true;
        }
        board[y][x] = temp;
        path.pop_back();
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        if(board.empty())
            return false;
        width = board[0].size();
        height = board.size();
        Node *head = new Node();
        constructTrie(word, head);
        for(int y = 0; y < height; y++){
            for(int x = 0; x < width; x++){
                if(dfs(x, y,head, board))
                    return true;
            }
        }
        return false;
    }
};