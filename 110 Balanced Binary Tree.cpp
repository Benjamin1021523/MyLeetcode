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
    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        return !(abs(deep(root->left) - deep(root->right)) > 1) && 
                isBalanced(root->left) && 
                isBalanced(root->right);
    }
private:
    int deep(TreeNode* root, int now = 0){
        if(!root)
            return now;
        return max(deep(root->left, now+1), deep(root->right, now+1));
    }
};