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
    bool isValidBST(TreeNode* root) {
        return f(root, (long long)INT_MIN - 1, (long long)INT_MAX + 1);
    }
    bool f(TreeNode* now, long long l, long long r){
        if(!now)    return true;
        if(now->val <= l || now->val >= r)//不可碰觸
            return false;
        return f(now->left, l, now->val) && 
               f(now->right, now->val, r);
    }
};
//另外還試了「從左到右取值，兩兩比大小」的方式，耗時一樣
//原本以為不傳值，不使用long long會比較快