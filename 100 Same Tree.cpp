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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return equal(p, q);
    }
private:
    bool equal(TreeNode* p, TreeNode* q){
        if(!p & !q)
            return true;
        if(!p ^ !q)
            return false;
        if(p->val == q->val){
            return equal(p->left, q->left) & 
                equal(p->right, q->right);
        }
        else{
            return false;
        }
    }
};