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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head)
            return NULL;
        std::set<int> mySet;
        while(head)
        {
            mySet.insert(head->val);
            head = head->next;
        }
        ListNode *res = NULL;
        ListNode *tmp = NULL;
        for(std::set<int>::iterator it = mySet.begin(); it != mySet.end(); ++it){
            if(it == mySet.begin()){
                res = new ListNode(*it, nullptr);
                tmp = res;
            }else{
                tmp->next= new ListNode(*it, nullptr);
                tmp = tmp->next;
            }
        }
        return res;
    }
};