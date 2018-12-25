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
    int maxPathSum(TreeNode* root) {
        if(!root)   return 0;
        f(root);
        return re;
    }
    int f(TreeNode* now){
        if(!now)    return 0;
        if(!now->left && !now->right){
            re = max(re, now->val);
            return max(0, now->val);
        }
        int l = f(now->left), r = f(now->right);
        re = max(re, now->val + l + r);
        return max(0, now->val + max(l, r));
    }
    int re = INT_MIN;
};