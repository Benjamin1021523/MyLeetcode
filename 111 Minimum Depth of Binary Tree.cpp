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
    int minDepth(TreeNode* root) {
        if(!root)
            return 0;
        return f(root, 1);
    }
    int f(TreeNode* root, int now){
        if(isLeaf(root))
            return now;
        if(!root->left)
            return f(root->right, now+1);
        else if(!root->right)
            return f(root->left, now+1);
        else
            return min(f(root->left, now+1), f(root->right, now+1));
    }
    inline bool isLeaf(TreeNode* n){
        return !n->left && !n->right;
    }
};