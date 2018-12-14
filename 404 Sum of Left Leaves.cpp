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
    int sumOfLeftLeaves(TreeNode* root, bool isleft = false) {
        if(!root)
            return 0;
        if(!root->left && !root->right){
            if(isleft)
                return root->val;
            else
                return 0;
        }
        return sumOfLeftLeaves(root->left, true) + sumOfLeftLeaves(root->right, false);
    }
};