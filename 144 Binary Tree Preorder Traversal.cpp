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
    vector<int> preorderTraversal(TreeNode* root) {
        f(root);
        return re;
    }
    void f(TreeNode* now){
        if(!now)    return;
        re.push_back(now->val);
        f(now->left);
        f(now->right);
    }
    vector<int> re;
};