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
    vector<int> res;
    void constructRes(TreeNode* node){
        if(!node) return ;
        res.push_back(node->val);
        constructRes(node->right);
        constructRes(node->left);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        constructRes(root);
        reverse(res.begin(), res.end());
        return res;
    }
};