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
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        deepest = 0;
        deep(root, 0);
        if(!tar)
            return root;
        return tar;
    }
private:
    TreeNode* tar;
    int deepest;
    void deep(TreeNode* root, int depth){
        if(root->left || root->right){
            if(depth > deepest){
                deepest = depth;
                tar = root;
            }
        }
        if(root->left){
            deep(root->left, depth+1);
        }
        if(root->right){
            deep(root->right, depth+1);
        }
    }
};