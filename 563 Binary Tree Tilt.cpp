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
    int findTilt(TreeNode* root) {
        if(!root)
            return 0;
        diff(root->left, root->right);
        return cnt;
    }
private:
    int diff(TreeNode* l, TreeNode* r){
        if(!l && !r)
            return 0;
        if(!l){
            r->val += diff(r->left, r->right);
            cnt += abs(r->val);
            return r->val;
        }
        if(!r){
            l->val += diff(l->left, l->right);
            cnt += abs(l->val);
            return l->val;
        }
        else{
            l->val += diff(l->left, l->right);
            r->val += diff(r->left, r->right);
            cnt += abs(l->val - r->val);
            return l->val + r->val;
        }
    }
    int cnt = 0;
};