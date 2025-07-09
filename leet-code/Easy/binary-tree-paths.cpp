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
    vector<string> res;
    void traverseTree(TreeNode* node, string temp){
        temp += to_string(node->val);
        if(node->left) traverseTree(node->left, temp + "->");
        if(node->right) traverseTree(node->right, temp + "->");
        if(!node->left && !node->right) res.push_back(temp);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root) traverseTree(root, "");
        return res;
    }
};