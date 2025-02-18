class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        ListNode* root;
        ListNode* merged = NULL;
        if(list1->val < list2->val){
            merged = new ListNode(*list1);
            list1 = list1->next;
        }else{
            merged = new ListNode(*list2);
            list2 = list2->next;
        }
        root = merged;
        while(list1 || list2){
            if(list1 && list2){
                if(list1->val > list2->val){
                    merged->next = new ListNode(*list2);
                    list2 = list2->next;
                }else{
                    merged->next = new ListNode(*list1);
                    list1 = list1->next;
                }
            }else if(list1){
                merged->next = new ListNode(*list1);
                list1 = list1->next;
            }else if(list2){
                merged->next = new ListNode(*list2);
                list2 = list2->next;
            }
            merged = merged->next;
        }
        return root;
    }
};