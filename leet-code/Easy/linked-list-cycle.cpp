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
    bool hasCycle(ListNode *head) {
        map<ListNode *, int> addresses;
        while(head){
            if(head->next){
                if(addresses.count(head) > 0)
                    return true;
                addresses.insert({head, 0});
            }
            head = head->next;
        }
        return false;
    }
};