/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//https://leetcode.com/contest/weekly-contest-92/ranking/
//第八名facelessvoid的方法
class Solution {
    pair<int, TreeNode *> solve(TreeNode *root){
        if(root == NULL)
            return {0, NULL};
        auto left = solve(root->left);
        auto right = solve(root->right);
        if(left.first == right.first)
            return {left.first + 1, root};
        else if(left.first > right.first)
            return {left.first + 1, left.second};
        else
            return {right.first + 1, right.second};
        //回傳在這個節點之下，最接近根部，能左右子樹深度相同的母節點
    }
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root).second;
    }
};