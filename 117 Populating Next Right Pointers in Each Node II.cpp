/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root, int deep = 0) {
        if(!root)   return;
        if(deep == v.size())
            v.push_back(NULL);

        root->next = v[deep];
        v[deep] = root;
        if(root->right)
            connect(root->right, deep+1);
        if(root->left)
            connect(root->left, deep+1);
    }
    vector<TreeLinkNode*> v;
};
//使用116的方法完全可以呢... 因為那時沒管均衡樹的條件吧