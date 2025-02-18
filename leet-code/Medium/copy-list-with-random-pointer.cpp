/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* deepCopy(Node *node){
        if(!node)
            return NULL;
        Node *newNode = new Node(node->val);
        return newNode;
    }
    Node* copyRandomList(Node* head) {
        if(!head)
            return NULL;
        map<Node*, Node*> db;
        Node *root = head;
        Node *temp = NULL;
        Node *old = NULL;;
        while(head){
            if(db.find(head) == db.end())
                db.insert({head, deepCopy(head)});
            if(head->random && db.find(head->random) == db.end())
                db.insert({head->random, deepCopy(head->random)});
            if(!old){
                if(head->random)
                    db[head]->random = db[head->random];
            }else{
                db[old]->next = db[head];
                if(head->random)
                    db[old]->next->random = db[head->random];
            }
            old = head;
            head = head->next;
        }
        return db[root];
    }
};