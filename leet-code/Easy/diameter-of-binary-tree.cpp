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
    int ans;
    map<TreeNode *, int> dp;
    void rec(TreeNode*root){
        if(!root)
            return ;
        if(dp.find(root) != dp.end()){
            if(dp[root] > ans)
                ans = dp[root];
            return ;
        }
        int ld = maxDepth(root->left);
        int rd = maxDepth(root->right);
        dp.insert({root, ld + rd});
        if(ld + rd > ans){
            ans = ld + rd;
        }
        rec(root->right);
        rec(root->left);
    }
    int maxDepth(TreeNode* root) {
        if(!root)
            return 0;
        int ldepth = 1;
        int rdepth = 1;
        rdepth += maxDepth(root->right);
        ldepth += maxDepth(root->left);
        if(ldepth > rdepth)
            return ldepth;
        return rdepth; 
    }
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 0;
        rec(root);
        return ans;
    }
};