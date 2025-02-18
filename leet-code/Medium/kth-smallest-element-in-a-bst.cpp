/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    set<int> values;
    void getSmallest(TreeNode* root, int depth){
        if(!root)
            return;
        values.insert(root->val);
        getSmallest(root->left, depth + 1);
        getSmallest(root->right, depth + 1);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root)
            return -1;
        getSmallest(root, 1);
        for(auto &l: values){
            if(k == 1)
                return l;
            k--;
        }
        return -1;
    }
};