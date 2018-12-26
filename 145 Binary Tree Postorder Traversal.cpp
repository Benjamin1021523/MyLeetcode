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
    vector<int> postorderTraversal(TreeNode* root) {
        f(root);
        return re;
    }
    void f(TreeNode* now){
        if(!now)    return;
        f(now->left);
        f(now->right);
        re.push_back(now->val);
        /*re.insert(re.begin(), now->val);
        f(now->right);//runtime一樣
        f(now->left);*/
    }
    vector<int> re;
};