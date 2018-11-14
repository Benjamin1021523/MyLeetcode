class Solution {
public:
    int countNodes(TreeNode* root) {
        if(!root)
            return 0;

        int hl = 0, hr = 0;
        TreeNode *l=root, *r=root;
        while(l && ++hl)
            l = l->left;
        while(r && ++hr)
            r = r->right;

        if(hl == hr)//本節點可成為三角型頂點
            return pow(2,hl)-1;
        //不行就往下找較小的三角型，輸入已確定是完全樹
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};