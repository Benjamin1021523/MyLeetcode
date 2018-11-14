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
    int kthSmallest(TreeNode* root, int k) {
        target = k;
        func(root);
        return v[k-1];
    }
    void func(TreeNode* root){
        if(!root){
        }
        else if(target > v.size()){
            func(root->left);
            v.push_back(root->val);
            func(root->right);
        }
    }
private:
    vector<int> v;
    int target;
};