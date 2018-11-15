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
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root)
            return re;
        visit(root, "");
        return re;
    }
private:
    void visit(TreeNode* now, string path){
        path += "->" + itoa(now->val);
        if(!now->left && !now->right){//leaf
            path.erase(0, 2);
            re.push_back(path);
        }
        else{
            if(now->left)
                visit(now->left, path);
            if(now->right)
                visit(now->right, path);
        }
    }
    string itoa(int x){
        string re = "", sign = "";
        if(x < 0){
            sign = "-";
            x *= -1;
        }
        if(x == 0)
            re = "0";
        while(x){
            re = char(x % 10 + '0') + re;
            x /= 10;
        }
        return sign + re;
    }
    vector<string> re;
};