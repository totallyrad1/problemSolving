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
    int height(TreeNode* node){
        if(!node)   return 0;
        int ldp = height(node->left);
        if(ldp == -1)   return -1;

        int rdp = height(node->right);
        if(rdp == -1)    return -1;

        if(abs(ldp - rdp) > 1)     return -1;

        return max(ldp, rdp) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};