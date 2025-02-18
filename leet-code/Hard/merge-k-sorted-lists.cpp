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
    int smallestValue(vector<ListNode*>& lists){
        int res = -1;
        for(int i = 0; i < lists.size(); i++){
            if(!lists[i])
                continue;
            if(res == -1 || lists[res]->val > lists[i]->val){
                res = i;
            }
        }
        return res;
    }
    ListNode* deepCopy(ListNode* node){
        ListNode* res = new ListNode(node->val);
        res->next = NULL;
        return res;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = NULL;
        int index;
        ListNode* newList = NULL;
        int finished = 0;
        while(finished < lists.size()){
            index = smallestValue(lists);
            if(index == -1) return ans;
            if(!newList){
                newList = deepCopy(lists[index]);
                ans = newList;
            }else{
                newList->next = deepCopy(lists[index]);
                newList = newList->next;
            }
            lists[index] = lists[index]->next;
            if(lists[index] == NULL)
                finished++;
        }
        return ans;
    }
};