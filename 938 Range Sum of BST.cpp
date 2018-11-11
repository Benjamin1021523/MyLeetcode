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
    int rangeSumBST(TreeNode* root, int L, int R) {
        l_range = L;
        r_range = R;
        total = 0;
        visit(root);
        return total;
    }
private:
    void visit(TreeNode* root){
        if(!root){
        }
        else if(root->val > r_range){
            visit(root->left);
        }
        else if(root->val < l_range){
            visit(root->right);
        }
        else if(root->val == r_range){
            total += root->val;
            visit(root->left);
        }
        else if(root->val == l_range){
            total += root->val;
            visit(root->right);
        }
        else{
            total += root->val;
            visit(root->left);
            visit(root->right);
        }
    }
    int l_range, r_range, total;
};