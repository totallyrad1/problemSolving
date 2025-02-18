struct Node{
    map<char, Node *> links;
    int endOf;
    Node(){
        this->endOf = 0;
    }
};

class Solution {
public:
    int height;
    int width;
    int wdsize;
    set<string> wordsFound;
    int Bounds(int x, int y){
        if(x < 0 || x >= width || y < 0 || y >= height){
            return 0;
        }
        return 1;
    }
    void addToTrie(string &word,Node *head){
        for(auto &ch:word){
            if(head->links.find(ch) != head->links.end()){
                head = head->links[ch];
            }else{
                Node *newNode = new Node();
                head->links.insert({ch, newNode});
                head = newNode;
            }
        }
        head->endOf = 1;
    }
    void bfs(string path, Node* head, int x,int y, vector<vector<char>>& board){
        if(wordsFound.size() == wdsize)
            return ;
        if(!Bounds(x, y)) return ;

        char ch = board[y][x];
        if(head->links.find(ch) == head->links.end()) return ;
        path.push_back(ch);
        head = head->links[ch];
        if(head->endOf){
            head->endOf = 0;
            wordsFound.insert(path);
        }
        char temp = board[y][x];
        board[y][x] = '#';
        const vector<pair<int, int>> Directions = {{0, -1}, {0, 1}, {1 , 0}, {-1, 0}};
        for(auto &dir:Directions){
            bfs(path, head, x + dir.first, y + dir.second, board);
        }
        board[y][x] = temp;
        path.pop_back();
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.empty())
            return {};
        wdsize = words.size();
        height = board.size();
        width = board[0].size();
        Node *head= new Node();
        for(auto &word: words)
            addToTrie(word, head);
        for(int y = 0; y < height; y++){
            for(int x = 0; x < width; x++){
                bfs("",head, x, y, board);
            }
        }
        return vector<string>(wordsFound.begin(), wordsFound.end());
    }
};