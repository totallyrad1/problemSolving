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
    int res;
    void traverseTree(TreeNode* node){
        if(!node) return ;
        res++;
        traverseTree(node->right);
        traverseTree(node->left);
    }
    int countNodes(TreeNode* root) {
        res = 0;
        traverseTree(root);
        return res;
    }
};