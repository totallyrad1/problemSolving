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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* root = new ListNode();
        ListNode* curr = root;
        int remainder = 0;
        while(l1 && l2){
            int value = l1->val + l2->val + remainder;
            curr->next = new ListNode(value% 10);
            remainder = value / 10;
            l1 = l1->next;
            l2 = l2->next;
            curr = curr->next;
        }
        while(l1 || l2){
            if(l1){
                int value = l1->val + remainder;
                remainder = value / 10;
                curr->next = new ListNode(value% 10);
                l1 = l1->next;
            }else if(l2){
                int value = l2->val + remainder;
                remainder = value / 10;
                curr->next = new ListNode(value% 10);
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(remainder)
            curr->next = new ListNode(remainder);
        return root->next;
    }
};