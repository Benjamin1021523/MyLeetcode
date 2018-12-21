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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return f(nums, 0, nums.size());
    }
    TreeNode* f(vector<int>& nums, int st, int en){
        if(st == en)
            return NULL;
        if(st == en-1)
            return new TreeNode(nums[st]);

        int d = st;
        for(int i = st;i < en;++i){
            if(nums[d] < nums[i])
                d = i;
        }
        TreeNode* re = new TreeNode(nums[d]);
        re->left = f(nums, st, d);
        re->right = f(nums, d+1, en);
        return re;
    }
};