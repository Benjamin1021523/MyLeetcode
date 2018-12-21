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
    int widthOfBinaryTree(TreeNode* root) {
        if(root)
            f(root, 0, 1);
        int re = 0;
        for(auto& i:data){
            re = max(re, i[i.size()-1]-i[0]+1);
        }
        return re;
    }
    void f(TreeNode* now, int depth, int path){
        if(depth == data.size())
            data.push_back({path ^ (1 << depth)});
        else
            data[depth].push_back(path ^ (1 << depth));
        if(now->left)
            f(now->left, depth+1, path*2);
        if(now->right)
            f(now->right, depth+1, path*2+1);
    }
    vector<vector<int>> data;
};