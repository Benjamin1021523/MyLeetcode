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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.empty())
            return NULL;
        if(nums.size() == 1)
            return new TreeNode(nums[0]);
        if(nums.size() == 2){
            auto re = new TreeNode(nums[0]);
            re->right = new TreeNode(nums[1]);
            return re;
        }
        if(nums.size() == 3){
            auto re = new TreeNode(nums[1]);
            re->left = new TreeNode(nums[0]);
            re->right = new TreeNode(nums[2]);
            return re;
        }
        auto re = new TreeNode(nums[nums.size() / 2]);
        vector<int> n1(nums.begin(), nums.begin()+(nums.size() / 2));
        vector<int> n2(nums.begin()+(nums.size() / 2)+1, nums.end());
        re->left = sortedArrayToBST(n1);
        re->right = sortedArrayToBST(n2);
        return re;
    }
};