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
    int minCameraCover(TreeNode* root) {
        TreeNode* head = new TreeNode(0);
        head->left = root;
        visit(root, head);
        if(root->val == 0)
            ++cnt;
        return cnt;
    }
    void visit(TreeNode* now, TreeNode* fa){
        if(!now)    return;
        visit(now->left, now);
        visit(now->right, now);
        if(!now->left && !now->right)   return;
        if((now->left && now->left->val == 0) || 
           (now->right && now->right->val == 0)){
            ++cnt;
            fa->val = 1;
            now->val = 1;
        }
    }
    int cnt = 0;
};