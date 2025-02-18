/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        vector<ListNode*> ans;
        while(head){
            ans.push_back(head);
            head = head->next;
        } 
        if(ans.empty())
            return ;
        ListNode* tmp = ans[0];
        int size;
        int lastelem = ans.size()- 1;
        while(lastelem > ans.size() /2){
            ans[lastelem]->next = tmp->next;
            ans[lastelem - 1]->next = NULL;
            tmp->next = ans[lastelem];
            tmp = ans[lastelem]->next;
            lastelem--;
        }
    }
};