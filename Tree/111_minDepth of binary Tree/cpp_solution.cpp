// min depth of a binary tree
// define a tree
#include<iostream>
using namespace std;
struct Treenode {
    int val;
    Treenode* left;
    Treenode* right;
    Treenode() : val(0), left(nullptr), right(nullptr) {}
    Treenode(int x) : val(x), left(nullptr), right(nullptr) {}
    Treenode(int x, Treenode* l, Treenode* r) : val(x), left(l), right(r) {}
};
class Solution {
    public:
    int dfsDepth(Treenode* root) {
        if (root == nullptr) {
            return 0;
        }
        int l = dfsDepth(root->left);
        int r = dfsDepth(root->right);
        return l && r ? min(l, r) + 1 : max(l, r) + 1;
    }
    int minDepth(Treenode* root) {
        return dfsDepth(root);
    }
};
// for view
class preOrder {
    public:
    void preOut(Treenode* root) {
        if(!root) {
            return;
        }
        preOut(root->left);
        cout<< root->val << endl;
        preOut(root->right);
    }
};
int main() {
    cout << "hello " << endl;
    Treenode* l = new Treenode(9);
    Treenode* rr = new Treenode(7);
    Treenode* rl = new Treenode(15);
    Treenode* r = new Treenode(20);
    r->left = rl;
    r->right = rr;

    Treenode* root = new Treenode(3);
    root->left = l;
    root->right = r;
    preOrder p;
    p.preOut(root);
    cout << "pre out end " << endl;
    Solution s;
    cout << s.minDepth(root) << endl;
    
    return 0;
}
