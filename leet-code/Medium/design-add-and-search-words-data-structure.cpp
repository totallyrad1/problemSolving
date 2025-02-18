struct Node {
    map<char, Node*> links;
    int endOf;
    Node()
    {
        endOf = 0;
    }
};

class WordDictionary {
public:
    Node *root;

    WordDictionary() {
        root = new Node();    
    }
    void addWord(string word) {
        Node *tmp = root;
        int i = 0;
        Node *newNode;
        while(word[i]){
            if(tmp->links.find(word[i]) == tmp->links.end()){
                newNode = new Node();
                tmp->links.insert({word[i], newNode});
            }
            else
                newNode = tmp->links[word[i]];
            tmp = newNode;
            i++;
        }
        newNode->endOf = 1;
    }
    bool dfs(string &word, Node*tmp, int index){
        if(index == word.size())
            return tmp->endOf;;
        char ch = word[index];
        if(ch == '.'){
            for(auto &[key,value] :tmp->links){
                if(dfs(word, value, index + 1))
                    return true;
            }
            return false;
        }else{
            if (tmp->links.count(ch) == 0) {
                return false;
            }
            return dfs(word, tmp->links[ch], index + 1);
        }
    }
    bool search(string word) {
        return (dfs(word,root, 0));
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */