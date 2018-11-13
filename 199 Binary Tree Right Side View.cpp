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
    vector<int> rightSideView(TreeNode* root) {
        if(root)
            visit(root, 0);
        return re;
    }
private:
    void visit(TreeNode* root, int deep){
        if(re.size() == deep)
            re.push_back(root->val);

        if(root->right)
            visit(root->right, deep+1);
        if(root->left)
                visit(root->left, deep+1);
    }
    vector<int> re;
};