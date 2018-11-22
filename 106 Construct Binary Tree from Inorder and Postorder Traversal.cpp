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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.empty())
            return NULL;
        TreeNode* re = new TreeNode(postorder[postorder.size()-1]);
        if(inorder.size() == 1)
            return re;

        int i = 0;
        for(;i < inorder.size() && inorder[i] != re->val;++i){}
        vector<int> inl(inorder.begin(), inorder.begin()+i);
        vector<int> pol(postorder.begin(), postorder.begin()+i);
        vector<int> inr(inorder.begin()+i+1, inorder.end());
        vector<int> por(postorder.begin()+i, postorder.end()-1);

        re->left = buildTree(inl, pol);
        re->right = buildTree(inr, por);
        return re;
    }
};