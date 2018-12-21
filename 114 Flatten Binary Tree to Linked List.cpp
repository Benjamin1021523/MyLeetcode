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
    void flatten(TreeNode* root) {
        visit(root);
    }
    void visit(TreeNode* now){
        if(!now || (!now->left && !now->right))
            return;
        if(!now->right){
            now->right = now->left;
            now->left = NULL;//忘了打所以double free
            visit(now->right);
            return;
        }
        if(!now->left){
            visit(now->right);
            return;
        }
        auto lt = now->left;
        auto rt = now->right;
        visit(lt);
        visit(rt);
        now->right = now->left;
        now->left = NULL;
        while(lt->right){
            lt = lt->right;
        }
        lt->right = rt;
    }
};
/**
如果解pointer類的題目出現double free的錯誤，通常是因為有兩指標指到同個位址
int* a = new int(5);
int* b = a;
...
delete a;
delete b;//double free
*/