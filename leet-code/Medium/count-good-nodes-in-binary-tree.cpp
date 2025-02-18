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
    int ans = 0;
    void bruteforce(int val,TreeNode* root){
        if(!root)
            return ;
        if(val <= root->val){
            ans++;
            val = root->val;
        }
        bruteforce(val, root->right);
        bruteforce(val, root->left);
    }
    int goodNodes(TreeNode* root) {
        if(!root)
            return 1;
        bruteforce(root->val, root);
        return ans;
    }
};