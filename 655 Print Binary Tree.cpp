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
    vector<vector<string>> printTree(TreeNode* root) {
        int deep = visit(root);
        re.assign(deep, vector<string>((1 << deep) - 1, ""));
        write(root, 0, re[0].size()/2, (1 << re.size()) >> 2);
        return re;
    }
private:
    int visit(TreeNode* now){
        if(!now)
            return 0;
        return max(visit(now->left), visit(now->right)) + 1;
    }
    void write(TreeNode* now, int x, int y, int c){
        if(!now)    return;
        stringstream s;
        s << now->val;
        s >> re[x][y];
        write(now->left, x+1, y - c, c >> 1);
        write(now->right, x+1, y + c, c >> 1);
    }
    vector<vector<string>> re;
};