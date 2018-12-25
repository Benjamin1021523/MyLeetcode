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
    int sumNumbers(TreeNode* root, int total = 0) {
        if(!root)
            return 0;
        if(!root->left && !root->right)
            return total * 10 + root->val;
        total = total * 10 + root->val;
        return sumNumbers(root->left, total) + 
               sumNumbers(root->right, total);
    }
};