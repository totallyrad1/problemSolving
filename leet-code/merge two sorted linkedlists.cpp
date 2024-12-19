#include <iostream>
// Definition for singly-linked list. //NOT FULLY SOLVED YET I STILL NEED TO IMPOVE IT
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1)
            return list2;
        if(!list2)
            return list1;
        if(list1->val <= list2->val){
            ListNode* tmp = list1;
            ListNode* save;
            ListNode* tmp1 = list2;
            ListNode* list2save;
            ListNode* lhrba;
            while(tmp){
                save = tmp;
                tmp = tmp->next;
                if(tmp && tmp1 && tmp1->val <= tmp->val){
                    lhrba = save->next;
                    save->next = tmp1;
                    list2save = tmp1->next;
                    tmp1->next = lhrba;
                    tmp1 = list2save;
                }else{
                    save->next = tmp1;
                    tmp1->next = NULL; 
                }
            }
            return list1;
        }else{
            ListNode* tmp = list2;
            ListNode* save;
            ListNode* tmp1 = list1;
            ListNode* list2save;
            ListNode* lhrba;
            while(tmp){
                save = tmp;
                tmp = tmp->next;
                if(tmp && tmp1 && tmp1->val <= tmp->val){
                    lhrba = save->next;
                    save->next = tmp1;
                    list2save = tmp1->next;
                    tmp1->next = lhrba;
                    tmp1 = list2save;
                }else{
                    save->next = tmp1;
                    tmp1->next = NULL; 
                }
            }
            return list2;
        }
        return (NULL);
    }
};

int main(){
    Solution sol;
    ListNode* node = new ListNode(-9, nullptr);
    ListNode* node1 = new ListNode(3, nullptr);
    // ListNode* node2 = new ListNode(3, nullptr);
    ListNode* snode = new ListNode(5, nullptr);
    // ListNode* snode1 = new ListNode(7, nullptr);
    // ListNode* snode2 = new ListNode(3, nullptr);

    node->next = node1;
    // node1->next = node2;
    // snode->next = snode1;
    // snode1->next = snode2;
    ListNode* res = sol.mergeTwoLists(node, snode);
    while(res){
        std::cout << res->val << std::endl;
        res = res->next;
    }

}