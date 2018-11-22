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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        deep(root);
        return re;
    }
private:
    int deep(TreeNode* root, int now = 0){
        if(!root)
            return 0;
        if(re.size() == now)
            re.insert(re.begin(), vector<int>(1, root->val));
        else
            re[re.size()-now-1].push_back(root->val);
        deep(root->left, now+1);
        deep(root->right, now+1);
        return 0;
    }
    vector<vector<int>> re;
};