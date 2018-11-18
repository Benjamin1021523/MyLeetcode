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
    TreeNode* increasingBST(TreeNode* root) {
        if(!root || (!root->left && !root->right))
            return root;
        f(root);
        data.push_back(NULL);
        for(int i = 0;i < data.size()-1;++i){
            data[i]->left = NULL;
            data[i]->right = data[i+1];
        }
        return data[0];
    }
private:
    void f(TreeNode* now){
        if(now){
            f(now->left);
            data.push_back(now);
            f(now->right);
        }
    }
    vector<TreeNode*> data;
};