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
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        if(pre.size() == 0)
            return NULL;
        if(pre.size() == 1)
            return new TreeNode(pre[0]);
        if(pre.size() == 2){
            if(pre[1] == in[1]){
                auto re = new TreeNode(pre[0]);
                re->right = new TreeNode(pre[1]);
                return re;
            }
            else{
                auto re = new TreeNode(pre[0]);
                re->left = new TreeNode(pre[1]);
                return re;
            }
        }
        auto re = new TreeNode(pre[0]);
        int i = 0;
        while(in[i] != pre[0] && ++i){}
        vector<int> prel(pre.begin()+1, pre.begin()+i+1);
        vector<int> inl(in.begin(), in.begin()+i);
        re->left = buildTree(prel, inl);
        vector<int> prer(pre.begin()+i+1, pre.end());
        vector<int> inr(in.begin()+i+1, in.end());
        re->right = buildTree(prer, inr);
        return re;
    }
};