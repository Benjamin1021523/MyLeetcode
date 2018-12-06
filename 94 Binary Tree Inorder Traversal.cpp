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
    vector<int> inorderTraversal(TreeNode* root) {
        p(root);
        return re;
    }
private:
    void p(TreeNode* now){
        if(now){
            p(now->left);
            re.push_back(now->val);
            p(now->right);
        }
    }
    vector<int> re;
};