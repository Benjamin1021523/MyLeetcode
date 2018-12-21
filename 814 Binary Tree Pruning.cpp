/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(root && !visit(root))
            return NULL;
        return root;
    }
    bool visit(TreeNode* root){
        if(!root->left && !root->right){
            return root->val;
        }
        if(root->left && !visit(root->left))
            root->left = NULL;
        if(root->right && !visit(root->right))
            root->right = NULL;

        return root->left || root->right || root->val;
    }
};