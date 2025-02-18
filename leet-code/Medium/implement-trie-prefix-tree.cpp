struct Node {
    map<char, Node*> links;
    int endOf;
    Node()
    {
        endOf = 0;
    }
};

class Trie {
public:
    Node *root;

    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
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
    
    bool search(string word) {
        Node *tmp = root;
        for(int i = 0; i<= word.size() && tmp; i++){
            if(i == word.size() && tmp->endOf){
                return true;
            }else{
                if(tmp->links.find(word[i]) != tmp->links.end())
                    tmp = tmp->links[word[i]];
                else
                    break;
            }
        }
        return false;
    }
    
    bool startsWith(string prefix) {
        Node *tmp = root;
        int i = 0;
        while(prefix[i]){
            if(tmp->links.find(prefix[i]) != tmp->links.end())
                tmp = tmp->links[prefix[i]];
            else
                break;
            i++;
        }
        if(i == prefix.size())
            return true;
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */