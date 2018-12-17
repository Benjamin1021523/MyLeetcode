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
    bool isCompleteTree(TreeNode* root) {
        f(root);
        return last == s;
    }
private:
    void f(TreeNode* root, int now = 1){
        if(!root)   return;
        ++s;
        last = max(last, now);
        f(root->left, now*2);
        f(root->right, now*2+1);
    }
    int last = 0, s = 0;
};