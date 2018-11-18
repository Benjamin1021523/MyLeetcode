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
    vector<int> postorder(Node* root) {
        if(!root)
            return {};

        vector<Node*> x = f(root);
        vector<int> re(x.size(), 0);
        for(int i = 0;i < x.size();++i)
            re[i] = x[i]->val;
        re.push_back(root->val);
        return re;
    }
private:
    vector<Node*> f(Node* now){
        if(!now)
            return {};
        for(int i = now->children.size()-1;i >= 0;--i){
            vector<Node*> temp = f(now->children[i]);
            now->children.insert(now->children.begin()+i, temp.begin(), temp.end());
        }
        return now->children;
    }
};
/**
class Solution {
public:
    vector<int> postorder(Node* root) {
        if(!root)
            return {};
        f(root);
        return re;
    }
private:
    void f(Node* now){
        for(auto& i:now->children){
            f(i);
        }
        re.push_back(now->val);
    }
    vector<int> re;
};
*/