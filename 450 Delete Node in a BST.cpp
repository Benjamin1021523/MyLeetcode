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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)
            return NULL;
        if(!root->left && !root->right){//leaf
            if(root->val == key)
                return NULL;
            else
                return root;
        }
        if(key < root->val){//往左找
            root->left = deleteNode(root->left, key);
        }
        else if(key > root->val){//往右找
            root->right = deleteNode(root->right, key);
        }
        else{//就是這個
            if(root->left){
                leftBig(root, root, root->left);
            }
            else{
                rightSmall(root, root, root->right);
            }
        }
        return root;
    }
    void rightSmall(TreeNode* del, TreeNode* fa, TreeNode* root){
        if(root->left){
            rightSmall(del, root, root->left);
        }
        else{
            del->val = root->val;
            if(fa == del)
                fa->right = root->right;
            else
                fa->left = root->right;
        }
    }
    void leftBig(TreeNode* del, TreeNode* fa, TreeNode* root){
        if(root->right){
            leftBig(del, root, root->right);
        }
        else{
            del->val = root->val;
            if(fa == del)
                fa->left = root->left;
            else
                fa->right = root->left;
        }
    }
};