/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
public:
    vector<int> preorder(Node* root) {
        if(!root)
            return {};

        vector<Node*> x = f(root);
        vector<int> re(x.size(), 0);
        for(int i = 0;i < x.size();++i)
            re[i] = x[i]->val;
        re.insert(re.begin(), root->val);
        return re;
    }
private:
    vector<Node*> f(Node* now){
        if(!now)
            return {};
        for(int i = 0;i < now->children.size();++i){
            vector<Node*> temp = f(now->children[i]);
            now->children.insert(now->children.begin()+i+1, temp.begin(), temp.end());
            i += temp.size();
        }
        return now->children;
    }
};