/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        set<ListNode *> seen;
        while(headA || headB){
            if(headA){
                if(seen.count(headA) > 0) return headA;
                seen.insert(headA);
                headA = headA->next;
            }
            if(headB){
                if(seen.count(headB) > 0) return headB;
                seen.insert(headB);
                headB = headB->next;
            }
        }
        return NULL;
    }
};