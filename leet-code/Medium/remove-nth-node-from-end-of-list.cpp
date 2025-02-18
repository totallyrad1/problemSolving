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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return NULL;
        vector<ListNode*> ans;
        ListNode* tmp = head;
        while(tmp){
            ans.push_back(tmp);
            tmp = tmp->next;
        }

        int elem = ans.size() - n;
        if(elem == 0)
            return head->next;
        if(elem == ans.size() -1){
            ans[elem -1]->next = NULL;
            return head;
        }
        ans[elem - 1]->next = ans[elem + 1];
        return head;
    }
};