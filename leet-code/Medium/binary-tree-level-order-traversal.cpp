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
    vector<vector<int>> ans;
    void deeee(TreeNode* root, int depth){
        if(!root)
            return;
        if(root->left || root->right && ans.size() < depth + 1)
            ans.push_back({});
        vector<int> ts;
        if(root->left)
            ans[depth].push_back(root->left->val);
        if(root->right)
            ans[depth].push_back(root->right->val);
        deeee(root->left, depth+1);
        deeee(root->right,depth+1);
    } 
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)
            return {};
        ans.push_back({root->val});
        deeee(root, 1);
        // while(ans[ans.size() -1].empty())
        //     ans.pop_back();
        return ans;
    }
};