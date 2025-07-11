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
    int sum = 0;
    void treverse(TreeNode *node){
        // if(!node) return;
        if(node->left){
            if(node->left->left == NULL && node->left->right == NULL)
                sum += node->left->val;
            // if(node->left->left == NULL)
            treverse(node->left);
        }
        if(node->right){
            treverse(node->right);
        }
    }
    int sumOfLeftLeaves(TreeNode* root) {
        treverse(root);
        return sum;
    }   
};