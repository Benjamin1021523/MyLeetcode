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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root)
            write(root, 0);
        return re;
    }
private:
    void write(TreeNode* now, int deep){
        if(!now){}
        else{
            if(re.size() == deep){
                re.push_back({});
            }
            if(deep % 2 == 0)
                re[deep].push_back(now->val);
            else
                re[deep].insert(re[deep].begin(), now->val);
            write(now->left, deep+1);
            write(now->right, deep+1);
        }
    }
    vector<vector<int>> re;
};