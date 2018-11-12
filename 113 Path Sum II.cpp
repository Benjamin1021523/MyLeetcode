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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        add(root, sum, {});
        return re;
    }
private:
    void add(TreeNode* root, int sum, vector<int> accu){
        if(!root){}
        else{
            accu.push_back(root->val);
            if(sum - root->val == 0 && !root->left && !root->right){
                re.push_back(accu);
            }
            else{
                add(root->left, sum - root->val, accu);
                add(root->right, sum - root->val, accu);
            }
        }
    }
    vector<vector<int>> re;
};